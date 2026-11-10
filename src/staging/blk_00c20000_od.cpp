
// src/staging/blk_00c20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/tls.h"
#include <new>
#include <windows.h>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/ControlGraph.h"
#include "fnv/decl/E70Owner.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0042fb60_shell.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00559a70_Class.h"
#include "fnv/decl/FUN_00a5db30_shell.h"
#include "fnv/decl/FUN_00aa4c60_class.h"
#include "fnv/decl/FUN_00b5af80_self.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00a59e00.h"
#include "fnv/decl/S_00aff060_Class.h"
#include "fnv/decl/SystemFileWriter.h"
#include "fnv/decl/fnv_00c3cea0__FUN_00c3cea0.h"
#include "fnv/decl/fnv_00c41610__FUN_00c41610_cls.h"
#include "fnv/decl/fnv_00c42b80__C42List.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aff000.h"
#include "fnv/symbols_00c33000.h"
#include "fnv/symbols_00c36000.h"
#include "fnv/symbols_00c38000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_00c3c000.h"
#include "fnv/symbols_00c42000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c46000.h"
#include "fnv/symbols_00c4a000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c53000.h"
#include "fnv/symbols_00c54000.h"
#include "fnv/symbols_00c55000.h"
#include "fnv/symbols_00c5c000.h"
#include "fnv/symbols_00c5e000.h"
#include "fnv/symbols_00c5f000.h"
#include "fnv/symbols_00c60000.h"
#include "fnv/symbols_00c61000.h"
#include "fnv/symbols_00c63000.h"
#include "fnv/symbols_00c64000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_010c1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01204000.h"
#include "../../include/layout_support.h"

#include "fnv/decl/NiTPointerListBase.h"
#include <cmath>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/BSShaderLightingProperty.h"
#include "fnv/decl/Container00c3e420.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0044e010_class.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00aa62e0_shell.h"
#include "fnv/decl/FUN_00c3c700_cls.h"
#include "fnv/decl/FUN_00c3e310_shell.h"
#include "fnv/decl/FUN_00c3e340_cls.h"
#include "fnv/decl/FUN_00c3e690_cls.h"
#include "fnv/decl/FUN_00c3e860_t.h"
#include "fnv/decl/FUN_00c41050_Class.h"
#include "fnv/decl/FUN_00c42060_Class.h"
#include "fnv/decl/FUN_00c64780_Class.h"
#include "fnv/decl/GameTimerRecord.h"
#include "fnv/decl/Lock5b.h"
#include "fnv/decl/Map40.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiSourceTexture.h"
#include "fnv/decl/NodeMap.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/RemovalMapState.h"
#include "fnv/decl/S_0045c520.h"
#include "fnv/decl/Sphere.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskProcessor.h"
#include "fnv/decl/TextureFileEntrySetter.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa4000.h"
#include "fnv/symbols_00c3a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01203000.h"
#include "fnv/symbols_01272000.h"
#include <math.h>

struct FUN_00c3a090_Class
{
    char FUN_00c3a090(void* arg);
};

// Calls IsSameAs with arg and returns its result unchanged.
// @fnv 0x00c3a090
char FUN_00c3a090_Class::FUN_00c3a090(void* arg)
{
    char result = ((char)(reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(arg))));
    return result;
}


struct FUN_00c3a610_Class
{
    void* FUN_00c3a610();
};

// @fnv 0x00c3a610
void* FUN_00c3a610_Class::FUN_00c3a610()
{
    return &(*reinterpret_cast<void * *>(&::g_01202828));
}

struct P03MM
{
    void* Allocate(unsigned int);
};

struct FUN_00c3a640_Class
{
    void* FUN_00c3a640(unsigned int size);
};

// Allocates size*4 bytes through g_memoryManager and returns the resulting pointer.
// @fnv 0x00c3a640
void* FUN_00c3a640_Class::FUN_00c3a640(unsigned int size)
{
    void* result = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(size << 2);
    return result;
}

namespace fnv_00c3a670 {
struct MemoryManager
{
    void* Reallocate(void* p, unsigned int size);
};

struct FUN_00c3a670_Class
{
    void* FUN_00c3a670(void* old, unsigned int count);
};

// @fnv 0x00c3a670
void* FUN_00c3a670_Class::FUN_00c3a670(void* apBlock, unsigned int count)
{
    return (*reinterpret_cast<::fnv_00c3a670::MemoryManager *>(&::g_memoryManager)).Reallocate(apBlock, count * 4);
}
}  // namespace fnv_00c3a670


struct FUN_00c3b9e0_Class
{
    void* GetGlobalPointer();
};

// @fnv 0x00c3b9e0
void* FUN_00c3b9e0_Class::GetGlobalPointer()
{
    return &(*reinterpret_cast<void * *>(&::g_012043dc));
}


struct FUN_00c3ba70_Class
{
    void* FUN_00c3ba70();
};

// @fnv 0x00c3ba70
void* FUN_00c3ba70_Class::FUN_00c3ba70()
{
    return &(*reinterpret_cast<void * *>(&::g_012043e4));
}

// @fnv 0x00c3c200
int __cdecl FUN_00c3c200()
{
    int v = 0;
    return v;
}

extern const void* DAT_010c14e8;
extern void __cdecl FUN_00c3d930();

struct FUN_00c3c520_class
{
    const void* vtbl;
    void FUN_00c3c520();
};

// @fnv 0x00c3c520
void FUN_00c3c520_class::FUN_00c3c520()
{
    vtbl = &DAT_010c14e8;
    ((void(*)(void*))FUN_00c3d930)(this);
}

extern int DAT_010c1510;
struct QueuedParents
{
    void FUN_00c3c570();
};
extern int DAT_010c14fc;

struct FUN_00c3d930_Class
{
    void* vftable;
    void FUN_00c3d930();
};
// @fnv 0x00c3c570
void QueuedParents::FUN_00c3c570()
{
    *reinterpret_cast<int**>(this) = &DAT_010c1510;
    reinterpret_cast<::FUN_00c3d930_Class *>(this)->FUN_00c3d930();
}


struct FUN_00c3f6f0_Class
{
    char pad00[0x18];
    long unk18;
    void FUN_00c3f6f0();
};

// @fnv 0x00c3f6f0
void FUN_00c3f6f0_Class::FUN_00c3f6f0()
{
    InterlockedIncrement(&this->unk18);
}

struct FUN_00c3f710_Class
{
    char pad00[0xc];
    long unk0c;
    void IncrementRefCount();
};

// @fnv 0x00c3f710
void FUN_00c3f710_Class::IncrementRefCount()
{
    InterlockedIncrement(&this->unk0c);
}

struct FUN_00c3f730_Class
{
    void DecrementRefCount();
};

// @fnv 0x00c3f730
void FUN_00c3f730_Class::DecrementRefCount()
{
    InterlockedDecrement((volatile long*)(this + 0xc));
}

struct FUN_00c3fc80_class
{
    void CallSecondVirtualMethod(void* p);
};

// @fnv 0x00c3fc80
void FUN_00c3fc80_class::CallSecondVirtualMethod(void* apObject)
{
    ((void(*)(void*))(*reinterpret_cast<void***>(apObject))[1])(apObject);
}

struct FUN_00c35980_Class
{
    char pad00[0xec];
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int FUN_00c35980();
};

// Returns 2 if the fields at offsets 0xec or 0xf4 are set, 1 if 0xf0 or 0xf8 are set, otherwise 0.
// @fnv 0x00c35980
int FUN_00c35980_Class::FUN_00c35980()
{
    if (this->unkec || this->unkf4)
        return 2;
    if (this->unkf0 || this->unkf8)
        return 1;
    return 0;
}

struct FUN_00c3a080_Class
{
    void* FUN_00c3a080(int arg);
};

// @fnv 0x00c3a080
void* FUN_00c3a080_Class::FUN_00c3a080(int arg)
{
    return 0;
}

struct NiTPrimitiveArray_unsigned_int_
{
};
struct FUN_00c3a0c0_Class
{
    void AddFirstEmptyFromGlobal(uintptr_t a);
};
// @fnv 0x00c3a0c0
void FUN_00c3a0c0_Class::AddFirstEmptyFromGlobal(uintptr_t pArray)
{
    struct
    {
        void* p;
        uintptr_t u;
    } locals;
    char pad[12];
    reinterpret_cast<::E70Owner *>(this)->FUN_00c46e70((::StrArr *)(pArray));
    locals.p = (*reinterpret_cast<void * *>(&::g_01202828));
    locals.u = (uintptr_t)((void *)(::FUN_00a7d330((const char *)(locals.p))));
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)pArray)))->FUN_0096a610((intptr_t)&(locals.u));
}

struct FUN_00c3a100_Class
{
    void FUN_00c3a100(int);
};
// @fnv 0x00c3a100
void FUN_00c3a100_Class::FUN_00c3a100(int)
{}

struct FUN_00c3a110_Class
{
    void FUN_00c3a110(int arg);
};

// @fnv 0x00c3a110
void FUN_00c3a110_Class::FUN_00c3a110(int arg)
{}

struct FUN_00c3a120_Class
{
    void FUN_00c3a120(int);
};

// @fnv 0x00c3a120
void FUN_00c3a120_Class::FUN_00c3a120(int)
{}

struct FUN_00c3a130_Class
{
    char FUN_00c3a130(void* arg);
};

// @fnv 0x00c3a130
char FUN_00c3a130_Class::FUN_00c3a130(void* arg)
{
    return 1;
}

struct FUN_00c3a140_Class
{
    void* FUN_00c3a140(unsigned int flags);
    void FUN_00c39770();
};

struct NiUpdateData
{
};
class NiNode
{
  public:
    void UpdateDownwardPass(NiUpdateData&, unsigned int);
};
struct BSMultiBoundNode : NiNode
{
    void FUN_00c3a5b0(NiUpdateData& data, unsigned int flags);
};
// Calls UpdateDownwardPass with data and flags, then invokes the object's virtual method at vtable slot 47 on this.
// @fnv 0x00c3a5b0
void BSMultiBoundNode::FUN_00c3a5b0(NiUpdateData& aUpdateData, unsigned int flags)
{
    UpdateDownwardPass(aUpdateData, flags);
    ((void(*)(void*))(*(void***)this)[47])(this);
}

struct FUN_00c3a620_Class
{
    void FUN_00c3a620();
};
struct MemoryManager
{
    void Deallocate(void*);
};
struct FUN_00c3a6a0_Class
{
    void* FUN_00c3a6a0(unsigned int flags);
};
// @fnv 0x00c3a6a0
void* FUN_00c3a6a0_Class::FUN_00c3a6a0(unsigned int flags)
{
    ((FUN_00c3a620_Class*)this)->FUN_00c3a620();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

// @fnv 0x00c3bb90
void FUN_00c3bb90(const char* src)
{
    strcpy_s(DAT_01202c50, 260, DAT_01202fa0);
    strcat_s(DAT_01202c50, 260, src);
}

namespace fnv_00c3bbe0 {
// @fnv 0x00c3bbe0
void __cdecl FUN_00c3bbe0(const char* pcSuffix)
{
    fnv::crt::strcpy_s((*reinterpret_cast<char (*)[260]>(&::DAT_01202b48)), 260, &(*reinterpret_cast<char *>(&::DAT_01202fa0)));
    fnv::crt::strcat_s((*reinterpret_cast<char (*)[260]>(&::DAT_01202b48)), 260, pcSuffix);
}
}  // namespace fnv_00c3bbe0

extern char DAT_01202a40[0x104];
// Copies DAT_01202fa0 into DAT_01202a40, then appends p to it.
// @fnv 0x00c3bc30
void __cdecl FUN_00c3bc30(const char* pcSuffix)
{
    strcpy_s(DAT_01202a40, 0x104, DAT_01202fa0);
    strcat_s(DAT_01202a40, 0x104, pcSuffix);
}

namespace fnv_00c3bc80 {
// Copies DAT_01202fa0 into DAT_01202938, then appends src to that buffer.
// @fnv 0x00c3bc80
void __cdecl FUN_00c3bc80(const char* pcSuffix)
{
    fnv::crt::strcpy_s((*reinterpret_cast<char (*)[256]>(&::DAT_01202938)), 0x104, (*reinterpret_cast<char (*)[256]>(&::DAT_01202fa0)));
    fnv::crt::strcat_s((*reinterpret_cast<char (*)[256]>(&::DAT_01202938)), 0x104, pcSuffix);
}
}  // namespace fnv_00c3bc80

extern const void* DAT_010c14a8;
class MessageHandler
{
  public:
    const void* vtbl;
    bool bStatic;
    static MessageHandler* pHandler;
    MessageHandler* FUN_00c3bcf0(bool b);
};
// Calls FUN_00aa4c60, sets the vtable to DAT_010c14a8, stores b in bStatic, sets MessageHandler::pHandler to this and returns this.
// @fnv 0x00c3bcf0
MessageHandler* MessageHandler::FUN_00c3bcf0(bool abStatic)
{
    reinterpret_cast<::FUN_00aa4c60_class *>(this)->FUN_00aa4c60();
    *(const void**)this = &DAT_010c14a8;
    bStatic = abStatic;
    MessageHandler::pHandler = this;
    return this;
}

struct FUN_00c3c070_Class
{
    void* FUN_00c3c070(int arg);
};

// @fnv 0x00c3c070
void* FUN_00c3c070_Class::FUN_00c3c070(int arg)
{
    return 0;
}

extern "C" unsigned char DAT_011af49c;

// @fnv 0x00c3c0c0
void __cdecl FUN_00c3c0c0()
{
    for (int i = 0; i < 0x18; ++i)
        ((unsigned char*)0x11f6370)[i] = 0;
    DAT_011af49c = 0;
}

namespace fnv_00c3d380 {
struct MemoryManager
{
};
struct FUN_00c3d380_Class : public FUN_00c3c520_class
{
    void* FUN_00c3d380(unsigned int flags);
};
// @fnv 0x00c3d380
void* FUN_00c3d380_Class::FUN_00c3d380(unsigned int flags)
{
    FUN_00c3c520();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c3d380

namespace fnv_00c3d410 {
struct MemoryManager
{
};
struct _Base_00441d20
{
    ~_Base_00441d20();
};
struct FUN_00c3d410_Class : _Base_00441d20
{
    void* DestroySelf(unsigned int flags);
};
// Runs the base destructor, frees this via the memory manager when flags has bit 0 set, and returns this.
// @fnv 0x00c3d410
void* FUN_00c3d410_Class::DestroySelf(unsigned int flags)
{
    reinterpret_cast<::fnv_00c3cea0::FUN_00c3cea0 *>(this)->fnv_00c3cea0::FUN_00c3cea0::~FUN_00c3cea0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c3d410

namespace fnv_00c3d950 {
struct MemoryManager
{
};
struct FUN_00c3d950_Class
{
    void* FUN_00c3d950(unsigned int flags);
};
// @fnv 0x00c3d950
void* FUN_00c3d950_Class::FUN_00c3d950(unsigned int flags)
{
    ((FUN_00c3d930_Class*)this)->FUN_00c3d930();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c3d950

struct InputValues
{
    void* vtbl;
    unsigned int unk04;
    unsigned int unk08;
    int m_iState;
};
struct FUN_00c3fca0_Class
{
    void FUN_00c3fca0(void* p);
public:
    bool FUN_0044e050(::InputValues *);
};
// Sets the task's state to 4, calls the task's virtual method at vtable index 2, then sets the state to 5 and calls FUN_0044e050.
// @fnv 0x00c3fca0
void FUN_00c3fca0_Class::FUN_00c3fca0(void* apObject)
{
    InputValues* pTask = (InputValues*)apObject;
    pTask->m_iState = 4;
    ((void(*)(void*))(*(void***)apObject)[2])(apObject);
    pTask->m_iState = 5;
    reinterpret_cast<::FUN_00c3fca0_Class *>(this)->FUN_0044e050((::InputValues *)(apObject));
}

struct FUN_00c3fe00_Class
{
    char pad00[0x4];
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    void* FUN_00c3fe00(int a, int b, int c, int d);
};
// Stores the four arguments into the first four fields and zeroes the fields at offsets 0x10 through 0x20, returning this.
// @fnv 0x00c3fe00
void* FUN_00c3fe00_Class::FUN_00c3fe00(int aiField0, int aiField1, int aiField2, int aiField3)
{
    int* p4 = &this->unk14;
    *p4 = 0;
    int* p2 = &this->unk18;
    *p2 = 0;
    *(int*)this = aiField0;
    this->unk04 = aiField1;
    this->unk08 = aiField2;
    this->unk0c = aiField3;
    this->unk10 = 0;
    this->unk1c = 0;
    this->unk20 = 0;
    return this;
}

struct FUN_00c416a0_Class
{
    bool FUN_00c416a0(int a, int b, int c);
};
struct FUN_00c3fe80_Class : FUN_00c416a0_Class
{
    bool FUN_00c3fe80(int a, int b, int c, void** out);
    char pad00[0x4];
    int * unk04;
    int * unk08;
    int * unk0c;
    char pad10[0x4];
    uintptr_t unk14;
};
// @fnv 0x00c3fe80
bool FUN_00c3fe80_Class::FUN_00c3fe80(int aiArg1, int aiArg2, int aiArg3, void** ppOut)
{
    bool result = FUN_00c416a0(aiArg1, aiArg2, aiArg3);
    if (result)
    {
        int padA;
        {
            int padA2[40];
            {
                int padA3;
                {
                    uintptr_t* field = &this->unk14;
                    {
                        int padB[3];
                        {
                            char* obj;
                            {
                                void** src = (void**)((*field & ~(uintptr_t)1) + 8);
                                if (*ppOut != *src)
                                {
                                    if (*ppOut)
                                        ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(*ppOut));
                                    *ppOut = *src;
                                    if (*ppOut)
                                    {
                                        obj = (char*)*ppOut;
                                        InterlockedIncrement((long volatile*)(obj + 8));
                                    }
                                }
                                {
                                    uintptr_t* field2 = &this->unk14;
                                    {
                                        uintptr_t node = *field2 & ~(uintptr_t)1;
                                        {
                                            unsigned int* flags = (unsigned int*)(node + 0xc);
                                            if ((*flags & 1) ? true : false)
                                                result = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *this->unk04 = 0;
    *this->unk08 = 0;
    *this->unk0c = 0;
    return result;
}

// @fnv 0x00c33090
int __cdecl FUN_00c33090(const char* p)
{
    int result = 9;
    if (p)
    {
        switch (*p)
        {
        case 'b':
            result = 0;
            break;
        case 'c':
            result = 1;
            break;
        case 'f':
            result = 5;
            break;
        case 'h':
            result = 2;
            break;
        case 'i':
            result = 3;
            break;
        case 'u':
            result = 4;
            break;
        case 'S':
        case 's':
            result = 6;
            break;
        case 'r':
            result = 7;
            break;
        case 'a':
            result = 8;
            break;
        }
    }
    return result;
}

typedef void*(__cdecl* PFN_00c3c100)(void*, void*, unsigned int);
extern PFN_00c3c100 DAT_01202d5c;
extern intptr_t DAT_01202d70;
void __cdecl FUN_00c3c250();
void __cdecl FUN_00c3c280();
// @fnv 0x00c3c100
void* __cdecl FUN_00c3c100(void* a, void* b, unsigned int auiFlags)
{
    void* r = 0;
    if (DAT_01202d5c)
    {
        bool bAdjusted = false;
        if (auiFlags & 3)
        {
            FUN_00c3c250();
            if (DAT_01202d70)
            {
                auiFlags &= 0xffffefff;
                auiFlags |= 0x2000;
                bAdjusted = true;
            }
        }
        r = DAT_01202d5c(a, b, auiFlags);
        if (bAdjusted)
            FUN_00c3c280();
    }
    return r;
}

struct NiObject
{
};
struct FUN_00c465a0;
struct FUN_00c4fb10_shell;
struct FUN_00c61b10;

typedef NiObject*(__cdecl* PFN_NiObjectLoader)(void);

struct NiStream
{
    static int __cdecl RegisterObjectLoader(char const* name, PFN_NiObjectLoader loader);
};

FUN_00c465a0* __cdecl FUN_00c46740();
FUN_00c61b10* __cdecl FUN_00c61e70();
FUN_00c4fb10_shell* __cdecl FUN_00c4fdb0();

extern char const g_012043dc_arg0[];
extern char const g_012043e4_arg0[];
extern char const g_012031e8_arg0[];
extern char const g_01202de0_arg0[];
extern char const g_012043d4_arg0[];
extern char const g_01202e60_arg0[];
extern char const g_012043c8_arg0[];
extern char const g_012031c4_arg0[];
extern char const g_012043b0_arg0[];
extern char const g_012043a4_arg0[];
extern char const g_01202e8c_arg0[];
extern char const g_01202e7c_arg0[];
extern char const g_01202de8_arg0[];
extern char const g_01203340_arg0[];
extern char const g_0120436c_arg0[];
extern char const g_01202810_arg0[];
extern char const g_01202e74_arg0[];
extern char const g_01202820_arg0[];
extern char const g_01202818_arg0[];
extern char const g_01204398_arg0[];
extern char const g_01203108_arg0[];
extern char const g_01204390_arg0[];
extern char const g_01202e84_arg0[];
extern char const g_01204388_arg0[];

// @fnv 0x00c3a6d0
void FUN_00c3a6d0()
{
    NiStream::RegisterObjectLoader(g_012043dc_arg0, ((NiObject *(&)())::FUN_00c64810));
    NiStream::RegisterObjectLoader(g_012043e4_arg0, ((NiObject *(&)())::fnv_00c649f0::FUN_00c649f0));
    NiStream::RegisterObjectLoader(g_012031b8_arg0, ((NiObject *(&)())::fnv_00c537f0::FUN_00c537f0));
    NiStream::RegisterObjectLoader(g_012031e8_arg0, ((NiObject *(&)())::FUN_00c55010));
    NiStream::RegisterObjectLoader(g_01202de0_arg0, ((NiObject *(&)())::FUN_00c43190));
    NiStream::RegisterObjectLoader(g_012043d4_arg0, ((NiObject *(&)())::fnv_00c64530::CreateNamedNode));
    NiStream::RegisterObjectLoader(g_01202e60_arg0, reinterpret_cast<PFN_NiObjectLoader>(FUN_00c46740));
    NiStream::RegisterObjectLoader(g_012043c8_arg0, ((NiObject *(&)())::CreatePositionModifierObject));
    NiStream::RegisterObjectLoader(g_012031c4_arg0, ((NiObject *(&)())::FUN_00c54210));
    NiStream::RegisterObjectLoader(g_012043b0_arg0, reinterpret_cast<PFN_NiObjectLoader>(FUN_00c61e70));
    NiStream::RegisterObjectLoader(g_012043a4_arg0, ((NiObject *(&)())::FUN_00c61510));
    NiStream::RegisterObjectLoader(g_01202e8c_arg0, ((NiObject *(&)())::FUN_00c4b0c0));
    NiStream::RegisterObjectLoader(g_01202e7c_arg0, ((NiObject *(&)())::FUN_00c4ac00));
    NiStream::RegisterObjectLoader(g_01202de8_arg0, ((NiObject *(&)())::FUN_00c43a30));
    NiStream::RegisterObjectLoader(g_01203340_arg0, ((NiObject *(&)())::FUN_00c5cbb0));
    NiStream::RegisterObjectLoader(g_0120436c_arg0, ((NiObject *(&)())::fnv_00c5e5a0::FUN_00c5e5a0));
    NiStream::RegisterObjectLoader(g_01202810_arg0, ((NiObject *(&)())::FUN_00c361a0));
    NiStream::RegisterObjectLoader(g_01202e74_arg0, ((NiObject *(&)())::CreateNewObject));
    NiStream::RegisterObjectLoader(g_01202820_arg0, ((NiObject *(&)())::CreateNewBodyCls));
    NiStream::RegisterObjectLoader(g_01202818_arg0, ((NiObject *(&)())::CreateBC36500Object));
    NiStream::RegisterObjectLoader(g_01204398_arg0, ((NiObject *(&)())::fnv_00c610a0::FUN_00c610a0));
    NiStream::RegisterObjectLoader(g_01203108_arg0, reinterpret_cast<PFN_NiObjectLoader>(FUN_00c4fdb0));
    NiStream::RegisterObjectLoader(g_01204390_arg0, ((NiObject *(&)())::FUN_00c607d0));
    NiStream::RegisterObjectLoader(g_01202e84_arg0, ((NiObject *(&)())::FUN_00c4ae60));
    NiStream::RegisterObjectLoader(g_01204388_arg0, ((NiObject *(&)())::CreatePositionModifierInstance));
}


struct FUN_00c3ba80_Class
{
    void* FUN_00c3ba80(unsigned int flags);
    int a, b, c, d;
    void FUN_00c3bab0();
};


extern "C" unsigned char DAT_01202d55;
void* __cdecl FUN_00c3c100(void*, void*, unsigned int);

// Sets DAT_01202d55 to 1, calls FUN_00c3c100 with a, "Confirm" and 0x2034, then resets DAT_01202d55 to 0 and returns the result.
// @fnv 0x00c3c180
void* __cdecl FUN_00c3c180(void* a)
{
    void* result;
    DAT_01202d55 = 1;
    result = FUN_00c3c100(a, (void*)"Confirm", 0x2034);
    DAT_01202d55 = 0;
    return result;
}

extern unsigned char DAT_01202d55;

// Sets DAT_01202d55 to 1, calls FUN_00c3c100 with a, "Confirm" and 0x2033, then resets DAT_01202d55 to 0 and returns the result.
// @fnv 0x00c3c1c0
void* __cdecl FUN_00c3c1c0(void* a)
{
    DAT_01202d55 = 1;
    void* result = FUN_00c3c100(a, (void*)"Confirm", 0x2033);
    DAT_01202d55 = 0;
    return result;
}

struct GlobalObject_00c3bcf0
{
    ~GlobalObject_00c3bcf0();
    void* DestroyAndFree(unsigned int flags);
};
struct QueuedParents;
struct FUN_00c3d3b0_Class : QueuedParents
{
    void* FUN_00c3d3b0(unsigned int flags);
};
// Calls FUN_00c3c570, then deallocates this via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00c3d3b0
void* FUN_00c3d3b0_Class::FUN_00c3d3b0(unsigned int flags)
{
    FUN_00c3c570();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

struct FUN_00c42f00_Class
{
    void* FUN_00c3f130(unsigned int flags);
};
// @fnv 0x00c3f130
void* FUN_00c42f00_Class::FUN_00c3f130(unsigned int flags)
{
    ::DestroyResources((void *)(this));
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}


struct FUN_00c32fb0_cls
{
    int m_00;
    intptr_t m_04;
    const char* m_08;
    int GetFormatSize();
};

// Returns a size based on the first character of m_08: 1 for b/c/h, 4 for a/f/i/r/u, and for S/s the result of FUN_00ec6130 on m_04 plus 1, else 0.
// @fnv 0x00c32fb0
int FUN_00c32fb0_cls::GetFormatSize()
{
    int result = 0;
    if (m_08 != 0)
    {
        switch (*m_08)
        {
        case 'b':
        case 'c':
        case 'h':
            result = 1;
            break;
        case 'a':
        case 'f':
        case 'i':
        case 'r':
        case 'u':
            result = 4;
            break;
        case 'S':
        case 's':
            if ((this != 0 ? this->m_04 : 0) != 0)
            {
                result = std::strlen((const char *)(this != 0 ? this->m_04 : 0)) + 1;
            }
            break;
        default:
            break;
        }
    }
    return result;
}

struct StateVec3
{
    unsigned int x, y, z;
};
struct StateVec2
{
    unsigned int x, y;
};
struct StateMatrix3
{
    unsigned int entries[9];
};

struct FUN_00c337c0_State
{
    unsigned int unk00;
    unsigned int unk04;
    StateVec3 primary;
    StateVec2 secondary;
    StateMatrix3 transform;
    unsigned int scalar;
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
    unsigned char dirtyE4;
    unsigned char dirtyE5;

    void CopyStateTo(FUN_00c337c0_State* destination, unsigned int unused);
};

// @fnv 0x00c337c0
void FUN_00c337c0_State::CopyStateTo(FUN_00c337c0_State* destination, unsigned int unused)
{
    destination->primary = primary;
    destination->dirtyE4 = 1;
    destination->dirtyE5 = 1;

    destination->secondary = secondary;
    destination->dirtyE4 = 1;
    destination->dirtyE5 = 1;

    destination->transform = transform;
    destination->dirtyE4 = 1;
    destination->dirtyE5 = 1;

    unsigned int value = scalar;
    destination->scalar = value;
}

struct FUN_00c347d0_Elem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00c347d0_Slot
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct FUN_00c347d0_Scratch
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
};

struct FUN_00c347d0_Obj
{
    FUN_00c347d0_Slot m_slot[6];
    unsigned int m_uiMask;
};

struct FUN_00c347d0_cls
{
    bool FUN_00c347d0(FUN_00c347d0_Obj* obj);
};


struct Node
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class Sub08
{
  public:
    unsigned int unk00;
};

class Mid
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    Sub08 m_08;
};

class Scratch18
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};

class FUN_00c39a80_cls
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74,
        unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4,
        unkb8, unkbc;
    Mid m_c0;
    void FUN_00c39a80(unsigned int a1);
};

// If a1 is nonzero, acquires a Node from m_c0's Sub08, stores a1 in its m_08, and passes it to m_c0.Consume.
// @fnv 0x00c39a80
void FUN_00c39a80_cls::FUN_00c39a80(unsigned int auiValue)
{
    Scratch18 scratch;
    Node* n;
    if (auiValue != 0)
    {
        Mid* mid = &m_c0;
        n = ((::Node *)(reinterpret_cast<::FUN_0043a010_shell *>(&(mid->m_08))->FUN_0043a010()));
        n->m_08 = auiValue;
        reinterpret_cast<::FUN_00559a70_Class *>((mid))->FUN_00559a70(n);
    }
}

extern "C" int DAT_010c117c;

struct FUN_00c3a220_cls
{
    void* m_vptr;

    FUN_00c3a220_cls* FUN_00c3a220();
};

struct FUN_00c3a350_cls
{
    void** m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReserved;

    virtual void v0();
    virtual void* Alloc(unsigned int n);

    void InitBuffer(unsigned int a, unsigned int b);
};
// Sets the vtable pointer to DAT_010c117c, calls InitBuffer with 0 and 0, and returns this.
// @fnv 0x00c3a220
FUN_00c3a220_cls* FUN_00c3a220_cls::FUN_00c3a220()
{
    int unk04;
    int unk08;
    m_vptr = (void*)&DAT_010c117c;
    reinterpret_cast<::FUN_00c3a350_cls *>(this)->InitBuffer(0, 0);
    return this;
}

// @fnv 0x00c3a350
void FUN_00c3a350_cls::InitBuffer(unsigned int auiCapacity, unsigned int auiCount)
{
    m_pBuffer = 0;
    m_uiLogicalSize = 0;
    m_iReserved = 0;
    if (auiCount > auiCapacity)
    {
        auiCapacity = auiCount;
    }
    if (auiCapacity > 0)
    {
        m_pBuffer = (void**)Alloc(auiCapacity);
        m_iReserved = auiCapacity;
    }
    if (auiCount > 0)
    {
        for (unsigned int i = 0; i < auiCount; i++)
        {
            void*& r = m_pBuffer[i];
        }
        m_uiLogicalSize = auiCount;
    }
}

struct FUN_00c3a4b0_node
{
    FUN_00c3a4b0_node* m_00;
    void* m_04;
    uintptr_t m_08;
};

struct FUN_00c3a4b0_sub
{
    unsigned int m_uiItemCount;
};

struct FUN_00c3a4b0_cls
{
    FUN_00c3a4b0_node* m_00;
    void* m_04;
    FUN_00c3a4b0_sub m_08;
    uintptr_t FUN_00c3a4b0();
};

// @fnv 0x00c3a4b0
uintptr_t FUN_00c3a4b0_cls::FUN_00c3a4b0()
{
    FUN_00c3a4b0_node unusedNode;
    FUN_00c3a4b0_node* pRemoved = this->m_00;
    this->m_00 = this->m_00->m_00;
    if (this->m_00 != 0)
    {
        this->m_00->m_04 = 0;
    }
    else
    {
        this->m_04 = 0;
    }
    uintptr_t uiValue = pRemoved->m_08;
    pRemoved->m_08 = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(this->m_08))->FUN_0045cee0(pRemoved);
    this->m_08.m_uiItemCount = this->m_08.m_uiItemCount - 1;
    return uiValue;
}

struct FUN_00c3a530_node
{
    FUN_00c3a530_node* m_00;
    FUN_00c3a530_node* m_04;
    void* m_08;
};

struct FUN_00c3a530_alloc
{
    unsigned int m_uiCount;
};

struct FUN_00c3a530_cls
{
    FUN_00c3a530_node* m_00;
    FUN_00c3a530_node* m_04;
    FUN_00c3a530_alloc m_08;
    void* FUN_00c3a530();
};

struct FUN_00c3a530_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

// Removes the head node from a linked list, clears its payload pointer, frees the node, decrements the count and returns the payload.
// @fnv 0x00c3a530
void* FUN_00c3a530_cls::FUN_00c3a530()
{
    FUN_00c3a530_pad pad;
    FUN_00c3a530_node* pNode = m_04;
    void* p;
    m_04 = m_04->m_04;
    if (m_04 != 0)
    {
        m_04->m_00 = 0;
    }
    else
    {
        m_00 = 0;
    }
    p = pNode->m_08;
    pNode->m_08 = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(m_08))->FUN_0045cee0(pNode);
    m_08.m_uiCount -= 1;
    return p;
}

struct S_00c3a5e0
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
    void FUN_00c3a5e0();
};

// Calls FUN_00a5db30 then invokes the last virtual method v2f.
// @fnv 0x00c3a5e0
void S_00c3a5e0::FUN_00c3a5e0()
{
    reinterpret_cast<::FUN_00a5db30_shell *>(this)->FUN_00a5db30();
    v2f();
}

namespace fnv_00c3a620 {

class SpawnedBase
{
  public:
    intptr_t m_vptr;
    int unk04;
};

class FUN_00c3a620_cls : public SpawnedBase
{
  public:
    void FUN_00c3a620();
};

// Sets the object's vtable pointer to DAT_010c117c and calls SpawnedBase::FUN_00b5af80 with flags 1.
// @fnv 0x00c3a620
void FUN_00c3a620_cls::FUN_00c3a620()
{
    int unk00;
    this->m_vptr = (intptr_t)&DAT_010c117c;
    reinterpret_cast<::FUN_00b5af80_self *>((this))->FUN_00b5af80(1);
}
}  // namespace fnv_00c3a620



PFN_NiObjectLoader __cdecl FUN_00c3b3c0(const char* name);

static const char kLoadersSection[] = "Loaders";
static const char kNoDefault[] = "";
static const char kBackslash[] = "\\";
static const char kIniName[] = "Loaders.ini";
static const char kSpace[] = " ";

// Reads the Loaders section of Loaders.ini next to dir, resolves each key's value to a loader and registers it with NiStream under the key name.
// @fnv 0x00c3b3f0
void __cdecl LoadObjectLoadersFromIni(const char* dir)
{
    char pathX[260];
    unsigned int len4;
    char _keys[0x1000];
    char* key;
    unsigned int nVal;
    char value2[128];
    PFN_NiObjectLoader loader;
    char* copy3;

    strcpy_s(pathX, 260, dir);
    len4 = strlen(pathX);
    if (len4 < 4 || pathX[len4 - 4] != '.')
    {
        if (pathX[len4 - 1] != '\\')
            strcat_s(pathX, 260, kBackslash);
        strcat_s(pathX, 260, kIniName);
    }
    len4 = GetPrivateProfileStringA(kLoadersSection, 0, kSpace, _keys, 0x400, pathX);
    copy3 = 0;
    if (len4 != 0)
    {
        key = _keys;
        while (*key)
        {
            nVal = GetPrivateProfileStringA("Loaders", key, kNoDefault, value2, 128, pathX);
            if (nVal != 0)
            {
                loader = FUN_00c3b3c0(value2);
                if (loader != 0)
                {
                    nVal = strlen(key);
                    {
                        char* tmp = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(nVal + 1);
                        copy3 = tmp;
                    }
                    strcpy_s(copy3, nVal + 1, key);
                    NiStream::RegisterObjectLoader(copy3, loader);
                }
            }
            key += strlen(key) + 1;
        }
    }
}


// Copies path into a buffer, splits off extension and trailing underscore suffix, and writes a DATA\-prefixed or plain path plus suffix and extension to out.
// @fnv 0x00c3b7e0
void __cdecl BuildDataPath(char* outPath, const char* srcPath, const char* suffix)
{
    char buf[260];
    char ext3[10];
    char* dot3;
    char* underscore7;
    char* name;
    char* slash3;

    strcpy_s(buf, 260, srcPath);
    *outPath = 0;
    name = buf;
    dot3 = strrchr(name, '.');
    slash3 = strrchr(name, '\\');
    underscore7 = strrchr(name, '_');
    if (slash3 && underscore7 && underscore7 < slash3)
        underscore7 = 0;
    if (dot3)
    {
        strcpy_s(ext3, 10, dot3);
        if (underscore7)
            *underscore7 = 0;
        *dot3 = 0;
        if (*name != '\\' && name[1] != ':' && fnv::crt::strnicmp(name, "data", 4))
        {
            strcpy_s(outPath, 260, "DATA\\");
            strcat_s(outPath, 260, name);
            strcat_s(outPath, 260, suffix);
            strcat_s(outPath, 260, ext3);
        }
        else
        {
            strcpy_s(outPath, 260, name);
            strcat_s(outPath, 260, suffix);
            strcat_s(outPath, 260, ext3);
        }
    }
}


// @fnv 0x00c3bbd0
void* __cdecl FUN_00c3bbd0()
{
    return &DAT_01202b48;
}

extern char DAT_01202a40[0x104];

// @fnv 0x00c3bc20
char* __cdecl FUN_00c3bc20()
{
    return DAT_01202a40;
}

// FUN_00c3bc70 returns the address of the 0x104-byte scratch buffer that the
// sibling helpers FUN_00c3bc80 (strcpy_s/strcat_s on it) operate on.

// @fnv 0x00c3bc70
char* __cdecl FUN_00c3bc70()
{
    return DAT_01202938;
}

// @fnv 0x00c3bcd0
int __cdecl FUN_00c3bcd0()
{
    return 0;
}

extern "C" unsigned char DAT_011af49d;
extern "C" unsigned char DAT_011af49e;
extern "C" unsigned char DAT_011af49f;
extern unsigned char DAT_011f6370[0x18];
void __cdecl FUN_00c3c460();

// Calls FUN_00c3c460, stores four bytes and a function pointer into globals, clears DAT_011f6370, and copies DAT_01202d74 into DAT_011f6388.
// @fnv 0x00c3bd30
void __cdecl FUN_00c3bd30(unsigned char ucParam1, unsigned char ucParam2, unsigned char ucParam3,
                          unsigned char ucParam4, uintptr_t e)
{
    unsigned int unk04;
    unsigned int unk08;
    int i;
    FUN_00c3c460();
    DAT_011af49c = ucParam1;
    DAT_011af49d = ucParam2;
    DAT_011af49e = ucParam3;
    DAT_011af49f = ucParam4;
    DAT_01202d5c = reinterpret_cast<PFN_00c3c100>(e);
    for (i = 0; i < 0x18; i++)
    {
        DAT_011f6370[i] = 0;
    }
    DAT_011f6388 = reinterpret_cast<AbstractHeapLogger*>(MessageHandler::pHandler);
}

int __cdecl GetFileSize(int* buf, int* out);

struct BSCoreMessage
{
    virtual ~BSCoreMessage();
};

struct FUN_00c3bda0_Class : BSCoreMessage
{
    ~FUN_00c3bda0_Class();
};
// @fnv 0x00c3c430
void* GlobalObject_00c3bcf0::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::FUN_00c3bda0_Class *>((this))->FUN_00c3bda0_Class::~FUN_00c3bda0_Class();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

// @fnv 0x00c3bda0
FUN_00c3bda0_Class::~FUN_00c3bda0_Class()
{
    int info[9];
    if (GetFileSize(FUN_00c3bb80(), &info[7]) == 0)
    {
        if (info[7] == 0x46 && info[8] == 0)
            FUN_00aff0b0((const char*)FUN_00c3bb80());
    }
    if (MessageHandler::pHandler == (MessageHandler*)this)
        MessageHandler::pHandler = 0;
}

// @fnv 0x00c3be40
int FUN_00c3be40()
{
    return 0;
}

// @fnv 0x00c3c220
int __cdecl FUN_00c3c220()
{
    return 0;
}




extern intptr_t DAT_01202d70;

// @fnv 0x00c3c250
void __cdecl FUN_00c3c250()
{
    if (DAT_01202d70 == 0)
    {
        DAT_01202d70 = (intptr_t)SetWindowsHookExA(5, (HOOKPROC)::CbtHookProc, 0, GetCurrentThreadId());
    }
}


// If the global hook handle DAT_01202d70 is set, unhooks it with UnhookWindowsHookEx and clears the handle.
// @fnv 0x00c3c280
void __cdecl FUN_00c3c280()
{
    if (DAT_01202d70 != 0)
    {
        UnhookWindowsHookEx((HHOOK)DAT_01202d70);
        DAT_01202d70 = 0;
    }
}


typedef void* C3C2B0HWND;

extern int(* g_pfnC3C2B0GetClassName)(C3C2B0HWND hWnd, char* pcClassName, int m_iMaximumCount);
extern int(* g_pfnC3C2B0GetWindowText)(C3C2B0HWND hWnd, char* pcString, int m_iMaximumCount);


// EnumChildWindows callback: finds the "Cancel" button.
// Searches a window: if it is a Button whose text is non-empty and not "Cancel", stores it through lParam and returns false; otherwise returns true.
// @fnv 0x00c3c2b0
BOOL CALLBACK FindFirstNonCancelButton(HWND hWnd, LPARAM lParam)
{
    bool bContinueSearch = true;
    if (hWnd)
    {
        char acText[260];
        std::memset(acText, 0, 260);
        if (g_pfnC3C2B0GetClassName(hWnd, acText, 260) && !fnv::crt::stricmp(acText, "Button"))
        {
            std::memset(acText, 0, 260);
            if (g_pfnC3C2B0GetWindowText(hWnd, acText, 260) && acText[0] && !fnv::crt::stricmp(acText, "Cancel"))
            {
                C3C2B0HWND* phFoundButton = (C3C2B0HWND*)lParam;
                *phFoundButton = hWnd;
                bContinueSearch = false;
            }
        }
    }
    return bContinueSearch;
}



// @fnv 0x00c3c3a0
int CbtHookProc(int code, uintptr_t wParam, int lParam)
{
    if (code < 0)
    {
        return CallNextHookEx((HHOOK)DAT_01202d70, code, wParam, lParam);
    }
    switch (code)
    {
    case 5: {
        void* owner = (void*)wParam;
        void* found = 0;
        EnumChildWindows((HWND)owner, (WNDENUMPROC)::FindFirstNonCancelButton, (LPARAM)&found);
        if (found != 0)
        {
            SetWindowTextA((HWND)found, "Yes to all");
            FUN_00c3c280();
        }
        break;
    }
    }
    return CallNextHookEx((HHOOK)DAT_01202d70, code, wParam, lParam);
}

struct FUN_00c3c540_Class
{
    int* unk00;
    void Resize(int a, int b);
    int* FUN_00c3c540();
};

// Sets unk00 to DAT_010c14fc, calls Resize(5, 0), then sets unk00 to DAT_010c1510 and returns this.
// @fnv 0x00c3c540
int* FUN_00c3c540_Class::FUN_00c3c540()
{
    int unused04;
    int unused08;
    int unused0C;
    int unused10;
    int unused14;

    this->unk00 = &DAT_010c14fc;
    this->Resize(5, 0);
    this->unk00 = &DAT_010c1510;

    return reinterpret_cast<int*>(this);
}

class C3CAE0Task
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void Notify(int iStatus);
};

struct C3CAE0TaskArray
{
    int unk00;
    C3CAE0Task** m_ppkData;
    unsigned int m_uiSize;
};

class C3CAE0Manager
{
  public:
};


class C3CAE0Request
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
    C3CAE0TaskArray* m_pkTasks;

    void NotifyTasks(int iStatus);
};

struct C3D3E0Heap
{
    void Deallocate(void* pvMem);
};


class C3D3E0Palette
{
  public:
    int unk00;

    ~C3D3E0Palette();
    C3D3E0Palette* FUN_00c3d3e0(unsigned int uiFlags);
};


struct RefObject
{
    void* vtable;
    long unk04;
    volatile long refCount;
};
struct Array
{
    virtual ~Array();
    virtual void* Allocate(unsigned int count);
    RefObject** data;
    unsigned int size;
    unsigned int capacity;
    void Resize(unsigned int reserve, unsigned int count);
};
// Resets the array, allocates reserve slots (at least count), zero-initialises count elements and sets size to count.
// @fnv 0x00c3d780
void Array::Resize(unsigned int reserve, unsigned int count)
{
    data = 0;
    size = 0;
    capacity = 0;
    if (count > reserve)
        reserve = count;
    if (reserve > 0)
    {
        data = (RefObject**)Allocate(reserve);
        capacity = reserve;
    }
    if (count > 0)
    {
        unsigned int position;
        RefObject** initializedElement;
        RefObject** destination;
        RefObject* pointer;
        RefObject** array = data;
        for (position = 0; position < count; ++position)
        {
            destination = array + position;
            initializedElement =
                destination ? ((*destination = 0),
                               (*destination && (pointer = *destination, InterlockedIncrement(&pointer->refCount))),
                               destination)
                            : (RefObject**)0;
        }
        size = count;
    }
}

class FUN_00c3d870_cls
{
  public:
    virtual void* v0();
    virtual void* v1(void* a);
    virtual void v2(void* a);
    virtual void* v3(void* a, void* b);
    void FUN_00c3d870(void* a1, void* a2);

    void* m_04;
    unsigned int unk08;
    void* m_0c;
};

// Rebuilds m_04 from a1 when a2 differs from m_0c, otherwise updates m_04 via v3; caches a1 in m_0c when m_04 is null.
// @fnv 0x00c3d870
void FUN_00c3d870_cls::FUN_00c3d870(void* a1, void* a2)
{
    void* tmp;
    void* q;
    void* r;
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, a1);
        }
        else
        {
            tmp = v1(a1);
            reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(tmp), (char *)(m_04), (uintptr_t)(a2));
            v2(m_04);
            m_04 = 0;
            m_04 = tmp;
        }
    }
    else
    {
        m_04 = v1(a1);
        m_0c = a1;
    }
}

struct S_00c3db60_Item
{
    virtual ~S_00c3db60_Item();
};
struct S_00c3db60_Base
{
    S_00c3db60_Base();
    virtual ~S_00c3db60_Base();
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
};
struct FUN_00c3db60 : S_00c3db60_Base
{
    S_00c3db60_Item* unk64;
    virtual ~FUN_00c3db60();
};
// Destructor that deletes the owned item pointer unk64.
// @fnv 0x00c3db60
FUN_00c3db60::~FUN_00c3db60()
{
    delete unk64;
}

struct FUN_00c3df40_Param1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __int64 unk10;
};

struct FUN_00c3df40_Class
{
    void FUN_00c3e690(FUN_00c3df40_Param1* a1, __int64 a2);
    void FUN_00c3df40(FUN_00c3df40_Param1* a1, int a2);
};
// Notifies each task in m_pkTasks with iStatus, then forwards this request and iStatus to g_pkC3CAE0Manager.
// @fnv 0x00c3cae0
void C3CAE0Request::NotifyTasks(int iStatus)
{
    if (m_pkTasks)
    {
        unsigned int uiTaskCount = m_pkTasks->m_uiSize;
        for (unsigned int i = 0; i < uiTaskCount; i++)
        {
            C3CAE0Task*& rpkEntry = m_pkTasks->m_ppkData[i];
            C3CAE0Task* pkTask = rpkEntry;
            if (pkTask)
                pkTask->Notify(iStatus);
        }
    }
    reinterpret_cast<::FUN_00c3df40_Class *>(((*reinterpret_cast<::C3CAE0Manager * *>(&::DAT_01202d98))))->FUN_00c3df40((::FUN_00c3df40_Param1 *)(void *)(this), iStatus);
}

// @fnv 0x00c3df40
void FUN_00c3df40_Class::FUN_00c3df40(FUN_00c3df40_Param1* pParam, int iValue)
{
    __int64 val = pParam->unk10;
    val = (val & 0xFFFFFFFFFF00FFFFULL) + ((__int64)iValue << 16);
    this->FUN_00c3e690(pParam, val);
}

struct FUN_00c3f650_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiModulus;
    unsigned int Modulo(volatile unsigned int value, unsigned int unused);
};
// @fnv 0x00c3f650
unsigned int FUN_00c3f650_cls::Modulo(volatile unsigned int value, unsigned int unused)
{
    return value % m_uiModulus;
}

struct C3F670Timer
{
    unsigned __int64 FUN_00c3f670(unsigned __int64 uiTicks);
};

// @fnv 0x00c3f670
unsigned __int64 C3F670Timer::FUN_00c3f670(unsigned __int64 uiTicks)
{
    return uiTicks;
}

struct FUN_00c3f690_pair
{
    int x;
    int y;
};

struct FUN_00c3f690_cls
{
    int unk00;
    void CopyPair(FUN_00c3f690_pair p, FUN_00c3f690_pair* out);
};

// @fnv 0x00c3f690
void FUN_00c3f690_cls::CopyPair(FUN_00c3f690_pair aPair, FUN_00c3f690_pair* out)
{
    *out = aPair;
}

struct S_00c3f6b0_Class
{
    bool IsGreaterOrEqual(__int64 a, __int64 b);
};
// Returns whether a is greater than or equal to b.
// @fnv 0x00c3f6b0
bool S_00c3f6b0_Class::IsGreaterOrEqual(__int64 a, __int64 b)
{
    return a >= b;
}

struct FUN_00c3fa70_elem
{
    virtual int vDtor(int flags);
};

struct DynamicMemoryAllocator
{
};


struct TeardownBase
{
    virtual void v00();
    ~TeardownBase();
};

struct FUN_00c3fa70_cls : public TeardownBase
{
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
    unsigned int m_uCount4c;
    FUN_00c3fa70_elem** m_ppItems50;
    void* m_p54;

    virtual ~FUN_00c3fa70_cls();
};

// @fnv 0x00c3fa70
FUN_00c3fa70_cls::~FUN_00c3fa70_cls()
{
    unsigned int i = 0;
    FUN_00c3fa70_elem* item3;
    FUN_00c3fa70_elem* eTmp;
    for (; i < m_uCount4c; i++)
    {
        item3 = m_ppItems50[i];
        eTmp = item3;
        (eTmp != 0) ? eTmp->vDtor(1) : 0;
    }
    void* pItems = m_ppItems50;
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::DynamicMemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060(pItems);
    void* pTail2 = m_p54;
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::DynamicMemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060(pTail2);
}

class NiCullingProcess;
class NiAVObject
{
    public:
    void EnsureWorldBound();
};
struct BoundShape
{
    void AddRef();
};
struct TESBoundObjectBounds
{
    int unk00;
    int unk04;
    int iType;
};
struct BoundHolder
{
    int unk00;
    int unk04;
    int unk08;
    TESBoundObjectBounds* pData;
};
struct CullerData
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
    int iCullMode;
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
    BoundShape* pBound;
};
struct MultiBoundNodeStandIn
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
    NiAVObject** m_ppObjects;
    unsigned short unkA4;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned short unkAA;
    BoundHolder* pHolder;
    int iCullMode;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    BoundShape* pBound;

    void FUN_00c39890(NiCullingProcess& kCuller);
};

// @fnv 0x00c39890
void MultiBoundNodeStandIn::FUN_00c39890(NiCullingProcess& kCuller)
{
    CullerData* pProcB = 0;
    int bVis;
    int iOldModeB = 0;
    BoundShape* pOldBound;
    BoundShape* pNewBound;
    unsigned int iIndex;
    NiAVObject* pkChild;
    if (m_usElementCount == 0 && (bool)(int)(unkBC == 0))
        return;
    pProcB = (CullerData*)&kCuller;
    {
        BoundHolder* pH = pHolder;
        TESBoundObjectBounds* pD = pH->pData;
        bVis = pD->iType;
    }
    {
        int m1, m2;
        if ((m1 = pProcB->iCullMode) == 3 || (m2 = pProcB->iCullMode) == 1)
            bVis = 1;
    }
    {
        int m3, m4;
        if (bVis != 1 && (m3 = pProcB->iCullMode) != 3 && (m4 = pProcB->iCullMode) != 1)
            return;
    }
    pOldBound = pProcB->pBound;
    pNewBound = 0;
    pNewBound = pBound;
    iOldModeB = pProcB->iCullMode;
    {
        int m5;
        if ((m5 = pProcB->iCullMode) != 3)
        {
            int iMode = iCullMode;
            pProcB->iCullMode = iMode;
        }
    }
    {
        int m6, mB;
        if ((m6 = pProcB->iCullMode) != 3 && (mB = pProcB->iCullMode) != 1)
        {
            if (pNewBound)
                reinterpret_cast<::ControlGraph *>((pNewBound))->FUN_00c49850();
            pProcB->pBound = pNewBound;
            if (pNewBound)
                reinterpret_cast<::ControlGraph *>((pNewBound))->FUN_00c49850();
        }
    }
    for (iIndex = 0; iIndex < m_usSize; iIndex++)
    {
        NiAVObject** ppChild = &m_ppObjects[iIndex];
        pkChild = *ppChild;
        if (pkChild)
            reinterpret_cast<::S_00a59e00 *>((pkChild))->FUN_00a59e00((::S_00a59e00_Arg *)&(kCuller));
    }
    pProcB->iCullMode = iOldModeB;
    {
        int mA, m9;
        if ((mA = pProcB->iCullMode) != 3 && (m9 = pProcB->iCullMode) != 1)
            pProcB->pBound = pOldBound;
    }
}

// @fnv 0x00c3bce0
void __cdecl FUN_00c3bce0()
{}

// @fnv 0x00c3c090
void __cdecl FUN_00c3c090()
{}

// @fnv 0x00c3c0a0
void __cdecl FUN_00c3c0a0()
{}

// @fnv 0x00c3c0b0
void __cdecl FUN_00c3c0b0()
{}

// @fnv 0x00c3c240
void __cdecl FUN_00c3c240()
{}

int __cdecl FUN_00c33090(const char* p);

union SettingValue
{
    bool boolean;
    unsigned char character;
    int integer;
    unsigned int unsignedInteger;
    float real;
    const char* string;
};

struct FUN_00c33280_Class
{
    unsigned int m_00;
    SettingValue value;
    const char* m_08;
    void FUN_00c33280(NiTPrimitiveArray_unsigned_int_* arr);
};

// Builds two spaces plus m_08 in a 256-byte buffer, formats value by the type from FUN_00c33090(m_08), and adds the helper's result to arr via AddFirstEmpty.
// @fnv 0x00c33280
void FUN_00c33280_Class::FUN_00c33280(NiTPrimitiveArray_unsigned_int_* arr)
{
    char aBuf[256];
    unsigned int ai;
    unsigned int al;
    unsigned int bs;
    unsigned int bu;
    unsigned int* cb;
    unsigned int cl;
    unsigned int d1;
    unsigned int d7;
    unsigned int dx;
    const char* em;
    unsigned int fd;
    float* ff;
    unsigned int gb;
    int* ap;
    unsigned int at;
    unsigned char* by;
    unsigned int ch;
    bool* d4;
    const char* da;
    uintptr_t dg;
    uintptr_t dt;
    uintptr_t eh;
    uintptr_t fl;
    uintptr_t gf;
    uintptr_t bi;

    strcpy_s(aBuf, 256, "  ");
    da = m_08;
    strcat_s(aBuf, 256, da);
    switch (FUN_00c33090(m_08))
    {
    case 0:
        d4 = this ? &value.boolean : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).boolean = false, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).boolean);
        bi = ((uintptr_t)(::FUN_00a7d370(aBuf, *d4)));
        reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(bi));
        break;
    case 1:
    case 2:
        by = this ? &value.character : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).character = 0, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).character);
        gf = ((uintptr_t)(::FormatStringAssignment(aBuf, *by)));
        reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(gf));
    case 3:
        ap = this ? &value.integer : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).integer = 0, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).integer);
        fl = ((uintptr_t)(::FUN_00a7d4d0(aBuf, *ap)));
        reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(fl));
        break;
    case 5:
        ff = this ? &value.real : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).real = 0.0f, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).real);
        eh = ((uintptr_t)(::FUN_00a7d550(aBuf, *ff)));
        reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(eh));
        break;
    case 6:
        if (this)
            em = value.string;
        else
            em = 0;
        dt = (uintptr_t)::fnv_00a7d5e0::FUN_00a7d5e0(aBuf, em);
        reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(dt));
        break;
    case 4:
    default:
        cb = this ? &value.unsignedInteger : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).unsignedInteger = 0, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).unsignedInteger);
        dg = ((uintptr_t)(::FUN_00a7d510(aBuf, *cb)));
        reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(dg));
        break;
    }
}

struct FUN_00c3a250_Class
{
};

struct FUN_00c39ad0_Class
{
    int unk00[0x30];
    FUN_00c3a250_Class m_c0;

    void FUN_00c39ad0(int a);
};


struct S00c3a2e0_Ptr
{
    void* unk00;
    void FUN_0066b0d0(void* value);
};

struct S00c3a2e0_Node
{
    S00c3a2e0_Node* unk00;
    void* unk04;
    S00c3a2e0_Ptr unk08;
};

struct S00c3a2e0_Alloc
{
    void* unk00;
};

struct S00c3a2e0_Cls
{
    S00c3a2e0_Node* unk00;
    unsigned int unk04;
    S00c3a2e0_Alloc unk08;

    void FUN_00c3a2e0();
};

// Walks the list from unk00, calls FUN_0066b0d0(0) on each node and passes it to FUN_0045cee0, then zeroes unk08.unk00, unk00 and unk04.
// @fnv 0x00c3a2e0
void S00c3a2e0_Cls::FUN_00c3a2e0()
{
    S00c3a2e0_Node* pNext;
    S00c3a2e0_Node* p;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;

    p = this->unk00;
    while (p != 0)
    {
        pNext = p;
        p = p->unk00;
        pNext->unk08.FUN_0066b0d0(0);
        reinterpret_cast<::FUN_0045cee0_shell *>(&(this->unk08))->FUN_0045cee0(pNext);
    }
    this->unk08.unk00 = 0;
    this->unk00 = 0;
    this->unk04 = 0;
}

// @fnv 0x00c3bcc0
void FUN_00c3bcc0()
{}

extern int DAT_01202d78;
extern char* DAT_01202d58;
extern bool DAT_01202d90;
extern char DAT_010c14c0[];
extern char DAT_0101f520[];
struct C3BEFile
{
    int m_00, m_04, m_08, m_0c, m_10;
    C3BEFile(const char*, int, int, int);
    ~C3BEFile();
};
// Returns true immediately; the unreachable code after it writes text to path through a file object, recursing once with a message under a critical section.
// @fnv 0x00c3be50
bool __cdecl FUN_00c3be50(const char* path, const char* text, bool flush)
{
    return true;
    if (!path)
        return true;
    EnterCriticalSection((CRITICAL_SECTION*)&DAT_01202d78);
    if (DAT_01202d58 && !DAT_01202d90)
    {
        DAT_01202d90 = true;
        const char* prefix = DAT_01202d58 + 8;
        if (!*prefix)
            prefix = ::DAT_01015890;
        char buffer[256];
        ::FUN_00406d00(buffer, 256, DAT_010c14c0, DAT_01202d58 + 0xe0, prefix);
        FUN_00c3be50(path, buffer, false);
        DAT_01202d90 = false;
    }
    LeaveCriticalSection((CRITICAL_SECTION*)&DAT_01202d78);
    bool success = false;
    C3BEFile file(path, 1, 1, 0);
    if (file.m_00 == 0)
    {
        unsigned __int64 written = strlen(text);
        unsigned __int64 length;
        file.m_00 = reinterpret_cast<::SystemFileWriter *>(&(file))->FUN_00afede0((void *)(text), written, 0, &length);
        if (!DAT_01202d90 && success && (text[written - 2] != '\r' || text[written - 1] != '\n'))
        {
            written = 2;
            file.m_00 = reinterpret_cast<::SystemFileWriter *>(&(file))->FUN_00afede0((void *)(DAT_0101f520), written, 0, &length);
        }
        if (flush)
            file.m_00 = reinterpret_cast<::S_00aff060_Class *>(&(file))->FUN_00aff060();
        success = file.m_00 == 0;
    }
    return success;
}

// @fnv 0x00c3c080
void __cdecl FUN_00c3c080()
{}


struct Obj090
{
    int unk00;
    int unk04;
    long refs;
};

struct Smart090
{
    Obj090* ptr;
};

struct Node090
{
    int unk00;
    union
    {
        Smart090 smart;
        Node090* next;
    };
};

struct Vtbl090
{
    void* unk00;
    void* unk04;
    void* unk08;
    int limit;
};

struct FUN_00c42b60_class
{
    Vtbl090* vtbl;
    int unk04;
    int unk08;
    int count;
    Node090* head;
    void FUN_00c3f090(Node090* node);
};

// Clears node's pointer (via FUN_0044dd60), pushes node onto head, increments count, and calls FUN_00c42b80 when count equals vtbl->limit.
// @fnv 0x00c3f090
void FUN_00c42b60_class::FUN_00c3f090(Node090* node)
{
    int CN2;
    int CN;
    int CNA;
    Obj090* CNX;
    Smart090* Dir3 = &node->smart;
    if (Dir3->ptr != 0)
    {
        if (Dir3->ptr)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(Dir3->ptr));
        Dir3->ptr = 0;
        if (Dir3->ptr)
        {
            CNX = Dir3->ptr;
            InterlockedIncrement(&CNX->refs);
        }
    }
    Node090* CSATmp = head;
    node->next = CSATmp;
    head = node;
    count++;
    int CNVal = vtbl->limit;
    if (count == CNVal)
        reinterpret_cast<::fnv_00c42b80::C42List *>(this)->FUN_00c42b80();
}

struct FUN_00c41610_Obj
{
    void* unk00;
    unsigned int unk04;

};

struct FUN_00c3f750_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    FUN_00c41610_Obj* unk14;

    void* FUN_00c3f750();
};

extern "C" void*(* DAT_00fdf044)(unsigned int index);

// Calls DAT_00fdf044 with unk14->unk04 and returns the result if nonzero; otherwise returns unk14->SetSlotValue(this).
// @fnv 0x00c3f750
void* FUN_00c3f750_Class::FUN_00c3f750()
{
    int tmp;
    int d2;
    int d3;
    int d0;
    int v;
    void* j;
    void* found;
    FUN_00c41610_Obj* obj;

    obj = this->unk14;
    v = (int)obj->unk04;
    found = DAT_00fdf044((unsigned int)v);

    if (found)
    {
        j = found;
    }
    else
    {
        j = (void*)(uintptr_t)(reinterpret_cast<::fnv_00c41610::FUN_00c41610_cls *>((obj))->SetSlotValue((::fnv_00c41610::SlotValueSource *)(void *)(this)));
    }

    return j;
}

int __cdecl FUN_00c3c200();

void __cdecl FUN_00c3c0c0();

void* __cdecl FUN_00c3c100(void* a, void* b, unsigned int c);

void* __cdecl FUN_00c3c180(void* a);

void* __cdecl FUN_00c3c1c0(void* a);

int __cdecl FUN_00ec6130(int value);

void __cdecl LoadObjectLoadersFromIni(const char* dir);


void __cdecl BuildDataPath(char* out, const char* path, const char* suffix);

char* __cdecl FUN_00c3bc20();

// FUN_00c3bc70 returns the address of the 0x104-byte scratch buffer that the
// sibling helpers FUN_00c3bc80 (strcpy_s/strcat_s on it) operate on.
char* __cdecl FUN_00c3bc70();

int __cdecl FUN_00c3bcd0();

extern "C" void* fnv_zlib_memset(void* pvDest, int iValue, int iSize);

int C3C2B0StrCmp(const char* pcA, const char* pcB);

struct FNVVec3
{
    float x, y, z;
    FNVVec3(float x, float y, float z);
    FNVVec3 FUN_00439ef0(const FNVVec3& other) const
    {
        FNVVec3 result(x - other.x, y - other.y, z - other.z);
        return result;
    }
    FNVVec3 FUN_00439e90(const FNVVec3& other) const
    {
        FNVVec3 result(x + other.x, y + other.y, z + other.z);
        return result;
    }
    FNVVec3 ApplyScaled(float scale) const
    {
        FNVVec3 result(scale * x, scale * y, scale * z);
        return result;
    }
};

struct FNVPlane
{
    FNVVec3 normal;
    float distance;
    float GetPlaneConstant() const
    {
        return distance;
    }
};

struct FNVPlaneSet
{
    FNVPlane plane[6];
    unsigned int enabledFlags;
};

struct FNVClip
{
    bool FUN_00c35ae0(FNVVec3* begin, FNVVec3* end, FNVPlane* face, FNVPlaneSet* region);
};

extern const double DAT_010c0f58;

// @fnv 0x00c35ae0
bool FNVClip::FUN_00c35ae0(FNVVec3* begin, FNVVec3* end, FNVPlane* face, FNVPlaneSet* region)
{
    float kDirectionDiff[3];
    FNVVec3 direction = (*(::FNVVec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(end))->FUN_00439ef0((::NiPoint3 *)&kDirectionDiff, *(const ::NiPoint3 *)&(*begin))));
    FNVVec3 normal = face->normal;
    float denom = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(normal))->DotProduct((void *)&(direction));
    float fraction;
    if (denom == ::_DAT_01012060)
        return false;
    {
        fraction = (face->GetPlaneConstant() - reinterpret_cast<::FUN_004b6190_shell *>((void *)&(normal))->DotProduct((void *)&(*begin))) / denom;
        if (fraction >= ::_DAT_01012060 && fraction <= ::g_01012070)
        {
            FNVVec3 scaled = direction.ApplyScaled(fraction);
            FNVVec3 sum(0.0f, 0.0f, 0.0f);
            FNVVec3 result = (*(::FNVVec3 *)(reinterpret_cast<::Point3Offset *>((void *)(begin))->ProjectileLaunched((::NiPoint3 *)(void *)(&sum), (::NiPoint3 *)(void *)(&scaled))));
            for (int i = 0; i < 6; ++i)
            {
                if ((bool)((1 << i) & region->enabledFlags))
                {
                    if (reinterpret_cast<::FUN_004b6190_shell *>((void *)&(region->plane[i].normal))->DotProduct((void *)&(result)) - region->plane[i].GetPlaneConstant() <=
                        DAT_010c0f58)
                        return false;
                }
            }
            return true;
        }
    }
    return false;
}

// NiStream::GetLoader(const char*): look the name up in the static loader map.
// GetAt is an inline template member with two locals; declined inlining at /Od still reserves them.
template <class TVAL> struct NiTStringMapItemL
{
    NiTStringMapItemL* m_pkNext;
    const char* m_key;
    TVAL m_val;
};

template <class TVAL> class NiTStringPointerMapL
{
  public:
    virtual ~NiTStringPointerMapL();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    unsigned int m_uiHashSize;
    NiTStringMapItemL<TVAL>** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(const char* key, TVAL& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTStringMapItemL<TVAL>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};

// @fnv 0x00c3b3c0
PFN_NiObjectLoader __cdecl FUN_00c3b3c0(const char* pcName)
{
    PFN_NiObjectLoader pfnLoader = 0;
    reinterpret_cast<::A54440Hash *>((void *)(&::DAT_011f4784))->FUN_00a53c30((::A54440Manager *)(pcName), (::A54440Manager **)(pfnLoader));
    return pfnLoader;
}

struct Point
{
    float x, y, z;
    inline Point(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point operator+(const Point&) const;
    Point operator-(const Point&) const;
    inline Point()
    {}
    inline bool operator==(const Point& b) const
    {
        return b.x == x && b.y == y && b.z == z;
    }
};

struct FUN_00a699d0
{
    float x, y, z, w;
    FUN_00a699d0(const Point&, const Point&, const Point&);
    int ClassifyPoint(const Point*);
};

struct FUN_00a699d0s
{
    FUN_00a699d0 planes[6];
    unsigned int active;
    inline void SetWaterColorParameter(unsigned int i, const FUN_00a699d0& p)
    {
        planes[i] = p;
    }
    inline void DisablePlane(unsigned int i)
    {
        active &= ~(1 << i);
    }
};

struct CornerMatrix
{
    float entries[9];
    Point operator*(const Point&) const;
};

struct Builder
{
    int unk00;
    int unk04;
    Point center;
    float halfWidth;
    float halfHeight;
    CornerMatrix rotation;
    int unk40;
    FUN_00a699d0s cached;
    Point cachedCorners[4];
    Point last;
    bool cornersDirty;
    bool dirty;
    unsigned char disabled[4];
    inline void FUN_00c35c10(Point* out)
    {
        if (!cornersDirty)
        {
            memcpy(out, cachedCorners, 48);
            return;
        }
        Point right(halfWidth, 0, 0);
        Point up(0, 0, halfHeight);
        CornerMatrix* transform = &rotation;
        right = (*transform) * right;
        up = (*transform) * up;
        out[3] = center - right + up;
        out[2] = center - right - up;
        out[1] = center + right - up;
        out[0] = center + right + up;
        memcpy(cachedCorners, out, 48);
        cornersDirty = false;
    }
    void FUN_00c33870(Point eye, FUN_00a699d0s* out);
};

// @fnv 0x00c33870
void Builder::FUN_00c33870(Point eye, FUN_00a699d0s* out)
{
    if (!dirty && last == eye)
    {
        *out = cached;
        return;
    }
    Point corners5[4];
    FUN_00c35c10(corners5);
    out->active = 63;
    FUN_00a699d0 test7(corners5[0], corners5[1], corners5[2]);
    if (test7.ClassifyPoint(&eye) != 1)
    {
        out->SetWaterColorParameter(0, FUN_00a699d0(corners5[0], corners5[1], corners5[2]));
        out->DisablePlane(1);
        out->SetWaterColorParameter(2, FUN_00a699d0(corners5[0], corners5[1], eye));
        out->SetWaterColorParameter(3, FUN_00a699d0(corners5[2], corners5[3], eye));
        out->SetWaterColorParameter(4, FUN_00a699d0(corners5[3], corners5[0], eye));
        out->SetWaterColorParameter(5, FUN_00a699d0(corners5[1], corners5[2], eye));
    }
    else
    {
        out->SetWaterColorParameter(0, FUN_00a699d0(corners5[1], corners5[0], corners5[2]));
        out->DisablePlane(1);
        out->SetWaterColorParameter(2, FUN_00a699d0(corners5[1], corners5[0], eye));
        out->SetWaterColorParameter(3, FUN_00a699d0(corners5[3], corners5[2], eye));
        out->SetWaterColorParameter(4, FUN_00a699d0(corners5[0], corners5[3], eye));
        out->SetWaterColorParameter(5, FUN_00a699d0(corners5[2], corners5[1], eye));
    }
    for (int index = 0; index < 4; index++)
    {
        if (disabled[index] == 1)
            out->DisablePlane(index + 2);
    }
    last = eye;
    cached = *out;
    dirty = false;
}

extern int DAT_010c1064;

struct FUN_00c46970
{
    FUN_00c46970();
    virtual ~FUN_00c46970();
};

template <class T> struct ArrX
{
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMax;
    ArrX()
    {
        m_uiMax = 0;
        m_pBase = 0;
        m_uiSize = 0;
    }
    ~ArrX();
};

struct MemberX
{
    MemberX();
};

struct FUN_00c39640 : FUN_00c46970
{
    char pad04[0x2c];
    unsigned int m_uiValue1;
    char pad34[0x80];
    ArrX<int> m_kA;
    ArrX<int> m_kB;
    unsigned int m_uiCC;
    ArrX<int> m_kC;
    MemberX m_kCubicCoefficient;
    void SetBit(unsigned int uiMask, bool bVal)
    {
        int aiD[3];
        if (bVal)
            m_uiValue1 |= uiMask;
        else
            m_uiValue1 &= ~uiMask;
    }
    FUN_00c39640();
    virtual ~FUN_00c39640();
};

// @fnv 0x00c39640
FUN_00c39640::FUN_00c39640()
{
    SetBit(0x800, true);
    m_uiCC = 0;
}

extern const char* DAT_011af484[];

void __cdecl BuildDataPath(char*, const char*, const char*);

bool __cdecl FUN_00aa1a30(const char*, int);

struct TextureObject
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};

struct TexturePtr
{
    TextureObject* object;
    __forceinline TexturePtr()
    {
        object = 0;
        if (object)
            object->IncRefCount();
    }
    __forceinline ~TexturePtr()
    {
        if (object)
            object->DecRefCount();
    }
    inline TexturePtr& FUN_0066b0d0(TextureObject* other)
    {
        if (object != other)
        {
            if (object)
                object->DecRefCount();
            object = other;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
};

struct StringHeader
{
    volatile long refs;
    unsigned int length;
};

class NiFixedString
{
  public:
    const char* text;
    __forceinline NiFixedString(const char* source)
    {
        if (source == 0)
            text = ::DAT_0109b220;
        else
            text = ::NiGlobalStringTable::AddString(source);
    }
    __forceinline ~NiFixedString()
    {
        if (text == ::DAT_0109b220)
            return;
        volatile long* refs = &((StringHeader*)text)[-1].refs;
        InterlockedDecrement(refs);
    }
};

struct TextureLoader
{
    void FUN_00c3b5e0(const char* path);
};

// @fnv 0x00c3b5e0
void TextureLoader::FUN_00c3b5e0(const char* path)
{
    char filename[260];
    for (const char** suffix = DAT_011af484; *suffix; ++suffix)
    {
        BuildDataPath(filename, path, *suffix);
        TexturePtr texture;
        ::FindTextureByPath(filename, (::NiTexture **)(::TexturePtr *)(&texture));
        if (!texture.object && FUN_00aa1a30(filename, 0))
        {
            texture.FUN_0066b0d0(((::TextureObject *)(::NiSourceTexture::Create(NiFixedString(filename), (::NiTexture__FormatPrefs &)(DAT_011a9598), true, false))));
            if (texture.object)
                ::TextureFileEntrySetter::SetTexture((::NiTexture *)(texture.object), (const ::BSFileEntry *)(0));
        }
    }
}

class QueuedFile : public RefObject
{
};

struct QueuedPointer
{
    QueuedFile* pointer;
    QueuedPointer(QueuedFile* p = 0) : pointer(p)
    {
        if (pointer)
        {
            QueuedFile* object = pointer;
            InterlockedIncrement(&object->refCount);
        }
    }
};

struct BaseArray
{
    QueuedPointer* data;
    unsigned int size;
    unsigned int capacity;
    virtual ~BaseArray();
    virtual QueuedPointer* Allocate(unsigned int count);
    BaseArray()
    {
        Init(5, 0);
    }
    void Init(unsigned int reserve, unsigned int count)
    {
        data = 0;
        size = 0;
        capacity = 0;
        if (count > reserve)
            reserve = count;
        if (reserve > 0)
        {
            data = Allocate(reserve);
            capacity = reserve;
        }
        if (count > 0)
        {
            QueuedPointer* destination = data;
            for (unsigned int i = 0; i < count; ++i)
            {
                QueuedPointer* element = new (destination + i) QueuedPointer;
            }
            size = count;
        }
    }
};

struct FUN_00c3c4e0 : BaseArray
{
    unsigned int children;
    virtual ~FUN_00c3c4e0();
    FUN_00c3c4e0();
};

// @fnv 0x00c3c4e0
FUN_00c3c4e0::FUN_00c3c4e0()
{
    children = 0;
}

struct PoolShell
{
};


struct TlsScope
{
    int saved;
    static int Get()
    {
        return g_tlsBlock.memoryContext;
    }
    static void Set(int value)
    {
        g_tlsBlock.memoryContext = value;
    }
    TlsScope() : saved(Get())
    {
        Set(6);
    }
    ~TlsScope()
    {
        Set(saved);
    }
};

struct Child10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Child10(int count);
};

struct SmartRef
{
    int* ptr;
    SmartRef() : ptr(0)
    {
        if (ptr)
            AddRef(ptr);
    }
    static void AddRef(int* object)
    {
        InterlockedIncrement((volatile long*)(object + 2));
    }
};

struct Pair8
{
    int unk00;
    SmartRef unk04;
    Pair8() : unk00(0)
    {}
};

struct TwoInts
{
    int first;
    int second;
    TwoInts() : first(0), second(0)
    {}
};

struct BaseObj
{
    BaseObj()
    {}
    virtual ~BaseObj()
    {}
    virtual void vfunc0();
};

struct FUN_00c3eeb0 : BaseObj
{
    Pair8* unk04;
    Pair8* unk08;
    int unk0C;
    void* unk10;
    Child10* unk14;
    int unk18;
    int unk1C;
    TwoInts unk20;
    FUN_00c3eeb0(int count, int arg2);
    virtual ~FUN_00c3eeb0();
    virtual void vfunc0();
};

// @fnv 0x00c3eeb0
FUN_00c3eeb0::FUN_00c3eeb0(int count, int arg2)
{
    TlsScope context;
    unk18 = 0;
    unk04 = new Pair8();
    unk08 = unk04;
    unk0C = arg2;
    unk10 = new int[count << 1];
    unk14 = new Child10(count);
}

struct HeapContext_c3f530
{
    int unk000;
};

static __forceinline int GetHeap203()
{
    return ::g_tlsBlock.memoryContext;
}

static __forceinline void SetHeap203(int v)
{
    ::g_tlsBlock.memoryContext = v;
}

struct ScopedHeap_c3f530
{
    int iOld;
    __forceinline ScopedHeap_c3f530(int iNew)
    {
        iOld = GetHeap203();
        SetHeap203(iNew);
    }
    __forceinline ~ScopedHeap_c3f530()
    {
        SetHeap203(iOld);
    }
};

struct Point3_c3f530
{
    float x;
    float y;
    float z;
};

struct Owner_c3f530;

struct Item_c3f530
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
    Item_c3f530(Owner_c3f530* owner, float* x, float* y, float* z);
};

struct Owner_c3f530
{
    int unk00;
    float* pElementBuffer;
    Item_c3f530* FUN_00c3f530(int i);
};

// @fnv 0x00c3f530
Item_c3f530* Owner_c3f530::FUN_00c3f530(int i)
{
    ScopedHeap_c3f530 heap(6);
    return new Item_c3f530(this, &pElementBuffer[i * 3], &pElementBuffer[i * 3 + 1], &pElementBuffer[i * 3 + 2]);
}

struct RefX
{
    virtual void v00();
    int m_i04;
    long m_lRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
};

struct SPX
{
    RefX* m_pObject;
    SPX(const SPX& kOther)
    {
        int aiD[2];
        m_pObject = kOther.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SPX()
    {
        int aiE[3];
        if (m_pObject)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
    }
};

struct LockX
{
    int m_iOwner;
    int m_iArrayLength;
    void Unlock()
    {
        if (--m_iArrayLength == 0)
            m_iOwner = 0;
    }
};

struct ListQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05();
    virtual bool Test(unsigned int uiIndex, SPX pSceneObject);
    int m_i04;
    unsigned int m_uiCount;
    char pad0c[0x14];
    LockX m_kLock;
    bool FUN_00c3f960(SPX pSceneObject);
};

// @fnv 0x00c3f960
bool ListQ::FUN_00c3f960(SPX pSceneObject)
{
    bool bFound = false;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kLock))->FUN_0040fbf0((char *)(0));
    for (unsigned int i = 0; i < m_uiCount && !bFound; i++)
        bFound = Test(i, pSceneObject);
    reinterpret_cast<::FUN_00aa62e0_shell *>(&(m_kLock))->FUN_00aa62e0();
    return bFound;
}

struct NiPoint3
{
  public:
    float x, y, z;
    __forceinline NiPoint3()
    {}
    NiPoint3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
    NiPoint3 operator-(const NiPoint3& other) const;
    NiPoint3 operator+(const NiPoint3&) const;
    inline float Dot(const NiPoint3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }
public:
    static const ::NiPoint3 ZERO;
};

struct ClipMatrix
{
    float values[3][3];
    inline NiPoint3 operator*(const NiPoint3& point) const
    {
        return NiPoint3(values[0][0] * point.x + values[0][1] * point.y + values[0][2] * point.z,
                        values[1][0] * point.x + values[1][1] * point.y + values[1][2] * point.z,
                        values[2][0] * point.x + values[2][1] * point.y + values[2][2] * point.z);
    }
    __forceinline void GetRow(unsigned row, NiPoint3& out) const
    {
        out.x = values[row][0];
        out.y = values[row][1];
        out.z = values[row][2];
    }
};

class NiCamera
{
  public:
    float x, y, z, w;
    inline int ClassifyPoint(const NiPoint3* point)
    {
        float distance = x * point->x + y * point->y + z * point->z - w;
        if (distance < 0.0)
            return 2;
        else if (distance > 0.0)
            return 1;
        else
            return 0;
    }
};

struct ClipVolume
{
    NiCamera planes[6];
    unsigned mask;
};

struct RectangleClip
{
    int unk00, unk04;
    NiPoint3 center;
    float halfWidth, halfHeight;
    ClipMatrix rotation;
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
    NiPoint3 cached[4];
    int unkd8;
    int unkdc;
    int unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
    inline void FUN_00c35c10(NiPoint3* out)
    {
        if (!dirty)
        {
            memcpy(out, cached, sizeof(cached));
            return;
        }
        NiPoint3 horizontal(halfWidth, 0, 0);
        NiPoint3 vertical(0, 0, halfHeight);
        horizontal = rotation * horizontal;
        vertical = rotation * vertical;
        out[3] = center - horizontal + vertical;
        out[2] = center - horizontal - vertical;
        out[1] = center + horizontal - vertical;
        out[0] = center + horizontal + vertical;
        memcpy(cached, out, sizeof(cached));
        dirty = false;
    }
    bool FUN_00c33cf0(ClipVolume* volume, bool testCenter, NiPoint3 point);
};

inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}

// @fnv 0x00c33cf0
bool RectangleClip::FUN_00c33cf0(ClipVolume* volume, bool testCenter, NiPoint3 point)
{
    NiPoint3 corners[4];
    reinterpret_cast<::Builder *>(this)->FUN_00c35c10((::Point *)(corners));
    int masks[4];
    masks[0] = masks[1] = masks[2] = masks[3] = 0;
    for (int plane = 0; plane < 6; plane++)
    {
        if (bool(volume->mask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 4; vertex++)
            {
                if (volume->planes[plane].ClassifyPoint(&corners[vertex]) != 2)
                {
                    outside = false;
                }
                else
                {
                    masks[vertex] |= 1 << plane;
                }
            }
            if (outside)
                return false;
        }
    }
    edge0 = (masks[0] & masks[1]) != 0;
    edge1 = (masks[3] & masks[2]) != 0;
    edge2 = (masks[0] & masks[3]) != 0;
    edge3 = (masks[2] & masks[1]) != 0;
    bool needsTest = false;
    if (edge0 && edge1 && edge2 && edge3)
        needsTest = true;
    else if (!edge0 && edge1 && edge2 && edge3)
    {
        bool hit0 = false;
        for (int plane0 = 2; plane0 < 6; plane0++)
        {
            if (reinterpret_cast<::FNVClip *>(this)->FUN_00c35ae0((::FNVVec3 *)(::NiPoint3 *)(&corners[0]), (::FNVVec3 *)(::NiPoint3 *)(&corners[1]), (::FNVPlane *)(void *)(&volume->planes[plane0]), (::FNVPlaneSet *)(volume)))
            {
                hit0 = true;
                break;
            }
        }
        if (!hit0)
            needsTest = true;
    }
    else if (edge0 && !edge1 && edge2 && edge3)
    {
        bool hit1 = false;
        for (int plane1 = 2; plane1 < 6; plane1++)
        {
            if (reinterpret_cast<::FNVClip *>(this)->FUN_00c35ae0((::FNVVec3 *)(::NiPoint3 *)(&corners[3]), (::FNVVec3 *)(::NiPoint3 *)(&corners[2]), (::FNVPlane *)(void *)(&volume->planes[plane1]), (::FNVPlaneSet *)(volume)))
            {
                hit1 = true;
                break;
            }
        }
        if (!hit1)
            needsTest = true;
    }
    else if (edge0 && edge1 && !edge2 && edge3)
    {
        bool hit2 = false;
        for (int plane2 = 2; plane2 < 6; plane2++)
        {
            if (reinterpret_cast<::FNVClip *>(this)->FUN_00c35ae0((::FNVVec3 *)(::NiPoint3 *)(&corners[0]), (::FNVVec3 *)(::NiPoint3 *)(&corners[3]), (::FNVPlane *)(void *)(&volume->planes[plane2]), (::FNVPlaneSet *)(volume)))
            {
                hit2 = true;
                break;
            }
        }
        if (!hit2)
            needsTest = true;
    }
    else if (edge0 && edge1 && edge2 && !edge3)
    {
        bool hit3 = false;
        for (int plane3 = 2; plane3 < 6; plane3++)
        {
            if (reinterpret_cast<::FNVClip *>(this)->FUN_00c35ae0((::FNVVec3 *)(::NiPoint3 *)(&corners[2]), (::FNVVec3 *)(::NiPoint3 *)(&corners[1]), (::FNVPlane *)(void *)(&volume->planes[plane3]), (::FNVPlaneSet *)(volume)))
            {
                hit3 = true;
                break;
            }
        }
        if (!hit3)
            needsTest = true;
    }
    if (needsTest)
    {
        for (int planeLast = 2; planeLast < 6; planeLast++)
        {
            if (reinterpret_cast<::FNVClip *>(this)->FUN_00c35ae0((::FNVVec3 *)(::NiPoint3 *)(&corners[0]), (::FNVVec3 *)(::NiPoint3 *)(&corners[2]), (::FNVPlane *)(void *)(&volume->planes[planeLast]), (::FNVPlaneSet *)(volume)) ||
                reinterpret_cast<::FNVClip *>(this)->FUN_00c35ae0((::FNVVec3 *)(::NiPoint3 *)(&corners[1]), (::FNVVec3 *)(::NiPoint3 *)(&corners[3]), (::FNVPlane *)(void *)(&volume->planes[planeLast]), (::FNVPlaneSet *)(volume)))
                return true;
        }
        if (testCenter)
        {
            NiPoint3 delta = point - center;
            NiPoint3 axis = ::NiPoint3::ZERO;
            rotation.GetRow(0, axis);
            float vec = fabsf(reinterpret_cast<::FUN_004b6190_shell *>((void *)&(delta))->DotProduct((void *)&(axis)));
            rotation.GetRow(1, axis);
            float height = fabsf(reinterpret_cast<::FUN_004b6190_shell *>((void *)&(delta))->DotProduct((void *)&(axis)));
            if (vec <= halfWidth && height <= halfHeight)
                return true;
        }
        return false;
    }
    return true;
}

namespace fnv_00c34350 {
struct NiPoint3
{
  public:
    float x, y, z;
    __forceinline NiPoint3()
    {}
    NiPoint3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
    NiPoint3 operator-(const NiPoint3& other) const;
    NiPoint3 operator+(const NiPoint3&) const;
};
inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}
struct ClipMatrix
{
    float values[3][3];
    inline NiPoint3 operator*(const NiPoint3& point) const
    {
        return NiPoint3(values[0][0] * point.x + values[0][1] * point.y + values[0][2] * point.z,
                        values[1][0] * point.x + values[1][1] * point.y + values[1][2] * point.z,
                        values[2][0] * point.x + values[2][1] * point.y + values[2][2] * point.z);
    }
};
class NiCamera
{
  public:
    float x, y, z, w;
    inline int ClassifyPoint(const NiPoint3* point)
    {
        float distance = x * point->x + y * point->y + z * point->z - w;
        if (distance < 0.0)
            return 2;
        else if (distance > 0.0)
            return 1;
        else
            return 0;
    }
};
struct ClipVolume
{
    NiCamera planes[6];
    unsigned mask;
};
struct RectangleClip
{
    int unk00, unk04;
    NiPoint3 center;
    float halfWidth, halfHeight;
    ClipMatrix rotation;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4;
    NiPoint3 cached[4];
    int unkd8, unkdc, unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
    inline void FUN_00c35c10(NiPoint3* out)
    {
        if (!dirty)
        {
            memcpy(out, cached, sizeof(cached));
            return;
        }
        NiPoint3 horizontal(halfWidth, 0, 0);
        NiPoint3 vertical(0, 0, halfHeight);
        horizontal = rotation * horizontal;
        vertical = rotation * vertical;
        out[3] = center - horizontal + vertical;
        out[2] = center - horizontal - vertical;
        out[1] = center + horizontal - vertical;
        memcpy(cached, out, sizeof(cached));
        dirty = false;
    }
    unsigned char FUN_00c34350(ClipVolume* volume);
};
// @fnv 0x00c34350
unsigned char RectangleClip::FUN_00c34350(ClipVolume* volume)
{
    NiPoint3 corners[4];
    reinterpret_cast<::Builder *>(this)->FUN_00c35c10((::Point *)(corners));
    int masks[4];
    masks[0] = masks[1] = masks[2] = masks[3] = 0;
    unsigned char needsTest = 1;
    for (int plane = 0; plane < 6; plane++)
    {
        if (bool(volume->mask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 4; vertex++)
            {
                if (volume->planes[plane].ClassifyPoint(&corners[vertex]) != 2)
                    outside = false;
                else
                    masks[vertex] |= 1 << plane;
            }
            if (outside)
                needsTest = 0;
        }
    }
    edge0 = (masks[0] & masks[1]) != 0;
    edge1 = (masks[3] & masks[2]) != 0;
    edge2 = (masks[0] & masks[3]) != 0;
    edge3 = (masks[2] & masks[1]) != 0;
    return needsTest;
}
}

// namespace fnv_00c34350

namespace fnv_00c344c0 {
extern "C" double __cdecl sqrt(double);
struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    inline float Dot(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    inline NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    inline float Length() const
    {
        return (float)sqrt(x * x + y * y + z * z);
    }
    inline NiPoint3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return NiPoint3(x * inv, y * inv, z * inv);
    }
    inline NiPoint3 CrossProduct(const NiPoint3& p) const
    {
        NiPoint3 cross(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
        float length = cross.Length();
        if (length > 1e-6)
            return cross / length;
        else
            return NiPoint3(0.0f, 0.0f, 0.0f);
    }
    inline NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
};
NiPoint3 __cdecl operator*(float, const NiPoint3&);
extern "C" double __cdecl fabs(double);
inline float fabs(float f)
{
    return (float)fabs((double)f);
}
struct ClipPlane
{
    NiPoint3 normal;
    float constant;
    ClipPlane(const NiPoint3&, const NiPoint3&, const NiPoint3&);
    inline float GetPlaneConstant() const
    {
        return constant;
    }
    inline float Distance(const NiPoint3& p) const
    {
        return reinterpret_cast<::FUN_004b6190_shell *>((void *)&(normal))->DotProduct((void *)&(p)) - constant;
    }
};
struct ClipMatrix
{
    float entries[3][3];
    NiPoint3 operator*(const NiPoint3&) const;
    inline void GetColumn(unsigned int col, NiPoint3& out) const
    {
        out.x = entries[col][0];
        out.y = entries[col][1];
        out.z = entries[col][2];
    }
};
extern const double DAT_01072f80;
struct SSNode
{
    virtual void v0();
    virtual void v1();
    virtual const void* GetType();
    int unk04;
    NiPoint3 center;
    float extentX, extentY;
    ClipMatrix orientation;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4;
    NiPoint3 cache[4];
    int unkd8, unkdc, unke0;
    bool dirty;
    inline void FUN_00c35c10(NiPoint3* out)
    {
        if (!dirty)
            memmove(out, cache, 48);
        else
        {
            NiPoint3 a(extentX, 0.0f, 0.0f);
            NiPoint3 b(0.0f, 0.0f, extentY);
            a = orientation * a;
            b = orientation * b;
            out[3] = center - a + b;
            out[2] = center - a - b;
            out[1] = center + a - b;
            out[0] = center + a + b;
            memmove(cache, out, 48);
            dirty = false;
        }
    }
    bool FUN_00c344c0(void*, const NiPoint3&);
    inline bool IsExactType()
    {
        if (!this)
            return false;
        return GetType() == &(*reinterpret_cast<int *>(&::g_012030b0));
    }
};
inline float ClipAbs(float f)
{
    return (double)(float)fabs((double)f);
}
inline float DistanceFromFirst(void* data, int index, const NiPoint3& point)
{
    const ClipPlane* selected = &((ClipPlane*)data)[index];
    return selected->Distance(point);
}
// @fnv 0x00c344c0
bool SSNode::FUN_00c344c0(void* planes, const NiPoint3& point)
{
    NiPoint3 verticesTmp[4];
    reinterpret_cast<::Builder *>(this)->FUN_00c35c10((::Point *)(verticesTmp));
    ClipPlane plane3(verticesTmp[0], verticesTmp[1], verticesTmp[2]);
    float distance2 = plane3.Distance(point);
    NiPoint3 projected8 = point + (-distance2 * plane3.normal);
    distance2 += DistanceFromFirst(planes, 0, point);
    if (distance2 >= -5.0 && distance2 < 5.0)
    {
        NiPoint3 axisX = (*reinterpret_cast<const ::fnv_00c344c0::NiPoint3 *>((void *)&::NiPoint3::ZERO));
        NiPoint3 axisY4 = (*reinterpret_cast<const ::fnv_00c344c0::NiPoint3 *>((void *)&::NiPoint3::ZERO));
        orientation.GetColumn(0, axisX);
        orientation.GetColumn(1, axisY4);
        float x5 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(projected8))->DotProduct((void *)&(axisX)) - center.x;
        float y4 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(projected8))->DotProduct((void *)&(axisY4)) - center.y;
        if (ClipAbs(x5) <= extentX && ClipAbs(y4) <= extentY)
        {
            if (IsExactType())
                return true;
            else
                return false;
        }
    }
    return reinterpret_cast<::RectangleClip *>(this)->FUN_00c33cf0((::ClipVolume *)(planes), 1, (*(::NiPoint3 *)&(const ::fnv_00c344c0::NiPoint3 &)(projected8)));
}
}

// namespace fnv_00c344c0

namespace fnv_00c359d0 {
struct NiPoint3
{
  public:
    float x;
    float y;
    float z;
    __forceinline NiPoint3()
    {}
    NiPoint3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
    inline NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    inline NiPoint3 operator+(const NiPoint3& pt) const
    {
        return NiPoint3(x + pt.x, y + pt.y, z + pt.z);
    }
    inline NiPoint3 operator*(float f) const
    {
        return NiPoint3(x * f, y * f, z * f);
    }
    inline float Dot(const NiPoint3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

struct NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
    inline const NiPoint3& GetPlaneNormal() const
    {
        return m_kPlaneNormal;
    }
    inline float GetPlaneConstant() const
    {
        return m_fPlaneConstant;
    }
};

class SegmentPlaneTester
{
  public:
    bool FUN_00c359d0(const NiPoint3& kStart, const NiPoint3& kEnd, const NiPlane& m_kFogPlane, const NiPlane& kBound0,
                      const NiPlane& kBound1);
};

// @fnv 0x00c359d0
bool SegmentPlaneTester::FUN_00c359d0(const NiPoint3& kStart, const NiPoint3& kEnd, const NiPlane& m_kFogPlane,
                                      const NiPlane& kBound0, const NiPlane& kBound1)
{
    NiPoint3 kDir4 = kEnd - kStart;
    NiPoint3 kNormal2 = m_kFogPlane.GetPlaneNormal();
    float fDenom = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kNormal2))->DotProduct((void *)&(kDir4));
    if (fDenom == 0.0)
        return false;

    float fT5 = (m_kFogPlane.GetPlaneConstant() - reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kNormal2))->DotProduct((void *)&(kStart))) / fDenom;
    if (fT5 >= 0.0 && fT5 <= 1.0)
    {
        NiPoint3 kPoint = kStart + kDir4 * fT5;
        if (reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kBound0.GetPlaneNormal()))->DotProduct((void *)&(kPoint)) - kBound0.GetPlaneConstant() >= -0.0001)
        {
            if (reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kBound1.GetPlaneNormal()))->DotProduct((void *)&(kPoint)) - kBound1.GetPlaneConstant() >= -0.0001)
                return true;
        }
    }
    return false;
}
}

// namespace fnv_00c359d0

class NiRefObject
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    virtual ~NiRefObject();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class MbShape : public NiRefObject
{
};

class FUN_00c35eb0 : public NiRefObject
{
  public:
    int unk08;
    NiPointer<MbShape> m_spTransformData;
    virtual ~FUN_00c35eb0();
};

// @fnv 0x00c35eb0
FUN_00c35eb0::~FUN_00c35eb0()
{
    m_spTransformData = 0;
}

namespace fnv_00c39560 {
struct NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3& rhs) const;
};


inline float AbsF(float v)
{
    return ((void)v, (float)std::fabs((double)v));
}

class FUN_00c39560_Class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 center;
    NiPoint3 extents;
    bool FUN_00c39560(NiPoint3 point);
};

// @fnv 0x00c39560
bool FUN_00c39560_Class::FUN_00c39560(NiPoint3 point)
{
    NiPoint3 pointDelta = point - center;
    float uX;
    float sZ;
    float xY;
    float inX;
    float nX;
    float oy;
    float dstY;
    float az;
    float lz;
    return ((inX = pointDelta.x), (nX = AbsF(inX)), !(nX - extents.x > ::DAT_01016408)) &&
           ((oy = pointDelta.y), (dstY = AbsF(oy)), !(dstY - extents.y > ::DAT_01016408)) &&
           ((az = pointDelta.z), (lz = AbsF(az)), !(lz - extents.z > ::DAT_01016408));
}
}

// namespace fnv_00c39560

struct Base_00c46af0
{
    virtual ~Base_00c46af0();
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
};

struct ListItem
{
    ListItem* next;
    ListItem* prev;
    void* value;
};

struct List_b4_base
{
    ListItem* head;
    ListItem* tail;
    unsigned count;
    inline ~List_b4_base()
    {}
};

struct List_b4 : List_b4_base
{
    inline ~List_b4()
    {
        reinterpret_cast<::BSShaderLightingProperty *>(this)->ClearLights();
    }
    void FUN_00b71300();
    void DeleteItem(ListItem*);
    void Deallocate(ListItem*);
};

struct List_c0_base
{
    ListItem* head;
    ListItem* tail;
    unsigned count;
    int unk0C;
    inline ~List_c0_base()
    {}
};

struct List_c0 : List_c0_base
{
    inline ~List_c0()
    {
        reinterpret_cast<::NiTPointerListBaseRaw *>(this)->FUN_004ed900();
    }
    void FUN_004ed900();
    void DeleteItem(ListItem*);
};

struct Map_d0_base
{
    ListItem* head;
    ListItem* tail;
    unsigned count;
    inline ~Map_d0_base()
    {}
};

struct Map_d0 : Map_d0_base
{
    inline ~Map_d0()
    {
        reinterpret_cast<::S00c3a2e0_Cls *>(this)->FUN_00c3a2e0();
    }
    void FUN_00c3a2e0();
    void DeleteItem(ListItem*);
};

inline void List_b4::DeleteItem(ListItem* item)
{
    item->value = 0;
    Deallocate(item);
}

inline void List_b4::FUN_00b71300()
{
    List_b4* self = this;
    ListItem* current = head;
    while (current)
    {
        ListItem* item = current;
        current = current->next;
        self->DeleteItem(item);
    }
    count = 0;
    head = 0;
    tail = 0;
}

inline void List_c0::FUN_004ed900()
{
    ListItem* current = head;
    while (current)
    {
        ListItem* item = current;
        current = current->next;
        DeleteItem(item);
    }
    count = 0;
    head = 0;
    tail = 0;
}

inline void Map_d0::FUN_00c3a2e0()
{
    Map_d0* self = this;
    ListItem* current = head;
    while (current)
    {
        ListItem* item = current;
        ListItem* next = current->next;
        current = next;
        self->DeleteItem(item);
    }
    self->count = 0;
    self->head = 0;
    self->tail = 0;
}

struct Array_dc
{
    virtual ~Array_dc();
    virtual void Allocate();
    virtual void Deallocate(void*);
    void* data;
    unsigned size;
    unsigned capacity;
    inline void FUN_00b5af80(bool b)
    {
        void* allocation = data;
        if (allocation)
        {
            if (b)
            {
                Deallocate(allocation);
                data = 0;
                capacity = 0;
            }
            size = 0;
        }
    }
};

class FUN_00c39770 : public Base_00c46af0
{
  public:
    List_b4 m_b4;
    List_c0 m_c0;
    Map_d0 m_d0;
    Array_dc m_dc;
    virtual ~FUN_00c39770();
};

// @fnv 0x00c39770
FUN_00c39770::~FUN_00c39770()
{
    reinterpret_cast<::BSShaderLightingProperty *>(&(m_b4))->ClearLights();
    reinterpret_cast<::NiTPointerListBaseRaw *>(&(m_c0))->FUN_004ed900();
    reinterpret_cast<::S00c3a2e0_Cls *>(&(m_d0))->FUN_00c3a2e0();
    reinterpret_cast<::FUN_00b5af80_self *>(&(m_dc))->FUN_00b5af80(true);
    if (m_c0.unk0C)
        reinterpret_cast<::S_0045c520 *>(this)->FUN_0045c520();
}

struct Handler39
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
    virtual unsigned char v8c(void* arg);
};

struct Node39
{
    Node39* next;
    int prev;
    Handler39* item;
};

struct Owner39
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8;
    Handler39* handler;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    Node39* head;
    int tail;
    unsigned int count;
    unsigned char FUN_00c39b00(void* arg);
};

inline Handler39* Pass39(Handler39* p)
{
    return p;
}

// @fnv 0x00c39b00
unsigned char Owner39::FUN_00c39b00(void* arg)
{
    unsigned char Dir;
    Node39* CN;
    Handler39* CN2;
    Handler39* PN;
    Node39* CSA;
    Handler39** EndLoc;
    PN = handler;
    Dir = Pass39(PN)->v8c(arg);
    if (!Dir)
    {
        if (!(unsigned char)(unsigned int)(count == 0))
        {
            CSA = head;
            CN = CSA;
            while (!Dir && CN != 0)
            {
                EndLoc = &CN->item;
                CN = CN->next;
                CN2 = *EndLoc;
                Dir = CN2->v8c(arg);
            }
        }
    }
    return Dir;
}

class TargetC39B
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
    virtual int Process(void* pvArg);
};

class HolderC39B
{
  public:
    TargetC39B* GetTarget()
    {
        TargetC39B* p = m_pkTarget;
        return p;
    }
    int unk00;
    int unk04;
    int unk08;
    TargetC39B* m_pkTarget;
};

template <class T> struct NiTListItemC39B
{
    NiTListItemC39B* m_pkNext;
    NiTListItemC39B* m_pkPrev;
    T m_element;
};

typedef void* NiTListIteratorC39B;

template <class T> class NiTPointerListC39B
{
  public:
    bool IsEmpty() const
    {
        return m_uiCount == 0;
    }
    NiTListIteratorC39B GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListIteratorC39B& kPos) const
    {
        T* element = &((NiTListItemC39B<T>*)kPos)->m_element;
        kPos = ((NiTListItemC39B<T>*)kPos)->m_pkNext;
        return *element;
    }
    void* m_pVTable;
    NiTListItemC39B<T>* m_pkHead;
    NiTListItemC39B<T>* m_pkTail;
    unsigned int m_uiCount;
};

class OwnerC39B
{
  public:
    HolderC39B* GetHolder()
    {
        HolderC39B* p = m_pkHolder;
        return p;
    }
    int FUN_00c39bb0(void* pvArg);

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
    HolderC39B* m_pkHolder;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    NiTPointerListC39B<HolderC39B*> m_kChildList;
};

// @fnv 0x00c39bb0
int OwnerC39B::FUN_00c39bb0(void* pvArg)
{
    int iResult = GetHolder()->GetTarget()->Process(pvArg);
    if (iResult != 1 && !m_kChildList.IsEmpty())
    {
        NiTListIteratorC39B kPos = m_kChildList.GetHeadPos();
        while (iResult != 1 && kPos)
        {
            HolderC39B* pkChild = m_kChildList.GetNext(kPos);
            int node = pkChild->GetTarget()->Process(pvArg);
            if (node)
                iResult = node;
        }
    }
    return iResult;
}

struct Bound144
{
    struct Point
    {
        float x, y, z;
    } center;
    float radius;
};

struct BoundProvider144
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
    virtual void GetBound(Bound144&);
};

struct Controller144
{
    int unk00, unk04, unk08;
    BoundProvider144* provider;
};

struct Link144
{
    Link144* next;
    int unk04;
    Controller144* controller;
};

struct Node144
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    Bound144* bound;
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
    Node144** children;
    unsigned short capacity, size, used, grow;
    Controller144* controller;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    Link144* head;
    int unkD4;
    unsigned int count;
    void FUN_00c39d50();
    bool Flag80000()
    {
        return (unk30 & 0x80000) ? 1 : 0;
    }
};

// @fnv 0x00c39d50
void Node144::FUN_00c39d50()
{
    const Bound144* a0;
    float aAcoustic;
    Node144** aATmp;
    Bound144* a2;
    float aAction;
    const Bound144* aA6;
    int a114;
    int a3;
    int aActorList;
    float aActive;
    Node144** aAct;
    Bound144* a4;
    BoundProvider144* a2_3;
    Controller144* a1c8;
    Controller144** aAVal;
    Link144* aAB;
    int aAEPos;
    int a60;
    int a5;
    BoundProvider144* aA3;
    Controller144* aAX;
    Controller144* a9;
    Node144* a7;
    unsigned int a8;
    unsigned int aA5;
    Bound144 aA;
    Link144* aA2;
    BoundProvider144* aAa;
    bool first;
    first = true;
    a9 = controller;
    if (a9)
    {
        aAX = controller;
        aA3 = aAX->provider;
        aAa = aA3;
        if (aAa)
        {
            reinterpret_cast<::NiAVObject *>(this)->EnsureWorldBound();
            aAa->GetBound(*bound);
            if (!(unsigned char)(unsigned int)(count == 0))
            {
                aAB = head;
                aA2 = aAB;
                while (aA2)
                {
                    aAVal = &aA2->controller;
                    aA2 = aA2->next;
                    a1c8 = *aAVal;
                    a2_3 = a1c8->provider;
                    aAa = a2_3;
                    aAa->GetBound(aA);
                    reinterpret_cast<::Sphere *>((bound))->FUN_00a7f3f0((const ::Sphere &)(aA));
                }
            }
            first = false;
        }
    }
    if (first)
    {
        if (bound && Flag80000())
        {
            a4 = bound;
            a4->radius = 0.0f;
        }
        a8 = size;
        for (aA5 = 0; aA5 < a8; ++aA5)
        {
            aAct = &children[aA5];
            a7 = *aAct;
            if (a7 && ((a7->bound && ((aActive = a7->bound->radius), (double)aActive != 0.0)) ? 1 : 0))
            {
                reinterpret_cast<::NiAVObject *>(this)->EnsureWorldBound();
                aA6 = a7->bound ? a7->bound : &(*reinterpret_cast<::Bound144 *>(&::g_defaultBound));
                a2 = bound;
                aAction = aA6->radius;
                a2->center = aA6->center;
                a2->radius = aAction;
                ++aA5;
                break;
            }
        }
        for (; aA5 < a8; ++aA5)
        {
            aATmp = &children[aA5];
            a7 = *aATmp;
            if (a7 && ((a7->bound && ((aAcoustic = a7->bound->radius), (double)aAcoustic != 0.0)) ? 1 : 0))
            {
                a0 = a7->bound ? a7->bound : &(*reinterpret_cast<::Bound144 *>(&::g_defaultBound));
                reinterpret_cast<::Sphere *>((bound))->FUN_00a7f3f0((const ::Sphere &)(*a0));
            }
        }
    }
}

struct S00c3a180_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    void FUN_00c3a180();
};

struct S00c3a180_Scope
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    __forceinline ~S00c3a180_Scope()
    {}
};

// @fnv 0x00c3a180
void S00c3a180_cls::FUN_00c3a180()
{
    S00c3a180_Scope s;
    reinterpret_cast<::NiTPointerListBaseRaw *>(this)->FUN_004ed900();
}

struct ScopeGuardA3a1
{
    __forceinline ~ScopeGuardA3a1()
    {}
};

struct FUN_00c3a1d0_cls
{
    void FUN_00c3a1d0();
};

// @fnv 0x00c3a1d0
void FUN_00c3a1d0_cls::FUN_00c3a1d0()
{
    int s0, s1, s2, s3, s4, s5;
    ScopeGuardA3a1 guard;
    reinterpret_cast<::S00c3a2e0_Cls *>(this)->FUN_00c3a2e0();
}

struct Node250
{
    Node250* m_pkNext;
    Node250* m_pkPrev;
    void* m_element;
};

struct Alloc250
{
    unsigned int m_uiCount;
    void Deallocate(void* p);
};

struct List250
{
    Node250* m_pkHead;
    Node250* m_pkTail;
    Alloc250 m_kItemCount;

    inline Node250* GetHeadPos() const
    {
        return m_pkHead;
    }

    inline void* FindPos(void*& element, void* kStart = 0) const
    {
        void* kPrevNode;
        if (kStart == 0)
        {
            Node250* head = GetHeadPos();
            kStart = head;
        }
        while (kStart)
        {
            kPrevNode = kStart;
            void** pElement = &((Node250*)kStart)->m_element;
            kStart = ((Node250*)kStart)->m_pkNext;
            if (element == *pElement)
                return kPrevNode;
        }
        return 0;
    }

    inline void* RemoveHead()
    {
        Node250* pkItem = m_pkHead;
        m_pkHead = m_pkHead->m_pkNext;
        if (m_pkHead)
            m_pkHead->m_pkPrev = 0;
        else
            m_pkTail = 0;
        void* element = pkItem->m_element;
        pkItem->m_element = 0;
        m_kItemCount.Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
        return element;
    }

    inline void* RemoveTail()
    {
        Node250* pkItem = m_pkTail;
        m_pkTail = m_pkTail->m_pkPrev;
        if (m_pkTail)
            m_pkTail->m_pkNext = 0;
        else
            m_pkHead = 0;
        void* element = pkItem->m_element;
        pkItem->m_element = 0;
        m_kItemCount.Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
        return element;
    }

    inline void* RemovePos(void*& kPos)
    {
        int slot0 = 0;
        int slot1 = 0;
        int slot2 = 0;
        int slot3 = 0;
        int slot4 = 0;
        int slot5 = 0;
        int slot6 = 0;
        (void)slot0;
        (void)slot1;
        (void)slot2;
        (void)slot3;
        (void)slot4;
        (void)slot5;
        (void)slot6;
        Node250* pkItem = (Node250*)kPos;
        if (pkItem == m_pkHead)
        {
            kPos = pkItem->m_pkNext;
            return RemoveHead();
        }
        else if (pkItem == m_pkTail)
        {
            kPos = 0;
            return RemoveTail();
        }
        Node250* pkPrev = pkItem->m_pkPrev;
        Node250* pkNext = pkItem->m_pkNext;
        kPos = pkNext;
        if (pkPrev)
            pkPrev->m_pkNext = pkNext;
        if (pkNext)
            pkNext->m_pkPrev = pkPrev;
        void* element = pkItem->m_element;
        pkItem->m_element = 0;
        m_kItemCount.Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
        return element;
    }

    void* FUN_00c3a250(void*& element);
};

// @fnv 0x00c3a250
void* List250::FUN_00c3a250(void*& element)
{
    void* kPos = FindPos(element);
    return kPos ? RemovePos(kPos) : element;
}

template <class T> inline void NiTPointerAllocator<T>::Deallocate(void* pointer)
{
    unsigned a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
    a0 = 1;
    a1 = 2;
    a2 = 3;
    a3 = 4;
    a4 = 5;
    a5 = 6;
    a6 = 7;
    a7 = 8;
    a8 = 9;
    a9 = 10;
    a10 = 11;
    a11 = 12;
    a12 = 13;
    if (pointer == 0)
    {
        return;
    }
    reinterpret_cast<::FUN_0045cee0_shell *>(this)->FUN_0045cee0((void*)((char*)pointer + a0));
}

struct FUN_00c3a3f0_cls
{
    FNVPointerListItem* m_pkHead;
    FNVPointerListItem* m_pkTail;
    FNVPointerListBase::MapEntryCount m_kItemCount;

    void* FUN_00c3a3f0(void*& position);
};

// @fnv 0x00c3a3f0
void* FUN_00c3a3f0_cls::FUN_00c3a3f0(void*& position)
{
    FNVPointerListItem* node = (FNVPointerListItem*)position;
    if (node == m_pkHead)
    {
        position = node->m_pkNext;
        return ((void *)(reinterpret_cast<::FUN_00c3a4b0_cls *>(this)->FUN_00c3a4b0()));
    }
    if (node == m_pkTail)
    {
        position = 0;
        return reinterpret_cast<::FUN_00c3a530_cls *>(this)->FUN_00c3a530();
    }
    FNVPointerListItem* link = node->m_pkPrev;
    FNVPointerListItem* pkNext = node->m_pkNext;
    position = pkNext;
    if (link != 0)
    {
        link->m_pkNext = pkNext;
    }
    if (pkNext != 0)
    {
        pkNext->m_pkPrev = link;
    }
    void* value = node->m_element;
    node->m_element = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(m_kItemCount))->FUN_0045cee0(node);
    m_kItemCount.m_uiCount = m_kItemCount.m_uiCount - 1;
    return value;
}

struct S_Base
{
    inline ~S_Base()
    {
        reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
    }
};

struct S_X : S_Base
{
    inline ~S_X();
    S_X* FUN_00c3b9f0(unsigned int flags);
};

inline S_X::~S_X()
{
    reinterpret_cast<::FUN_00c64780_Class *>(this)->FUN_00c64780((const char *)(0));
}

// @fnv 0x00c3b9f0
S_X* S_X::FUN_00c3b9f0(unsigned int flags)
{
    *(const void**)this = DAT_010c1364;
    this->S_X::~S_X();
    if (flags & 1)
    {
        FUN_00aa1460(this, 12);
    }
    return this;
}

namespace fnv_00c3bab0 {

class NiMemObject
{
};
class NiRefObject : public NiMemObject
{
  public:
    virtual ~NiRefObject();
    unsigned int m_uiRefCount;
};

struct NodeRef;
struct NodeArrayAlloc
{
    static inline void Deallocate(void* p)
    {
        ::FUN_00aa10f0(p);
    }
};
struct NodeArray
{
    virtual ~NodeArray()
    {
        NodeArrayAlloc::Deallocate(m_pBase);
    }
    NodeRef** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    inline void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; ++i)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

class FUN_00c3bab0 : public NiRefObject
{
  public:
    NodeArray m_aiIndexedValues;
    ~FUN_00c3bab0();
};

// @fnv 0x00c3bab0
FUN_00c3bab0::~FUN_00c3bab0()
{
    m_aiIndexedValues.RemoveAll();
}
}

// namespace fnv_00c3bab0

// @fnv 0x00c3c460
void __cdecl FUN_00c3c460()
{
    MessageHandler::pHandler = (new MessageHandler)->FUN_00c3bcf0(false);
}

extern long volatile DAT_01202d94;

struct QfObj
{
    void IncRefCount();
    void DecRefCount();
};

template <class T> struct QfPointer
{
    T* m_pObject;

    ~QfPointer()
    {
        int spareA;
        int spareB;
        int spareC;
        if (m_pObject)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
    }
};

struct QfDeletable
{
    virtual ~QfDeletable();
};

struct QfBase
{
    virtual void vf();

    ~QfBase()
    {
        InterlockedDecrement(&DAT_01202d94);
    }
};

struct FUN_00c3c620 : QfBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    QfPointer<QfObj> m_sp1c;
    QfDeletable* m_p20;
    QfDeletable* m_p24;

    virtual ~FUN_00c3c620();
};

// @fnv 0x00c3c620
FUN_00c3c620::~FUN_00c3c620()
{
    delete m_p20;
    delete m_p24;
}

struct MemMgr2
{
};

struct RefObj
{
    void* vtbl;
    int m_04;
    long m_08;
    void AcquireReference()
    {
        InterlockedIncrement(&m_08);
    }
};

struct RefPtr
{
    RefObj* m_p;
    RefPtr(RefObj* p = 0)
    {
        RefObj* self;
        RefObj* object = p;
        m_p = object;
        if (m_p)
        {
            self = m_p;
            InterlockedIncrement(&self->m_08);
        }
    }
    RefPtr& operator=(const RefPtr& other)
    {
        if (m_p != other.m_p)
        {
            if (m_p)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
            m_p = other.m_p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
    ~RefPtr()
    {
        if (m_p)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
    }
};

__forceinline void ConstructRefs(RefPtr* buffer, unsigned count)
{
    for (unsigned i = 0; i < count; ++i)
    {
        new (buffer + i) RefPtr;
    }
}

struct OwnArr
{
    RefObj** m_data;
    unsigned m_uiItemCount;
    int m_0c;
    OwnArr();
    int Find(RefObj* o)
    {
        for (unsigned i = 0; i < m_uiItemCount; i++)
        {
            if (m_data && (unsigned char)(unsigned int)(m_data[i] == o))
                return i;
        }
        return -1;
    }
    virtual void unused();
    virtual RefObj** Allocate(unsigned);
    virtual void Deallocate(RefObj**);
    virtual RefObj** Reallocate(RefObj**, unsigned);
    void FUN_0042fb60(RefObj**, RefObj**, unsigned);
    inline void FUN_00c3d870(unsigned capacity, unsigned count)
    {
        if (m_data)
        {
            if (count == (unsigned)m_0c)
            {
                m_data = Reallocate(m_data, capacity);
            }
            else
            {
                RefObj** buffer = Allocate(capacity);
                FUN_0042fb60(buffer, m_data, count);
                Deallocate(m_data);
                m_data = 0;
                m_data = buffer;
            }
        }
        else
        {
            m_data = Allocate(capacity);
            m_0c = capacity;
        }
    }
    __forceinline unsigned FUN_00c3d6c0()
    {
        unsigned oldCapacity = m_0c;
        unsigned oldSize = m_uiItemCount;
        bool full = oldSize == oldCapacity;
        if (full)
        {
            if (!oldCapacity)
            {
                unsigned capacity = 4;
                m_data = Allocate(capacity);
                m_0c = capacity;
            }
            else
            {
                unsigned capacity = oldCapacity > 1024 ? oldCapacity + 1024 : oldCapacity * 2;
                FUN_00c3d870(capacity, oldSize);
                m_0c = capacity;
            }
        }
        ++m_uiItemCount;
        return m_uiItemCount - 1;
    }
    inline unsigned FUN_00c3d4f0(const RefPtr& item)
    {
        unsigned index = FUN_00c3d6c0();
        RefPtr* first = (RefPtr*)(m_data + index);
        unsigned count = 1;
        ConstructRefs(first, count);
        RefPtr* destination = (RefPtr*)(m_data + index);
        *destination = item;
        return index;
    }
};

struct IOTask
{
    void* vtbl;
    int m_04;
    long m_08;
    long m_0c;
    int m_10, m_14, m_18;
    RefObj* m_1c;
    void* m_20;
    OwnArr* m_24;
    void FUN_00c3c7e0(RefObj* obj);
};

// @fnv 0x00c3c7e0
void IOTask::FUN_00c3c7e0(RefObj* obj)
{
    if (!m_24)
    {
        m_24 = new OwnArr;
    }
    else if (m_24->Find(obj) != -1)
    {
        return;
    }
    m_24->FUN_00c3d4f0(obj);
    reinterpret_cast<::FUN_00c3c700_cls *>((obj))->FUN_00c3c700((::QueuedFile *)(void *)(this));
}

namespace fnv_00c3cb70 {
inline void Dead3()
{
    int a[3];
}
inline void Dead5()
{
    int a[5];
}
inline void Dead9()
{
    int a[9];
}
struct RefObj
{
    void* vtbl;
    int m_04;
    long m_08;
    void AcquireReference()
    {
        InterlockedIncrement(&m_08);
    }
};
struct RefPtr
{
    RefObj* m_p;
    void Clear()
    {
        Dead3();
        if (m_p)
        {
            if (m_p)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
            m_p = 0;
            if (m_p)
                m_p->AcquireReference();
        }
    }
};
struct PtrArr
{
    void* vtbl;
    RefObj** m_data;
    unsigned m_uiItemCount;
    unsigned GetCount()
    {
        return m_uiItemCount;
    }
    RefObj*& ElementAt(unsigned i)
    {
        RefObj*& r = m_data[i];
        return r;
    }
    RefObj* GetAt(unsigned i)
    {
        return ElementAt(i);
    }
};
struct OwnArr
{
    virtual ~OwnArr();
    RefObj** m_data;
    unsigned m_uiItemCount;
    unsigned GetCount()
    {
        return m_uiItemCount;
    }
    RefObj*& ElementAt(unsigned i)
    {
        return m_data[i];
    }
    RefObj* GetAt(unsigned i)
    {
        RefObj*& r = m_data[i];
        return r;
    }
    void FUN_00c3d5e0(unsigned, int);
};
struct IOManager
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
    virtual void v48(void*);
};
struct IOTask
{
    void* vtbl;
    int m_04;
    long m_08;
    long m_0c;
    int m_10, m_14, m_18;
    RefPtr m_1c;
    PtrArr* m_20;
    OwnArr* m_24;
    RefObj* GetCur()
    {
        return m_1c.m_p;
    }
    void SetState(long v)
    {
        long old = m_0c;
        bool r = InterlockedCompareExchange(&m_0c, v, old) == old;
    }
    void FUN_00c3cb70(int state, RefObj* obj);
};
// @fnv 0x00c3cb70
void IOTask::FUN_00c3cb70(int state, RefObj* obj)
{
    InterlockedIncrement(&m_08);
    if (obj)
    {
        if (GetCur() == obj)
        {
            m_1c.Clear();
        }
        else if (m_24)
        {
            for (unsigned i = 0; i < m_24->GetCount(); i++)
            {
                if (m_24->GetAt(i) == obj)
                {
                    m_24->FUN_00c3d5e0(i, 1);
                    break;
                }
            }
            Dead5();
            if (m_24->GetCount() == 0)
            {
                delete m_24;
                m_24 = 0;
            }
        }
    }
    else
    {
        m_1c.Clear();
        delete m_24;
        m_24 = 0;
    }
    if (GetCur() || m_24)
    {
        if (state == 1)
            (*reinterpret_cast<::fnv_00c3cb70::IOManager * *>(&::DAT_01202d98))->v48(this);
        else
            SetState(state);
    }
    else if (m_20)
    {
        unsigned n = m_20->m_uiItemCount;
        for (unsigned j = 0; j < n; j++)
        {
            RefObj* o = m_20->ElementAt(j);
            if (o)
                reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::fnv_00c3cb70::IOManager * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)(o), (intptr_t)(this));
        }
    }
    ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)this);
    Dead9();
}
}

// namespace fnv_00c3cb70

struct QEntry
{
    unsigned int unk00, unk04, packedSize, packedOffset;
};

struct QTask
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Describe(char*, unsigned int);
};

struct QPointer
{
    QTask* value;
    operator QTask*()
    {
        return value;
    }
};

struct QArray
{
    unsigned int unk00;
    QPointer* data;
    unsigned int count;
};

struct QRequest
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    QArray* tasks;
    unsigned int unk24;
    const char* name;
    QEntry* entry;
    bool FUN_00c3d0e0(char*, unsigned int, const char*);
};

// @fnv 0x00c3d0e0
bool QRequest::FUN_00c3d0e0(char* out, unsigned int size, const char* type)
{
    char buffer[13000];
    unsigned int i;
    {
        QEntry* a;
        const char* b;
        if ((a = entry) && (b = name))
        {
            QEntry* f = entry;
            unsigned int g = f->packedSize & 0x3fffffff;
            unsigned int c;
            QEntry* d = entry;
            c = d->packedOffset & 0x7fffffff;
            const char* e = name;
            ::FUN_00406d00(out, size, "Queued %s %s with file entry offset %i and size %i", type, e, c, g);
        }
        else
        {
            QEntry* h = entry;
            if (h)
            {
                QEntry* k = entry;
                unsigned int l = k->packedSize & 0x3fffffff;
                QEntry* j = entry;
                ::FUN_00406d00(out, size, "Queued %s with file entry offset %i and size %i", type,
                             j->packedOffset & 0x7fffffff, l);
            }
            else
            {
                const char* m = name;
                ::FUN_00406d00(out, size, "Queued %s %s", type, m);
            }
        }
        if (tasks)
        {
            unsigned int n;
            for (i = 0; i < (n = tasks->count); i++)
            {
                QPointer* p = &tasks->data[i];
                QTask* o = p->value;
                if (o)
                {
                    QPointer* q = &tasks->data[i];
                    if (static_cast<QTask*>(*q)->Describe(buffer, sizeof(buffer)))
                    {
                        strcat_s(out, size, "\n * ");
                        strcat_s(out, size, buffer);
                    }
                }
            }
        }
    }
    return true;
}

struct ObjA
{
};

inline unsigned Zero()
{
    return 0;
}

struct FUN_00c3d5e0_Class
{
    void* unk00;
    void** m_pBase;
    unsigned int m_uiSize;
    void FUN_0042fb60(void* dst, void* src, unsigned int count);
    void FUN_00c3d5e0(unsigned int uiStart, unsigned int ItemUpdateArray);
};

// @fnv 0x00c3d5e0
void FUN_00c3d5e0_Class::FUN_00c3d5e0(unsigned int uiStart, unsigned int ItemUpdateArray)
{
    unsigned int i;
    unsigned int base;
    unsigned int index;
    unsigned int q;
    unsigned int b;
    unsigned int count;
    unsigned int p;
    void** n0;
    unsigned int a;
    void** tmp;
    count = m_uiSize - uiStart - ItemUpdateArray;
    p = (count < ItemUpdateArray) ? count : ItemUpdateArray;
    n0 = m_pBase + uiStart;
    for (a = 0; a < ItemUpdateArray; ++a)
    {
        tmp = n0 + a;
        if (*tmp)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(((ObjA*)(*tmp))));
        if ((Zero() & 1u) != 0)
            reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(tmp);
    }
    reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(void *)(m_pBase + uiStart), (char *)(void *)((m_pBase + m_uiSize) - p), p);
    m_uiSize -= ItemUpdateArray;
}

struct ArrayC3D6C0
{
    void** vtbl;
    void* data;
    uintptr_t size;
    unsigned int cap;
    inline void FUN_00c3d870(unsigned int neu, unsigned int count)
    {
        unsigned int i = neu;
        unsigned int s = count;
        unsigned int u = neu;
        i = i + s;
        s = s + u;
        u = u + i;
        i = i + s;
        s = s + 1;
        u = u + 1;
        i = i + s;
        s = s + u;
        u = u + i;
        i = i + 2;
        s = s + 2;
        u = u + 2;
        i = i + s + u;
        s = i;
        u = s;
        i = u + 3;
        s = i + 4;
        u = s + 5;
        i = u + s;
        s = i + 6;
        u = s + 7;
        i = u + 8;
        s = i + 9;
        u = s + 1;
        if (i > s)
            u = i;
        else
            u = s;
        data = (void*)(uintptr_t)(i + s + u + count);
        cap = neu;
    }
    int FUN_00c3d6c0();
};

// @fnv 0x00c3d6c0
int ArrayC3D6C0::FUN_00c3d6c0()
{
    unsigned int first;
    uintptr_t high;
    bool last;
    if (size == cap)
        last = true;
    else
        last = false;
    if (last)
    {
        if (cap == 0)
        {
            first = 4;
            typedef void*(* AllocFn)(void*, unsigned int);
            data = ((AllocFn)vtbl[1])(this, first);
            cap = first;
        }
        else
        {
            high = cap > 0x400 ? cap + 0x400 : cap * 2;
            reinterpret_cast<::FUN_00c3d870_cls *>(this)->FUN_00c3d870((void *)(high), (void *)(size));
            cap = high;
        }
    }
    size = size + 1;
    return size - 1;
}

inline unsigned int DbgFlags()
{
    return 0;
}

struct ItemSlot
{
    void** ptr;
    int unk04;
    int unk08;
    int unk0C;
};

struct C3D980Cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void** pItems);
    void** m_ppItems;
    unsigned int m_uCount;
    int unk0C;

    void FUN_00c3d980(bool bFree);
};

// @fnv 0x00c3d980
void C3D980Cls::FUN_00c3d980(bool bFree)
{
    unsigned int used;
    void** data;
    ItemSlot pItem;
    unsigned int i;
    if (m_ppItems != 0)
    {
        used = m_uCount;
        data = m_ppItems;
        for (i = 0; i < used; i++)
        {
            pItem.ptr = &data[i];
            if (*pItem.ptr != 0)
            {
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(*pItem.ptr));
            }
            if (DbgFlags() & 1)
            {
                reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::DynamicMemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060(pItem.ptr);
            }
        }
        if (bFree)
        {
            v08(m_ppItems);
            m_ppItems = 0;
            m_ppItems = 0;
            unk0C = 0;
        }
        m_uCount = 0;
    }
}

namespace fnv_00c3dbf0 {
inline void Dead3()
{
    int a[3];
}
inline void Dead16()
{
    int a[16];
}
inline void Dead19()
{
    int a[19];
}
extern unsigned char DAT_01202dd8;
struct Setting
{
    void* vtbl;
    unsigned m_uiFilterValue;
    unsigned* GetPtr()
    {
        return this ? &m_uiFilterValue : ((*reinterpret_cast<unsigned int *>(&::DAT_01202800)) = 0, &(*reinterpret_cast<unsigned int *>(&::DAT_01202800)));
    }
    unsigned GetUInt()
    {
        unsigned* p = GetPtr();
        return *p;
    }
};
struct IOTask
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Run();
    int m_04;
    long m_iObjectReferenceCount;
    void AcquireReference()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
};
struct TaskPtr
{
    IOTask* m_p;
    TaskPtr(IOTask* p) : m_p(p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    ~TaskPtr()
    {
        if (m_p)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
    }
    TaskPtr& operator=(IOTask* p)
    {
        if (m_p != p)
        {
            if (m_p)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
            m_p = p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
    operator IOTask*() const
    {
        return m_p;
    }
    IOTask* operator->() const
    {
        return m_p;
    }
};
struct IOQueue
{
};
struct IOManager
{
    char pad00[0x64];
    IOQueue* m_queue;
    int m_uiContentCount;
    int m_6c;
    void (*m_idleFn)();
    bool (*m_canRunFn)();
    bool FUN_00c3dbf0();
};
// @fnv 0x00c3dbf0
bool IOManager::FUN_00c3dbf0()
{
    if (DAT_01202dd8)
        return true;
    bool result2 = true;
    DAT_01202dd8 = 1;
    unsigned ms = 0;
    if (m_uiContentCount == 6)
        ms = (*reinterpret_cast<::fnv_00c3dbf0::Setting *>(&::g_01202da8)).GetUInt();
    else
        ms = (*reinterpret_cast<::fnv_00c3dbf0::Setting *>(&::g_01202db4)).GetUInt();
    __int64 start = 0;
    __int64 limit5 = 0;
    start = ((long long)(::FUN_00aa4d80()));
    limit5 = (__int64)(ms * ::DAT_011ac39c);
    if (m_canRunFn)
        result2 = m_canRunFn();
    TaskPtr taskA(0);
    reinterpret_cast<::Container00c3e420 *>((m_queue))->FUN_00c3e420((intptr_t)&(taskA));
    while (taskA)
    {
        Dead16();
        taskA->Run();
        if (m_idleFn)
            m_idleFn();
        if (!(bool)(((long long)(::FUN_00aa4d80())) - start > limit5 ? 1 : 0))
        {
            reinterpret_cast<::Container00c3e420 *>((m_queue))->FUN_00c3e420((intptr_t)&(taskA));
        }
        else
        {
            taskA = 0;
        }
    }
    DAT_01202dd8 = 0;
    Dead3();
    return result2;
}
}

// namespace fnv_00c3dbf0


inline int S00c3de80_Zero()
{
    return 0;
}

struct S00c3de80_Key
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();

    int unk08;
    int unk0c;
    __int64 value;
};

struct S00c3de80_Obj
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

    bool FUN_00c3de80(S00c3de80_Key* object);
};

// @fnv 0x00c3de80
bool S00c3de80_Obj::FUN_00c3de80(S00c3de80_Key* object)
{
    S00c3de80_Key* self = object;
    if (unk68 != 6)
    {
        if ((unsigned char)(self->value >> 16) <= unk68)
        {
            self->value = (self->value & 0xffffffffff00ffffLL) + ((__int64)S00c3de80_Zero() << 16);
        }
    }

    self->v6();

    while (!reinterpret_cast<::Target *>(this)->FUN_00c3fb50((::Task *)(self)))
    {
        __declspec(align(2)) unsigned short serial = (unsigned short)InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::fnv_0043dc10::DAT_01202d9c)));

        self->value = (self->value & 0xffffffffffff0000LL) + (int)serial;
    }

    return true;
}

struct IOQueue
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual unsigned Count();
};

struct IOManager
{
    char pad00[0x18];
    unsigned m_18;
    char pad1c[0x64 - 0x1c];
    IOQueue* m_queue;
    int m_uiContentCount;
    unsigned (*m_pendingFn)();
    char pad70[0x78 - 0x70];
    void (*m_progressFn)(float);
    unsigned QueuedCount()
    {
        return m_queue->Count();
    }
    void FUN_00c3dfa0(int mode);
};

extern long __cdecl FinishScriptRunLock(volatile long*);

struct RefObj_c3e1b0
{
    virtual ~RefObj_c3e1b0();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Run(int arg);
    int unk04;
    long refCount;
    inline void AcquireReference()
    {
        InterlockedIncrement(&refCount);
    }
    inline void DecRef()
    {
        long remaining = FinishScriptRunLock(&refCount);
        if (remaining == 0)
            delete this;
    }
};

struct RefPtr_c3e1b0
{
    RefObj_c3e1b0* obj;
    inline RefObj_c3e1b0* operator->() const
    {
        return obj;
    }
    inline RefPtr_c3e1b0(RefObj_c3e1b0* p = 0)
    {
        obj = p;
        if (obj)
            obj->AcquireReference();
    }
    inline ~RefPtr_c3e1b0()
    {
        if (obj)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(obj));
    }
};

struct StreamBase_c3e1b0
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char flags;
    inline StreamBase_c3e1b0()
    {
        unk08 = 0;
        unk10 = 0;
        unk14 = 0;
        flags = 0;
    }
    virtual ~StreamBase_c3e1b0()
    {}
    virtual void Reset()
    {
        unk10 = 0;
        unk14 = 0;
    }
    inline bool Started() const
    {
        return bool(flags & 1);
    }
    inline bool Finished() const
    {
        return bool(flags & 2);
    }
    inline void SetStarted(bool value)
    {
        if (value)
            flags |= 1;
        else
            flags &= ~1;
    }
    inline void SetFinished(bool value)
    {
        if (value)
            flags |= 2;
        else
            flags &= ~2;
    }
};

struct Stream_c3e1b0 : StreamBase_c3e1b0
{
    int unk1c;
    inline Stream_c3e1b0()
    {}
    inline void Reserve(int size)
    {
        Reset();
        unk08 = size;
        SetStarted(false);
        SetFinished(false);
    }
};

extern unsigned gm_GetCurrentThreadId();


extern void LockBarrier();

struct NextLockC3
{
    long owner;
    unsigned depth;
    inline void Lock(const char*)
    {
        unsigned threadId = gm_GetCurrentThreadId();
        if (owner == threadId)
            ++depth;
        else
        {
            unsigned spins = 0;
            while (FUN_0043b460(&owner, 0, threadId))
            {
                ++spins;
                if (spins > 10000)
                    FUN_0040fca0(1);
                else
                    FUN_0040fca0(0);
            }
            LockBarrier();
            depth = 1;
        }
    }
    inline void Unlock()
    {
        --depth;
        if (!depth)
            owner = 0;
    }
};

struct QueueC3
{
    bool First(unsigned, void*, RefPtr_c3e1b0*);
    bool Next(unsigned, void*, RefPtr_c3e1b0*);
};

struct IOMgr_c3e1b0;

struct QueueRegistryC3
{
    int unk00;
    unsigned tlsIndex;
    QueueC3* Create(IOMgr_c3e1b0*);
    inline QueueC3* Get(IOMgr_c3e1b0* mgr)
    {
        unsigned index = tlsIndex;
        void* value = TlsGetValue(index);
        return value ? (QueueC3*)value : Create(mgr);
    }
};

struct IOMgr_c3e1b0
{
    int unk00, unk04;
    unsigned count;
    int unk0c, unk10;
    QueueRegistryC3* registry;
    int unk18, unk1c;
    NextLockC3 nextLock;
    inline unsigned Count() const
    {
        return count;
    }
    inline QueueC3* GetQueue()
    {
        return registry->Get(this);
    }
    void Lock();
    void Unlock();
    inline bool Next(Stream_c3e1b0* s, __int64* key, RefPtr_c3e1b0* p, bool flag)
    {
        nextLock.Lock(0);
        bool result = false;
        if (s->Finished())
            result = false;
        else
        {
            while (true)
            {
                if (!s->Started())
                {
                    result = GetQueue()->First(s->unk08, &s->unk10, p);
                    s->SetStarted(true);
                }
                else
                    result = GetQueue()->Next(s->unk08, &s->unk10, p);
                if (!result)
                {
                    ++s->unk08;
                    if ((unsigned)s->unk08 >= Count())
                        s->SetFinished(true);
                    else if (flag)
                    {
                        s->SetStarted(false);
                        continue;
                    }
                }
                else
                    *key = *reinterpret_cast<const __int64*>(&s->unk10);
                break;
            }
        }
        nextLock.Unlock();
        return result;
    }
    void FUN_00c3e1b0(int maxPriority, int arg);
};

// @fnv 0x00c3dfa0
void IOManager::FUN_00c3dfa0(int mode)
{
    if (m_uiContentCount == 7)
        return;
    DAT_011af70c = 0;
    if (m_18 == 0 && QueuedCount() == 0 && (m_pendingFn ? m_pendingFn() : 0) == 0)
    {
        m_uiContentCount = 6;
        DAT_011af70c = 1;
        return;
    }
    m_uiContentCount = mode;
    reinterpret_cast<::IOMgr_c3e1b0 *>(this)->FUN_00c3e1b0(mode, 0);
    unsigned queued9 = m_queue->Count();
    unsigned total2 = ((unsigned int)(reinterpret_cast<::FUN_00c3e860_t *>(this)->SumArrayUpToCount(mode * 4 + 3))) + queued9 + (m_pendingFn ? m_pendingFn() : 0);
    float pctVal;
    unsigned remaining = total2;
    bool done7 = false;
    while (remaining != 0 || !done7)
    {
        pctVal = (float)((double)(total2 - remaining) / (double)total2 * 100.0);
        if (m_progressFn)
            m_progressFn(pctVal);
        unsigned limit = m_18;
        if (limit > m_queue->Count())
            Sleep(50);
        done7 = reinterpret_cast<::fnv_00c3dbf0::IOManager *>(this)->FUN_00c3dbf0();
        unsigned queued4 = m_queue->Count();
        remaining = ((unsigned int)(reinterpret_cast<::FUN_00c3e860_t *>(this)->SumArrayUpToCount(mode * 4 + 3))) + queued4 + (m_pendingFn ? m_pendingFn() : 0);
    }
    m_uiContentCount = 6;
    if (m_progressFn)
        m_progressFn(100.0f);
    DAT_011af70c = 1;
}

// @fnv 0x00c3e1b0
void IOMgr_c3e1b0::FUN_00c3e1b0(int maxPriority, int arg)
{
    if (maxPriority <= arg)
        return;
    {
        reinterpret_cast<::FUN_00c3e310_shell *>(this)->FUN_00c3e310();
        Stream_c3e1b0 stream;
        reinterpret_cast<::FUN_00c42060_Class *>(&(stream))->SetArg(arg * 4 + 4);
        while (!bool(stream.flags & 2))
        {
            __int64 key = 0;
            RefPtr_c3e1b0 item3;
            if (reinterpret_cast<::Map40 *>(this)->FUN_00c40e70((::Iter40 *)(::Stream_c3e1b0 *)(&stream), &key, (intptr_t)(&item3), 1))
            {
                if ((unsigned char)(key >> 16) > maxPriority)
                    break;
                item3->Run(arg);
            }
        }
        reinterpret_cast<::FUN_00c3e340_cls *>(this)->FUN_00c3e340();
    }
}

struct Q
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
    virtual int v9(int x, int y);
};

struct H
{
    Q* q;
};

struct LockObj
{
    void* owner;
    int count;
    __forceinline void Unlock()
    {
        count = count - 1;
        if (count == 0)
            owner = 0;
    }
};

struct Owner
{
    int u0, u1, u2, u3, u4, u5, u6, u7;
    LockObj lock;
    __forceinline bool pass(H* node, int a, int b, intptr_t c)
    {
        return reinterpret_cast<::FUN_00c3fe80_Class *>((node))->FUN_00c3fe80(node->q->v9(a, b), a, b, (void **)(c));
    }
    bool FUN_00c3f160(int a, int b, int c);
};

// @fnv 0x00c3f160
bool Owner::FUN_00c3f160(int a, int b, int c)
{
    int local4, local5, local6, receiver, answer;
    int extra14, done, status, extra4, extra5;
    int slot2, spare4, spare5, spare6, spare8, spare9, extra15;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    H* node = ((::H *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750()));
    bool found = pass(node, a, b, c);
    reinterpret_cast<::GameTimerRecord *>(&(lock))->Enable();
    return found;
}

struct Inner
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9(int a, int b);
};

class RecursiveSpinLock
{
  public:
    volatile long threadID;
    volatile long lockCount;
    void Lock(const char* name);
    inline void Unlock()
    {
        lockCount = lockCount - 1;
        if (lockCount == 0)
            threadID = 0;
    }
public:
    void FUN_0040fba0();
};

struct WeightedMapNode
{
    Inner* handler;
    inline bool TryAcquireAndFire(int index, int a, int b)
    {
        int l00 = index + 0;
        int l01 = index + 1;
        int l02 = index + 2;
        int l03 = index + 3;
        int l04 = index + 4;
        int l05 = index + 5;
        int l06 = index + 6;
        int l07 = index + 7;
        int l08 = index + 8;
        int l09 = index + 9;
        int l10 = index + 10;
        int l11 = index + 11;
        int l12 = index + 12;
        int l13 = index + 13;
        int l14 = index + 14;
        int l15 = index + 15;
        int l16 = index + 16;
        int l17 = index + 17;
        int l18 = index + 18;
        int l19 = index + 19;
        int l20 = index + 20;
        int l21 = index + 21;
        int l22 = index + 22;
        int l23 = index + 23;
        int l24 = index + 24;
        int l25 = index + 25;
        int l26 = index + 26;
        int l27 = index + 27;
        int l28 = index + 28;
        int l29 = index + 29;
        int l30 = index + 30;
        int l31 = index + 31;
        int l32 = index + 32;
        int l33 = index + 33;
        int l34 = index + 34;
        int l35 = index + 35;
        return l00 == a + b;
    }
};

inline bool Call(WeightedMapNode* node, int a, int b)
{
    return reinterpret_cast<::Lock5b *>((node))->TryAcquireAndFire(node->handler->v9(a, b), a, b);
}

struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RecursiveSpinLock lock;
    bool FUN_00c3f2b0(int a, int b);
};

// @fnv 0x00c3f2b0
bool Obj::FUN_00c3f2b0(int a, int b)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool result = Call(((::WeightedMapNode *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750())), a, b);
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return result;
}

struct Ref360
{
    void* ptr;
    inline ~Ref360()
    {
        if (ptr)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(ptr));
    }
};

struct Spin360
{
    int owner;
    int count;
    inline void Lock(const char* name)
    {
        unsigned u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15;
        unsigned u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35;
        u0 = 0;
        u1 = 1;
        u2 = 2;
        u3 = 3;
        u4 = 4;
        u5 = 5;
        u6 = 6;
        u7 = 7;
        u8 = 8;
        u9 = 9;
        u10 = 10;
        u11 = 11;
        u12 = 12;
        u13 = 13;
        u14 = 14;
        u15 = 15;
        u16 = 16;
        u17 = 17;
        u18 = 18;
        u19 = 19;
        u20 = 20;
        u21 = 21;
        u22 = 22;
        u23 = 23;
        u24 = 24;
        u25 = 25;
        u26 = 26;
        u27 = 27;
        u28 = 28;
        u29 = 29;
        u30 = 30;
        u31 = 31;
        u32 = 32;
        u33 = 33;
        u34 = 34;
        u35 = 35;
        if (owner == (intptr_t)name)
            return;
        reinterpret_cast<::FUN_0040fbf0_shell *>(this)->FUN_0040fbf0((char *)(name + 1));
    }
    inline void Unlock()
    {
        struct Hold
        {
            int d1;
            int d2;
            int d3;
            Spin360* p;
        } t;
        t.p = this;
        t.p->count -= 1;
        if (t.p->count == 0)
            t.p->owner = 0;
    }
};

struct Helper360
{
};

struct Result360
{
};

struct Obj360
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Spin360 lock;
    char FUN_00c3f360(void* a, Ref360 b);
};

// @fnv 0x00c3f360
char Obj360::FUN_00c3f360(void* a, Ref360 b)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    char r = ((char)(reinterpret_cast<::RemovalMapState *>((((Result360*)((void *)(reinterpret_cast<::FUN_00c3f750_Class *>((((Helper360*)this)))->FUN_00c3f750())))))->FUN_00c40680((int)(intptr_t)(a), (int)(intptr_t)(&b))));
    lock.Unlock();
    return r;
}

struct C3F4C0_Obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual int unk24(int a, int b);
};

struct C3F4C0_Holder : FUN_00c416a0_Class
{
    C3F4C0_Obj* obj;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    uintptr_t m_uSlot14;

    inline bool FUN_00c3fe80(int x, int a, int b, void** out);
    bool Lookup(int a, int b, void** out)
    {
        return reinterpret_cast<::FUN_00c3fe80_Class *>(this)->FUN_00c3fe80(obj->unk24(a, b), a, b, out);
    }
};

inline bool C3F4C0_Holder::FUN_00c3fe80(int x, int a, int b, void** out)
{
    bool ok = FUN_00c416a0(x, a, b);
    if (ok)
    {
        uintptr_t* pSlot1 = &m_uSlot14;
        void** ppVal = (void**)((*pSlot1 & ~(uintptr_t)1) + 8);
        if (*out != *ppVal)
        {
            if (*out)
            {
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(*out));
            }
            *out = *ppVal;
            if (*out)
            {
                char* pRef = (char*)*out;
                InterlockedIncrement((volatile long*)(pRef + 8));
            }
        }
        uintptr_t* pSlot2 = &m_uSlot14;
        uintptr_t uBase = *pSlot2 & ~(uintptr_t)1;
        unsigned int* pFlags = (unsigned int*)(uBase + 12);
        if ((*pFlags & 1u) != 0)
        {
            ok = false;
        }
    }
    int n00, n01, n02, n03, n04, n05, n06, n07, n08, n09;
    int n10, n11, n12, n13, n14, n15, n16, n17, n18, n19;
    int n20, n21, n22, n23, n24, n25, n26, n27, n28, n29;
    int n30, n31, n32, n33, n34, n35, n36, n37, n38, n39;
    int n40, n41, n42, n43, n44, n45, n46, n47, n48, n49;
    int n50;
    n00 = n01 = n02 = n03 = n04 = n05 = n06 = n07 = n08 = n09 = x;
    n10 = n11 = n12 = n13 = n14 = n15 = n16 = n17 = n18 = n19 = a;
    n20 = n21 = n22 = n23 = n24 = n25 = n26 = n27 = n28 = n29 = b;
    n30 = n31 = n32 = n33 = n34 = n35 = n36 = n37 = n38 = n39 = n00 + n10;
    n40 = n41 = n42 = n43 = n44 = n45 = n46 = n47 = n48 = n49 = n20 + n30;
    n50 = n40 + 1;
    return ok && n50 != 0x7fffffff;
}

struct C3F4C0_Cls
{
    bool FUN_00c3f4c0(int a, int b, void** out);
};

// @fnv 0x00c3f4c0
bool C3F4C0_Cls::FUN_00c3f4c0(int a, int b, void** out)
{
    bool res = ((::C3F4C0_Holder *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750()))->Lookup(a, b, out);
    return res;
}

struct FUN_00c3f7a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int* m_pValues10;
    void* FUN_00c3f7a0(int index);
};

class AutoMemContext_00c3f7a0
{
  public:
    AutoMemContext_00c3f7a0(int aeMemoryContext)
    {
        int iOld = ::g_tlsBlock.memoryContext;
        m_iOld = iOld;
        ::g_tlsBlock.memoryContext = aeMemoryContext;
    }
    ~AutoMemContext_00c3f7a0()
    {
        int iSaved = m_iOld;
        ::g_tlsBlock.memoryContext = iSaved;
    }

    int m_iOld;
};

struct Item_00c3f7a0
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    void* m_p10;

    Item_00c3f7a0(void* p0, void* p4, void* p8);
};

// @fnv 0x00c3f7a0
void* FUN_00c3f7a0_Class::FUN_00c3f7a0(int index)
{
    AutoMemContext_00c3f7a0 kContext(6);
    return new Item_00c3f7a0(this, m_pValues10 + index * 2, m_pValues10 + index * 2 + 1);
}

struct ObjectC3
{
    int unk00;
    int unk04;
    long refs;
    inline void AddRef()
    {
        InterlockedIncrement(&refs);
    }
};

struct RefC3
{
    ObjectC3* ptr;
    inline RefC3(ObjectC3* p = 0)
    {
        ptr = p;
        if (ptr)
            ptr->AddRef();
    }
    inline ~RefC3()
    {
        if (ptr)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(ptr));
    }
    inline void Set(RefC3 const& r)
    {
        if (ptr != r.ptr)
        {
            if (ptr)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(ptr));
            ptr = r.ptr;
            if (ptr)
                ptr->AddRef();
        }
    }
};

struct AllocC3
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};

struct NodeC3;

struct TaggedC3
{
    uintptr_t bits;
    TaggedC3()
    {}
    inline TaggedC3(NodeC3* p)
    {
        bits = (uintptr_t)p;
    }
    inline NodeC3* Get() const
    {
        const TaggedC3* self = this;
        return (NodeC3*)(self->bits & ~1u);
    }
    inline void Mark(bool mark)
    {
        TaggedC3* self = this;
        if (mark)
            self->bits |= 1;
        else
            self->bits &= ~1u;
    }
    inline unsigned int Value() const
    {
        const TaggedC3* self = this;
        return self->bits;
    }
    inline bool Marked() const
    {
        return (bits & 1) != 0;
    }
};

struct NodeC3
{
    __int64 key;
    RefC3 obj;
    TaggedC3 next;
    inline NodeC3(__int64 k, RefC3 const& v) : obj(), next(0)
    {
        key = k;
        reinterpret_cast<::FUN_00c41050_Class *>(&(obj))->AssignRef((::S_0044dd60 **)&(v));
    }
};

struct KeyC3
{
    int lo;
    int hi;
};

struct HandlerC3
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
    virtual __int64 Key(KeyC3);
    virtual void v12();
    virtual bool Less(__int64, KeyC3);
    virtual bool Equal(__int64, KeyC3);
    virtual void Done();
    int unk04;
    int unk08;
    struct AtomicC3* buckets;
};

struct ContextC3
{
    int previous;
    inline ContextC3(int old) : previous(old)
    {
        ::g_tlsBlock.memoryContext = 6;
    }
    inline static void Set(int value)
    {
        ::g_tlsBlock.memoryContext = value;
    }
    inline ~ContextC3()
    {
        Set(previous);
    }
};

struct AtomicC3
{
    long bits;
    inline unsigned int Value() const
    {
        return bits;
    }
    inline bool Compare(unsigned int desired, unsigned int expected)
    {
        bool success = InterlockedCompareExchange((long volatile*)this, desired, expected) == expected;
        return success;
    }
};

struct SearchC3
{
    HandlerC3* handler;
    void** out1;
    void** out2;
    void** out3;
    AtomicC3* link;
    TaggedC3 current;
    TaggedC3 observed;
    void FUN_00c41f40(NodeC3*);
    inline bool FUN_00c416a0(int index, KeyC3 key)
    {
        AtomicC3* start = &handler->buckets[index];
        while (true)
        {
            bool restart = false;
            link = start;
            current.bits = link->bits;
            *out2 = current.Get();
            TaggedC3 safe(current.Get());
            reinterpret_cast<::FUN_0044e010_class *>(&(safe))->FUN_0044e010(false);
            if (link->bits != safe.Value())
                continue;
            while (true)
            {
                if (!current.Get())
                    return false;
                observed = current.Get()->next;
                *out1 = observed.Get();
                if (observed.Value() != current.Get()->next.Value())
                {
                    restart = true;
                    break;
                }
                __int64 nodeKey = current.Get()->key;
                TaggedC3 expected(current.Get());
                expected.Mark(false);
                if (link->Value() != expected.Value())
                {
                    restart = true;
                    break;
                }
                if (!observed.Marked())
                {
                    if (handler->Less(nodeKey, key))
                        return handler->Equal(nodeKey, key);
                    link = (AtomicC3*)&current.Get()->next;
                    *out3 = current.Get();
                }
                else
                {
                    TaggedC3 desired(observed.Get());
                    desired.Mark(false);
                    if (link->Compare(desired.Value(), expected.Value()))
                        FUN_00c41f40(current.Get());
                    else
                    {
                        restart = true;
                        break;
                    }
                }
                current = observed;
                *out2 = observed.Get();
            }
            if (restart)
                continue;
        }
    }
    bool FUN_00c3ffb0(intptr_t index, KeyC3 key, RefC3* value, bool replace);
};

// @fnv 0x00c3ffb0
bool SearchC3::FUN_00c3ffb0(intptr_t index, KeyC3 key, RefC3* value, bool replace)
{
    ContextC3 context4(::g_tlsBlock.memoryContext);
    bool result2 = true;
    NodeC3* node7 = 0;
    while (true)
    {
        if (FUN_00c416a0(index, key))
        {
            delete node7;
            if (replace)
                current.Get()->obj.Set(*value);
            else
                result2 = false;
            break;
        }
        if (!node7)
            node7 = new NodeC3(handler->Key(key), *value);
        TaggedC3 next4(current.Get());
        reinterpret_cast<::FUN_0044e010_class *>(&(next4))->FUN_0044e010(false);
        TaggedC3 desired5(node7);
        desired5.Mark(false);
        node7->next = next4;
        if (link->Compare(desired5.Value(), next4.Value()))
        {
            handler->Done();
            break;
        }
    }
    *out1 = 0;
    *out2 = 0;
    *out3 = 0;
    return result2;
}

namespace fnv_00c35c10 {
struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}

    NiPoint3 operator+(const NiPoint3& other) const
    {
        return NiPoint3(x + other.x, y + other.y, z + other.z);
    }
    NiPoint3 operator-(const NiPoint3& other) const
    {
        return NiPoint3(x - other.x, y - other.y, z - other.z);
    }
};
struct NiPoint3b : NiPoint3
{
    NiPoint3b(float a, float b, float c) : NiPoint3(a, b, c)
    {}
};
struct M_004b4500
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3b FUN_004b4500(const NiPoint3* p)
    {
        return NiPoint3b(m00 * p->x + m01 * p->y + m02 * p->z, m10 * p->x + m11 * p->y + m12 * p->z,
                         m20 * p->x + m21 * p->y + m22 * p->z);
    }
};
struct Result
{
    NiPoint3 p0, p1, p2, p3;
};
struct Target
{
    int unk00, unk04;
    NiPoint3 center;
    float width, height;
    M_004b4500 matrix;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unkA0, unkA4;
    Result cached;
    int unkD8, unkDC, unkE0;
    bool dirty;
    void FUN_00c35c10(Result* out);
};
// @fnv 0x00c35c10
void Target::FUN_00c35c10(Result* out)
{
    if (!dirty)
    {
        memcpy(out, &cached, 48);
        return;
    }
    NiPoint3 horizontal(width, 0.0f, 0.0f);
    NiPoint3 vertical(0.0f, 0.0f, height);
    horizontal = matrix.FUN_004b4500(&horizontal);
    vertical = matrix.FUN_004b4500(&vertical);
    out->p3 = center - horizontal + vertical;
    out->p2 = center - horizontal - vertical;
    out->p1 = center + horizontal - vertical;
    out->p0 = center + horizontal + vertical;
    memcpy(&cached, out, 48);
    dirty = false;
}
}

// namespace fnv_00c35c10

long __cdecl FUN_004019a0(unsigned int& value);

struct RefObj_c3d4
{
    virtual ~RefObj_c3d4();
    int unk04;
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        unsigned int ui = FUN_004019a0(m_uiRefCount);
        if (ui == 0)
            DeleteThis();
    }
    void DeleteThis()
    {
        delete this;
    }
};

template <class T> class NiPointerC3D4
{
  public:
    NiPointerC3D4(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointerC3D4& operator=(const NiPointerC3D4& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

__forceinline void ConstructC3D4(NiPointerC3D4<RefObj_c3d4>* pkData, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        NiPointerC3D4<RefObj_c3d4>* pkNew = new (&pkData[i]) NiPointerC3D4<RefObj_c3d4>;
}

struct PtrArray_c3d4
{
    void* m_vtbl;
    NiPointerC3D4<RefObj_c3d4>* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMax;
    unsigned int FUN_00c3d6c0();
    unsigned int FUN_00c3d4f0(const NiPointerC3D4<RefObj_c3d4>& element);
};

// @fnv 0x00c3d4f0
unsigned int PtrArray_c3d4::FUN_00c3d4f0(const NiPointerC3D4<RefObj_c3d4>& element)
{
    unsigned int uiIndex = ((unsigned int)(reinterpret_cast<::ArrayC3D6C0 *>(this)->FUN_00c3d6c0()));
    ConstructC3D4(m_pBase + uiIndex, 1);
    m_pBase[uiIndex] = element;
    return uiIndex;
}

struct FUN_00c39c80_obj
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
    virtual int v94(int a);
    virtual int v98(int a);
};

struct FUN_00c39c80_holder
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c39c80_obj* m_0c;
    FUN_00c39c80_obj* GetObj()
    {
        FUN_00c39c80_obj* a = m_0c;
        return a;
    }
};

struct FUN_00c39c80_node
{
    FUN_00c39c80_node* m_00;
    int unk04;
    FUN_00c39c80_holder* m_08;
};

inline FUN_00c39c80_holder* const& GetNext(FUN_00c39c80_node*& pos)
{
    FUN_00c39c80_holder* const& e = pos->m_08;
    pos = pos->m_00;
    return e;
}

struct FUN_00c39c80_cls
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
    FUN_00c39c80_holder* m_ac;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FUN_00c39c80_node* m_d0;
    int unkD4;
    int m_d8;
    FUN_00c39c80_node* GetHead()
    {
        FUN_00c39c80_node* first = m_d0;
        return first;
    }
    int FUN_00c39c80(int a1);
};

// @fnv 0x00c39c80
int FUN_00c39c80_cls::FUN_00c39c80(int a1)
{
    int res;
    FUN_00c39c80_node* cur;
    FUN_00c39c80_holder* group;
    int r2;
    FUN_00c39c80_holder* owner;
    owner = m_ac;
    res = owner->GetObj()->v94(a1);
    if (res != 1 && !(bool)(int)(m_d8 == 0))
    {
        cur = GetHead();
        while (res != 1 && cur != 0)
        {
            group = GetNext(cur);
            r2 = group->GetObj()->v94(a1);
            if (r2 != 0)
            {
                res = r2;
            }
        }
    }
    return res;
}

static __forceinline void Dead34()
{
    int aiD[34];
}

struct F1f0Lock
{
    unsigned int m_pOwnerObject;
    unsigned int m_lLockCount;
    void Unlock()
    {
        m_lLockCount = m_lLockCount - 1;
        if (m_lLockCount == 0)
            m_pOwnerObject = 0;
    }
};

struct F1f0Inner
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
    virtual void* v24(int a, int b, int c, int d, int e, bool f);
};

struct F1f0Obj
{
    F1f0Inner* m_00;
    bool Test(int a1, int a2, int a3, bool a4)
    {
        return reinterpret_cast<::SearchC3 *>(this)->FUN_00c3ffb0((intptr_t)(m_00->v24(a1, a2, a1, a2, a3, a4)), {}, {}, {});
    }
};

struct F1f0Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    F1f0Lock m_lock;
    bool FUN_00c3f1f0(int a1, int a2, int a3, bool a4);
};

// @fnv 0x00c3f1f0
bool F1f0Cls::FUN_00c3f1f0(int a1, int a2, int a3, bool a4)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_lock))->FUN_0040fbf0((char *)(0));
    Dead34();
    bool r = ((::F1f0Obj *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750()))->Test(a1, a2, a3, a4);
    m_lock.Unlock();
    return r;
}

unsigned int __cdecl FUN_0040fc90();


struct SpinLockS
{
    unsigned int owningThread;
    unsigned int lockCount;
    void FUN_0040fbf0(const char* name)
    {
        unsigned int threadID = FUN_0040fc90();
        if (owningThread == threadID)
        {
            ++lockCount;
            return;
        }
        unsigned int spinCount = 0;
        while (FUN_0043b460(reinterpret_cast<long volatile*>(&owningThread), 0, (long)threadID))
        {
            if (++spinCount > 10000)
                ::FUN_0040fca0(1);
            else
                ::FUN_0040fca0(0);
        }
        FUN_0040fbe0();
        lockCount = 1;
    }
    void Unlock()
    {
        if (--lockCount == 0)
            owningThread = 0;
    }
};

struct WorkerS
{
};

struct ManagerS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SpinLockS lock;
    bool FUN_00c3f430(int a, int b, intptr_t c, int d, unsigned char e);
};

static __forceinline void Dead35()
{
    int aiD[35];
}

// @fnv 0x00c3f430
bool ManagerS::FUN_00c3f430(int a, int b, intptr_t c, int d, unsigned char e)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool result = reinterpret_cast<::SearchC3 *>((((::WorkerS *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750()))))->FUN_00c3ffb0(a, (::KeyC3)(b), (::RefC3 *)(c), d);
    Dead35();
    lock.Unlock();
    return result;
}

namespace fnv_00c3f8c0 {
class SpawnedBase
{
  public:
    virtual void unk00();
    virtual ~SpawnedBase()
    {}
    int unk04;
};

class FUN_00c3f8c0 : public SpawnedBase
{
  public:
    virtual ~FUN_00c3f8c0();
    int unk08;
    int unk0c;
};

// @fnv 0x00c3f8c0
FUN_00c3f8c0::~FUN_00c3f8c0()
{
    reinterpret_cast<::NodeMap *>((this))->FUN_00c40b70(1);
    {
        intptr_t unk10 = this->unk0c;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::DynamicMemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060((void*)unk10);
    }
    {
        int unk18 = this->unk04;
        intptr_t unk14 = unk18;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::DynamicMemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060((void*)unk14);
    }
}
}

// namespace fnv_00c3f8c0

struct FUN_0045c620
{
    NiCamera plane0;
    NiCamera plane1;
    NiCamera plane2;
    NiCamera plane3;
    NiCamera plane4;
    NiCamera plane5;
    unsigned int active;
    FUN_0045c620();
};

struct MatrixC358
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    Point FUN_004b4500(const Point&);
};

struct OccluderC358
{
    int unk00;
    int unk04;
    Point center;
    float halfWidth;
    float halfHeight;
    MatrixC358 rotation;
    int unk40;
    FUN_00a699d0s cached;
    Point corner0;
    Point corner1;
    Point corner2;
    Point corner3;
    Point last;
    bool cornersDirty;
    bool dirty;
    unsigned char disabled0;
    unsigned char disabled1;
    unsigned char disabled2;
    unsigned char disabled3;
    unsigned char unkEA;
    inline void FUN_00c35c10(Point* out)
    {
        if (!cornersDirty)
        {
            memcpy(out, &corner0, 48);
            return;
        }
        Point horizontal(halfWidth, 0, 0);
        Point vertical(0, 0, halfHeight);
        Point c0, c1, c2, c3;
        horizontal = rotation.FUN_004b4500(horizontal);
        vertical = rotation.FUN_004b4500(vertical);
        c3 = center - horizontal + vertical;
        c2 = center - horizontal - vertical;
        c1 = center + horizontal - vertical;
        c0 = center + horizontal + vertical;
        out[3] = c3;
        out[2] = c2;
        out[1] = c1;
        out[0] = c0;
        memcpy(&corner0, out, 48);
        cornersDirty = false;
    }
    bool FUN_00c358a0(Point point);
};

// @fnv 0x00c358a0
bool OccluderC358::FUN_00c358a0(Point point)
{
    if (unkEA != 0)
        return true;
    Point verts[4];
    FUN_0045c620 frustum;
    ((Builder*)this)->FUN_00c33870(point, (FUN_00a699d0s*)&frustum);
    reinterpret_cast<::Builder *>(this)->FUN_00c35c10(verts);
    FUN_00a699d0 plane(verts[0], verts[1], verts[2]);
    if (plane.ClassifyPoint(&point) != 2)
        return false;
    else
        return true;
}

// Sets the vftable to DAT_010c14fc and calls FUN_00c3d980 with 1.
// @fnv 0x00c3d930
void FUN_00c3d930_Class::FUN_00c3d930()
{
    char buf[0x18];
    vftable = &DAT_010c14fc;
    reinterpret_cast<::C3D980Cls *>(this)->FUN_00c3d980(1);
}

// Calls FUN_00c39770, then deletes this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c3a140
void* FUN_00c3a140_Class::FUN_00c3a140(unsigned int flags)
{
    reinterpret_cast<::FUN_00c39770 *>(this)->FUN_00c39770::~FUN_00c39770();
    if (flags & 1)
        operator delete(this, 0xec);
    return this;
}

// Calls FUN_00c3bab0, then deletes this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c3ba80
void* FUN_00c3ba80_Class::FUN_00c3ba80(unsigned int flags)
{
    int x, y, z;
    reinterpret_cast<::fnv_00c3bab0::FUN_00c3bab0 *>(this)->fnv_00c3bab0::FUN_00c3bab0::~FUN_00c3bab0();
    if (flags & 1)
        operator delete(this, 0x18);
    return this;
}

// @fnv 0x00c347d0
bool FUN_00c347d0_cls::FUN_00c347d0(FUN_00c347d0_Obj* obj)
{
    FUN_00c347d0_Scratch b1;
    FUN_00c347d0_Elem res[4];
    int tt = 4;
    FUN_00c347d0_Elem* g1 = res;
    while (--tt >= 0)
    {
        ++g1;
    }
    int lst;
    int val;
    reinterpret_cast<::Builder *>(this)->FUN_00c35c10((::Point *)(res));
    for (lst = 0; lst < 6; lst++)
    {
        if ((bool)((1u << lst) & obj->m_uiMask))
        {
            for (val = 0; val < 4; val++)
            {
                if (reinterpret_cast<::NiCamera *>(&(obj->m_slot[lst]))->ClassifyPoint((const ::NiPoint3 *)(::FUN_00c347d0_Elem *)(&res[val])) == 2)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// Scalar deleting destructor.
// Destructs the object, frees it via g_kC3D3E0Heap when uiFlags has bit 0 set, and returns this.
// @fnv 0x00c3d3e0
C3D3E0Palette* C3D3E0Palette::FUN_00c3d3e0(unsigned int uiFlags)
{
    reinterpret_cast<::FUN_00c3c620 *>((this))->FUN_00c3c620::~FUN_00c3c620();
    if (uiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::C3D3E0Heap *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

// If a is non-zero, forwards it to m_c0.FUN_00c3a250.
// @fnv 0x00c39ad0
void FUN_00c39ad0_Class::FUN_00c39ad0(int a)
{
    int pad0[10];
    int pad1[9];
    if (a)
    {
        reinterpret_cast<::List250 *>(&(m_c0))->FUN_00c3a250((void *&)(a));
    }
}

#include "generated/data/staging/blk_00c20000_od.inc"
#include "generated/data/staging/blk_00c20000_od_ob1_variant.inc"
