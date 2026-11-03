
// src/staging/blk_00b00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include "runtime/crt.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aff090_cls.h"
#include "fnv/decl/FUN_00b0cff0_class.h"
#include "fnv/decl/FileNameComponents.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Reader078.h"
#include "fnv/decl/S_008785e0.h"
#include "fnv/decl/S_af9.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/WideString.h"
#include "fnv/decl/fnv_00afac90__S_af9.h"
#include "fnv/decl/xlenb0f__BxVecBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_00b10000.h"
#include "fnv/symbols_00b12000.h"
#include "fnv/symbols_00b16000.h"
#include "fnv/symbols_00b17000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_010a4000.h"
#include "fnv/symbols_01140000.h"
#include "fnv/symbols_011f6000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/FUN_00b12790_class.h"
#include "fnv/decl/FUN_00b16890_It.h"
#include "fnv/decl/FUN_00b2e330_It.h"
#include "fnv/decl/FUN_00b37ad0_class.h"
#include "fnv/decl/FUN_00b3f130_shell.h"
#include "fnv/decl/IndexSet.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_00b13c10__Host.h"
#include "fnv/decl/fnv_00b1fca0__tidyb1f__T1Vector.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_00b13000.h"
#include "fnv/symbols_00b23000.h"
#include "fnv/symbols_00b36000.h"
#include "fnv/symbols_011f8000.h"

struct FUN_00b007d0_shell
{
    int FUN_00b007d0();
};

struct FUN_00b00860_shell
{
    void FUN_00b00860();
};

// @fnv 0x00b00860
void FUN_00b00860_shell::FUN_00b00860()
{
    ((FUN_00b007d0_shell*)this)->FUN_00b007d0();
}

extern int DAT_010a47b3;

struct FUN_00b008e0_class
{
    int* FUN_00b008e0();
};

// @fnv 0x00b008e0
int* FUN_00b008e0_class::FUN_00b008e0()
{
    return &DAT_010a47b3;
}

struct FUN_00b00950
{
    void DoWork();
};

// @fnv 0x00b00950
void FUN_00b00950::DoWork()
{
    reinterpret_cast<::FUN_00aff090_cls *>(this)->CloseHandleWrapper();
}

struct FUN_00b01bc0_class
{
    bool IsFlag2Clear(int flags, int unused);
};

// @fnv 0x00b01bc0
bool FUN_00b01bc0_class::IsFlag2Clear(int flags, int unused)
{
    return (flags & 2) == 0;
}

struct FUN_00b01be0_Class
{
    bool IsFlag4Clear(unsigned int flags, unsigned int unused);
};

// @fnv 0x00b01be0
bool FUN_00b01be0_Class::IsFlag4Clear(unsigned int flags, unsigned int unused)
{
    return !(flags & 4);
}

extern int DAT_010a48e8;

struct FUN_00b029a0_class
{
    void FUN_00b029a0();
};

// @fnv 0x00b029a0
void FUN_00b029a0_class::FUN_00b029a0()
{
    *(int**)(this) = &DAT_010a48e8;
}

struct FUN_00b18320_Class
{
    char GetByteAtOffset4C();
};

// @fnv 0x00b18320
char FUN_00b18320_Class::GetByteAtOffset4C()
{
    return ((const char*)this)[0x4c];
}

struct FUN_00b008f0_class
{
    int* FUN_00b008f0();
};

// @fnv 0x00b008f0
int* FUN_00b008f0_class::FUN_00b008f0()
{
    return 0;
}

extern int DAT_011f8250;
// @fnv 0x00b00970
void FUN_00b00970(int value)
{
    DAT_011f8250 = value;
}

extern int DAT_011f8af4;
extern void* DAT_011f8b38[16];
struct TaskletManager
{
    int* FUN_00b00a00();
};
// Appends param_1 to the DAT_011f8b38 queue when the manager's field at offset 8 is zero and the queue count is below 16, returning 1 on success and 0 otherwise.
// @fnv 0x00b00da0
char QueueTasklet(void* param_1)
{
    int* obj = (int*)((char*)&(*(::TaskletManager *)&(::GetTaskletManager())) + 8);
    char result;
    if (*obj == 0 && DAT_011f8af4 < 16)
    {
        DAT_011f8b38[DAT_011f8af4] = param_1;
        DAT_011f8af4++;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

struct FUN_00b12af0_shell
{
};
struct FUN_00b130a0
{
    float a, b, c;
    float d, e, f;
    FUN_00b130a0();
};
// Zeroes the six float members a-f and calls FUN_00b12af0 on the object at offset 0x1c.
// @fnv 0x00b130a0
FUN_00b130a0::FUN_00b130a0()
{
    c = 0.0f;
    b = 0.0f;
    a = 0.0f;
    float* p = &d;
    p[2] = 0.0f;
    p[1] = 0.0f;
    p[0] = 0.0f;
    ::FUN_00b12af0((::FUN_00b12af0_shell *)(((FUN_00b12af0_shell*)((char*)this + 0x1c))));
}

struct FUN_00b0cf90_class
{
    float x, y, z;
    float* AddVector(float* pDest, const float* pSource);
};
// Adds the object's x, y and z to the three components of pSource and writes the sums into pDest, returning pDest.
// @fnv 0x00b0cf90
float* FUN_00b0cf90_class::AddVector(float* pDest, const float* pSource)
{
    float f7 = pSource[0] + x;
    float f1 = pSource[1] + y;
    float f2 = pSource[2] + z;
    pDest[0] = f7;
    pDest[1] = f1;
    pDest[2] = f2;
    return pDest;
}

struct FUN_00afeac0_shell
{
    int OpenFile(int arg);
};

struct FUN_00b00900
{
    int m0;
    int m4;
    int m8;
    char mc;
    int OpenFile(int arg);
    FUN_00b00900(const char* a, int b, int c, char d);
};

// Initialises the object: stores b, c and d into m4, m8 and mc, then sets m0 from OpenFile(a).
// @fnv 0x00b00900
FUN_00b00900::FUN_00b00900(const char* aiValue, int aiSecond, int aiThird, char d)
{
    m0 = 0;
    m4 = aiSecond;
    m8 = aiThird;
    mc = d;
    m0 = reinterpret_cast<::S_008785e0 *>(this)->OpenFile(aiValue);
}

struct FUN_00b00cf0_vt
{
    virtual void vfn_0();
    virtual void vfn_1();
};
struct FUN_00b00cf0_shell
{
    void CallVirtualOnAllEntries();
};
// Iterates DAT_011f8b38 up to DAT_011f8af4 and calls vfn_1 on each non-null entry.
// @fnv 0x00b00cf0
void FUN_00b00cf0_shell::CallVirtualOnAllEntries()
{
    for (int i = 0; i < DAT_011f8af4; ++i)
    {
        if (DAT_011f8b38[i])
            ((FUN_00b00cf0_vt*)DAT_011f8b38[i])->vfn_1();
    }
}

struct FUN_00b12b50_class
{
    float* TransformVector(float* dst, const float* src) const;
};

// Multiplies a 3x3 matrix stored in this by a 3-component vector src and writes the result to dst, returning dst.
// @fnv 0x00b12b50
float* FUN_00b12b50_class::TransformVector(float* dst, const float* src) const
{
    float t0 = src[2] * ((const float*)this)[2] + (src[1] * ((const float*)this)[1] + src[0] * ((const float*)this)[0]);
    float t1 = src[2] * ((const float*)this)[5] + (src[1] * ((const float*)this)[4] + src[0] * ((const float*)this)[3]);
    float t2 = src[2] * ((const float*)this)[8] + (src[1] * ((const float*)this)[7] + src[0] * ((const float*)this)[6]);
    dst[0] = t0;
    dst[1] = t1;
    dst[2] = t2;
    return dst;
}

struct FUN_00b008b0_t
{
    int m0;
    FUN_00b008b0_t* FUN_00b008b0(int v);
};

// @fnv 0x00b008b0
FUN_00b008b0_t* FUN_00b008b0_t::FUN_00b008b0(int aiValue)
{
    m0 = aiValue;
    return this;
}

extern int DAT_011f8af0;
extern void* DAT_011f8af8[];

struct FUN_00b00c90_vt
{
    virtual void vfn_0();
    virtual void vfn_1();
};

// Iterates DAT_011f8af8 up to DAT_011f8af0 and calls vfn_1 on each non-null entry.
// @fnv 0x00b00c90
void CallVfn1OnAllEntries(void* param_1)
{
    int iIndex;
    for (iIndex = 0; iIndex < DAT_011f8af0; iIndex = iIndex + 1)
    {
        if (DAT_011f8af8[iIndex] != 0)
        {
            ((FUN_00b00c90_vt*)DAT_011f8af8[iIndex])->vfn_1();
        }
    }
}

extern int DAT_011f8af0;
extern void* DAT_011f8af8[16];

// @fnv 0x00b00d50
char FUN_00b00d50(void* param_1)
{
    char local2;
    int* piVar2 = (int*)((char*)&(*(::TaskletManager *)&(::GetTaskletManager())) + 8);
    if (*piVar2 == 0 && DAT_011f8af0 < 0x10)
    {
        DAT_011f8af8[DAT_011f8af0] = param_1;
        DAT_011f8af0 = DAT_011f8af0 + 1;
        local2 = 1;
    }
    else
    {
        local2 = 0;
    }
    return local2;
}

struct FUN_00b01020
{
    virtual ~FUN_00b01020();
};
struct FUN_00b01c20 : public FUN_00b01020
{
    virtual ~FUN_00b01c20();
};
// @fnv 0x00b01c20
FUN_00b01c20::~FUN_00b01c20()
{}

extern int DAT_010a4880;
extern int DAT_010a48ac;

struct FUN_00b01f00_class
{
    const void* vtable;
    char pad04[0x8];
    HANDLE threadHandle;
    char pad10[0x44];
    CRITICAL_SECTION lock;
    char pad6c[0x204];
    HANDLE eventHandle;
    void DestroyAndFreeLibraries();
};

// @fnv 0x00b01f00
void FUN_00b01f00_class::DestroyAndFreeLibraries()
{
    vtable = &DAT_010a4880;
    CloseHandle(eventHandle);
    DeleteCriticalSection(&lock);
    vtable = &DAT_010a48ac;
    CloseHandle(threadHandle);
}

struct MemoryManager
{
};
struct FUN_00b02970
{
    void* DeleteThis(unsigned int flags);
    void FUN_00b02860();
};

namespace fnv_00b0e7f0 {
struct MemoryManager
{
};


struct FUN_00b0e7f0_class
{
    void* unknown[3];
    int* m_pBuffer;
    int* m_nSize;
    int* m_nCapacity;

    void Clear();
};

// Deallocates m_pBuffer through the memory manager if set, then resets m_pBuffer, m_nSize and m_nCapacity to zero.
// @fnv 0x00b0e7f0
void FUN_00b0e7f0_class::Clear()
{
    struct Locals
    {
        int count;
        void* buffer;
        int* first;
        int* second;
        int* copiedFirst;
        int* copiedSecond;
        char padding1;
        char padding2;
        char source;
        char destination;
    } locals;

    if (m_pBuffer)
    {
        locals.first = m_nSize;
        locals.second = m_pBuffer;
        locals.copiedFirst = locals.first;
        locals.copiedSecond = locals.second;
        locals.destination = locals.source;
        locals.count = (int)(m_nCapacity - m_pBuffer);
        locals.buffer = m_pBuffer;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00b0e7f0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(locals.buffer);
    }

    m_pBuffer = 0;
    m_nSize = 0;
    m_nCapacity = 0;
}
}  // namespace fnv_00b0e7f0

class FUN_00b004d0_cls
{
  public:
    void FUN_00b004d0();
};

// @fnv 0x00b004d0
void FUN_00b004d0_cls::FUN_00b004d0()
{}

struct FUN_00b00820_tail
{
    unsigned int pendingState;
    unsigned int otherState;
    unsigned __int64 sequence;
};
struct FUN_00b00820_shell
{
    FUN_00b00820_shell* FUN_00b00820(const char* value);
};

// Clears pendingState and sequence at offset 0x248, calls FUN_00b006b0 with value, and returns this.
// @fnv 0x00b00820
FUN_00b00820_shell* FUN_00b00820_shell::FUN_00b00820(const char* value)
{
    reinterpret_cast<FUN_00b00820_tail*>(reinterpret_cast<char*>(this) + 0x248)->pendingState = 0;
    reinterpret_cast<FUN_00b00820_tail*>(reinterpret_cast<char*>(this) + 0x248)->sequence = 0;
    reinterpret_cast<::FileNameComponents *>(this)->SetFullPath(value);
    return this;
}

struct FUN_00b00880_cls
{
    int unk00;
    unsigned char m_bFlag;
    FUN_00b00880_cls* ClearFlag();
};

// @fnv 0x00b00880
FUN_00b00880_cls* FUN_00b00880_cls::ClearFlag()
{
    m_bFlag = 0;
    return this;
}

struct FUN_00b008a0_cls
{
    int unk00;
    void FUN_00b008a0();
};

// @fnv 0x00b008a0
void FUN_00b008a0_cls::FUN_00b008a0()
{}

class BSWin32TaskletManager
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual bool vf10(int& value);

    unsigned char unk04;

    bool GetTaskletValue(void* result);
};

inline void BSWin32TaskletManager::vf00()
{}
inline void BSWin32TaskletManager::vf04()
{}
inline void BSWin32TaskletManager::vf08()
{}
inline void BSWin32TaskletManager::vf0c()
{}
inline bool BSWin32TaskletManager::vf10(int&)
{
    return false;
}

// If unk04 is set, calls vf10 to obtain a value and stores it through result, returning the call's success; otherwise stores 0 and returns false.
// @fnv 0x00b00a80
bool BSWin32TaskletManager::GetTaskletValue(void* result)
{
    bool operationSucceeded;

    {
        int outputValue;

        {
            unsigned char enabled = this->unk04;

            {
                int copiedValue;

                if (enabled != 0)
                {
                    operationSucceeded = this->vf10(outputValue);
                    copiedValue = outputValue;
                    *static_cast<int*>(result) = copiedValue;
                }
                else
                {
                    operationSucceeded = false;
                    *static_cast<int*>(result) = 0;
                }
            }
        }
    }

    return operationSucceeded;
}

struct FUN_00b00ae0_class
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual bool virtual5(void* value);
    bool enabled;
    bool FUN_00b00ae0(void** value);
};
// Returns true only if enabled is set and the pointed-to value is non-null and passes virtual5.
// @fnv 0x00b00ae0
bool FUN_00b00ae0_class::FUN_00b00ae0(void** value)
{
    bool flag = enabled;
    {
        void* current;
        {
            void* payload;
            return (flag && (current = *value)) ? virtual5(payload = *value) : false;
        }
    }
}

class FUN_00b00b40_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual bool v18(void* a, void* b, bool c);
    bool m_04;
    bool TryProcessPair(void** a, void** b, bool c);
};

// @fnv 0x00b00b40
bool FUN_00b00b40_cls::TryProcessPair(void** apFirst, void** b, bool abFlag)
{
    bool flagTmp = m_04;
    void* p4;
    void* q;
    void* x7;
    void* y4;
    return (flagTmp && (p4 = *apFirst) != 0 && (q = b[1]) != 0) ? (x7 = b[1], y4 = *apFirst, v18(y4, x7, abFlag))
                                                                : false;
}

class B00C20Item
{
  public:
    virtual void vfn00();
    virtual void Shutdown(int iMode);

    bool m_bShutDown;
};

class B00C20Pool
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void FreeItem(B00C20Item* pkItem);

    void ReleaseItem(B00C20Item*& rpkItem);
};

// If rpkItem is non-null, shuts it down when not already shut down, frees it via FreeItem, and clears the reference.
// @fnv 0x00b00c20
void B00C20Pool::ReleaseItem(B00C20Item*& rpkItem)
{
    B00C20Item* pkItem_ = rpkItem;
    bool bShutDown2;
    B00C20Item* pkFree;
    if (pkItem_)
    {
        if (rpkItem)
        {
            bShutDown2 = rpkItem->m_bShutDown;
            if (!bShutDown2)
                rpkItem->Shutdown(0);
        }
        pkFree = rpkItem;
        FreeItem(pkFree);
        rpkItem = 0;
    }
}


struct FUN_00b00df0_sub
{
    long m_00;
    void* m_04;
};

class FUN_00b00df0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    FUN_00b00df0_sub m_08;
    void ReleaseAndSignal();
};

// Releases the semaphore in m_08, increments its counter, sets m_05 to 1, then calls vfn_9.
// @fnv 0x00b00df0
void FUN_00b00df0_cls::ReleaseAndSignal()
{
    FUN_00b00df0_sub* p = &m_08;
    ReleaseSemaphore(p->m_04, 1, 0);
    InterlockedIncrement(&p->m_00);
    m_05 = 1;
    vfn_9();
}


extern int DAT_0106c800;
extern int DAT_0106c814;

struct FUN_00b00ec0
{
    int unk00;
    int unk04;
    int m_08;
    int unk0c;
    long m_10;

    ~FUN_00b00ec0() throw();
};

// @fnv 0x00b00ec0
FUN_00b00ec0::~FUN_00b00ec0() throw()
{
    *(void* volatile*)this = (void*)&DAT_0106c800;
    while (InterlockedCompareExchange(&m_10, 1, 0) != 0)
    {
        Sleep(0);
    }
    if (m_08 != 0)
    {
        m_08 = 0;
    }
    m_10 = 0;
    *(void* volatile*)this = (void*)&DAT_0106c814;
}


struct FUN_00b01510_cls
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual const char* vfn_6();
    bool FUN_00b01510(int arg);
};

// @fnv 0x00b01510
bool FUN_00b01510_cls::FUN_00b01510(int aiUnused)
{
    WIN32_FIND_DATAA data;
    HANDLE handle = FindFirstFileA(vfn_6(), &data);
    bool ok;
    if (handle == INVALID_HANDLE_VALUE)
    {
        ok = false;
    }
    else
    {
        FindClose(handle);
        ok = true;
    }
    return ok;
}

extern "C" void(* fnv_EnterCriticalSection)(void* pkSection);
extern "C" void(* fnv_LeaveCriticalSection)(void* pkSection);

struct B02670Semaphore
{
    long m_lCount;
    void* m_pSemaphore;
};

struct B02670CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B02670Task
{
  public:
    int unk00;
    int unk04;
    B02670Semaphore m_kCompletionSemaphore;
    int unk10;
    B02670CriticalSection m_kLock;
    unsigned char unk2C;
    bool m_bCancelled;
    unsigned char unk2E;
    unsigned char unk2F;
    int unk30;
    int m_iTarget;
    int m_iCompleted;

    void CompleteTask();
};

// Increments m_iCompleted under the lock; if not cancelled and m_iCompleted equals m_iTarget, releases the semaphore and increments its count.
// @fnv 0x00b02670
void B02670Task::CompleteTask()
{
    fnv_EnterCriticalSection(&m_kLock);
    m_iCompleted++;
    bool bSignal = !m_bCancelled && m_iCompleted == m_iTarget;
    fnv_LeaveCriticalSection(&m_kLock);
    if (bSignal)
    {
        B02670Semaphore* pkSemaphore = &m_kCompletionSemaphore;
        ReleaseSemaphore(pkSemaphore->m_pSemaphore, 1, 0);
        InterlockedIncrement(&pkSemaphore->m_lCount);
    }
}


struct FUN_00b0e510_pair
{
    uintptr_t m_00;
    uintptr_t m_04;
    unsigned char FUN_00b10490(FUN_00b0e510_pair* other);
};

struct FUN_00b0e510_tmp
{
    uintptr_t unk00;
    uintptr_t unk04;
    uintptr_t unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned int unk10;
};

struct FUN_00b0e510_big
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

class FUN_00b0e510_cls
{
  public:
    uintptr_t m_00;
    uintptr_t m_04;
    uintptr_t m_08;
    uintptr_t m_0c;
    uintptr_t m_10;

    FUN_00b0e510_pair* FUN_00b0e510(FUN_00b0e510_pair* out, uintptr_t a0, uintptr_t a1, uintptr_t a2,
                                    uintptr_t a3);
};


struct FUN_00b10490_class
{
    int first;
    int second;
    bool FUN_00b10490(const FUN_00b10490_class* rhs);
};
// @fnv 0x00b0e510
FUN_00b0e510_pair* FUN_00b0e510_cls::FUN_00b0e510(FUN_00b0e510_pair* out, uintptr_t a0, uintptr_t a1,
                                                  uintptr_t a2, uintptr_t a3)
{
    FUN_00b0e510_pair lo;
    FUN_00b0e510_pair hi;
    uintptr_t r;
    FUN_00b0e510_tmp big;
    FUN_00b0e510_big t;

    lo.m_00 = 0;
    if (this == 0 || this->m_0c > a1 || a1 > this->m_10)
    {
        std::abort();
    }
    do
    {
    } while (0);
    lo.m_00 = this->m_00;
    lo.m_04 = a1;
    hi.m_00 = 0;
    if (this == 0 || this->m_0c > a3 || a3 > this->m_10)
    {
        std::abort();
    }
    do
    {
    } while (0);
    hi.m_00 = this->m_00;
    hi.m_04 = a3;
    if (((unsigned char)(reinterpret_cast<::FUN_00b10490_class *>(&(lo))->FUN_00b10490((const ::FUN_00b10490_class *)(::FUN_00b0e510_pair *)(&hi)))) != 0)
    {
        r = ((uintptr_t)(::fnv_00b10730::FUN_00b10730((unsigned char *)(hi.m_04), (unsigned char *)(this->m_10), (unsigned char *)(lo.m_04))));
        big.unk00 = this->m_10;
        big.unk04 = big.unk00;
        big.unk08 = r;
        big.unk0d = big.unk0c;
        this->m_10 = r;
    }
    *out = lo;
    return out;
}

// Calls FUN_00ec7c56 when first is zero or differs from rhs->first, then returns whether second differs from rhs->second.
// @fnv 0x00b10490
bool FUN_00b10490_class::FUN_00b10490(const FUN_00b10490_class* rhs)
{
    if (!((unsigned char)(int)(first != 0) && (unsigned char)(int)(first == rhs->first)))
    {
        std::abort();
    }
    do
    {
    } while (false);
    return !((unsigned char)(int)(second == rhs->second));
}

struct FUN_00b108e0_pool
{
};



// Checks that count * 0x1c does not overflow, reports an error if it does, then allocates count * 0x1c bytes from the pool and returns the pointer.
// @fnv 0x00b108e0
void* __cdecl AllocatePoolArray(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 0x1c)
        {
            throw std::bad_alloc();
        }
    }
    return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::FUN_00b108e0_pool *>(&::g_memoryManager))))->FUN_00aa3e40(count * 0x1c);
}

struct Mat3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    Mat3();
    Mat3 Multiply(const Mat3& rhs) const;
};

// Multiplies this 3x3 matrix by rhs and returns the resulting matrix.
// @fnv 0x00b12940
Mat3 Mat3::Multiply(const Mat3& rhs) const
{
    Mat3 result;
    result.m00 = m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20;
    result.m01 = m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21;
    result.m02 = m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22;
    result.m10 = m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20;
    result.m11 = m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21;
    result.m12 = m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22;
    result.m20 = m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20;
    result.m21 = m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21;
    result.m22 = m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22;
    return result;
}

struct RotationMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void SetRotationAxisAngle(float angle, float x, float y, float z);
};
// Builds a 3x3 rotation matrix from an angle and axis components, storing the result in m00..m22.
// @fnv 0x00b12ec0
void RotationMatrix::SetRotationAxisAngle(float angle, float afAxisX, float afAxisY, float afAxisZ)
{
    float cosA = (float)((float)(sin((float)(angle / ::DAT_010a4d90))));
    float sinA = (float)((float)(cos((float)(angle / ::DAT_010a4d90))));
    float zAxis = 1.0f - sinA;
    float xAxis = afAxisX, yAxis = afAxisY, oneMinusCosA = afAxisZ;
    m00 = zAxis * xAxis * xAxis + sinA;
    m01 = zAxis * xAxis * yAxis + cosA * oneMinusCosA;
    m02 = zAxis * xAxis * oneMinusCosA - cosA * yAxis;
    m10 = zAxis * xAxis * yAxis - cosA * oneMinusCosA;
    m11 = zAxis * yAxis * yAxis + sinA;
    m12 = zAxis * yAxis * oneMinusCosA + cosA * xAxis;
    m20 = zAxis * xAxis * oneMinusCosA + cosA * yAxis;
    m21 = zAxis * yAxis * oneMinusCosA - cosA * xAxis;
    m22 = zAxis * oneMinusCosA * oneMinusCosA + sinA;
}

struct Vec3f
{
    float x, y, z;
};

struct ScratchBlock
{
    Vec3f m_00;
    Vec3f m_0c;
    Vec3f m_18;
};

struct ScratchPair
{
    int m_00;
    int m_04;
};

struct ScratchResult
{
};

struct ScratchHelper
{
    ScratchResult* Compute(float* out, FUN_00b0cf90_class* owner, Vec3f* tmp, float scale);
};

// @fnv 0x00b13000
float* FUN_00b13000(float* dst, FUN_00b0cf90_class* pOwner, ScratchHelper* pHelper, float fScale)
{
    Vec3f blk;
    float c3;
    ScratchPair pr;
    ScratchBlock tmp;
    pOwner->AddVector(dst, ((const float *)(reinterpret_cast<::FUN_00b0cff0_class *>((pHelper->Compute(&c3, pOwner, &blk, fScale)))->ScaleSwizzled({}, {}))));
    return dst;
}

struct Flag
{
    unsigned char v;
};
// @fnv 0x00b17740
void __cdecl FUN_00b17740(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d)
{
    Flag zero = {};
    unsigned char raw4;
    unsigned char copy = raw4;
    {
        uintptr_t dd_b = b;
        int tau_p;
        uintptr_t zeta_a;
        zeta_a = a;
        ::FUN_00b17b40((::CopyElem12 *)(zeta_a), (::CopyElem12 *)(dd_b), (::CopyElem12 *)(c));
    }
}

struct BB17790Iterator
{
    int* m_piPtr;
};

struct BB17790PtrCategory
{
    char m_cKind;
};
struct BB17790CheckedTag
{
};


// Forwards the iterator range, destination pointer and allocator to FUN_00b17c20 along with an uninitialized category and a checked tag.
// @fnv 0x00b17790
void __cdecl FUN_00b17790(BB17790Iterator kFirst, BB17790Iterator kLast, int* piDest, void* pvAllocator)
{
    BB17790CheckedTag kChecked = {};
    BB17790PtrCategory kCategorySource4;
    BB17790PtrCategory kCategory = kCategorySource4;
    BB17790Iterator kLastBase = kLast;
    int* kDest;
    BB17790Iterator kFirstBase3 = kFirst;
    ::fnv_00b17c20::FUN_00b17c20((*(::fnv_00b17c20::ElQ * *)&(const ::BB17790Iterator &)(kFirstBase3)), (*(::fnv_00b17c20::ElQ * *)&(const ::BB17790Iterator &)(kLastBase)), (::fnv_00b17c20::ElQ *)(piDest));
}

struct SortEntry
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
    float key;
};
// Orders three SortEntry pointers by their key field using compare-and-swap passes.
// @fnv 0x00b17850
void SortThreeEntries(SortEntry** apFirst, SortEntry** apSecond, SortEntry** apThird)
{
    {
        float left0 = (*apSecond)->key;
        float right0 = (*apFirst)->key;
        if (((unsigned char)(left0 > right0 ? 1 : 0)) && apSecond != apFirst)
        {
            SortEntry* swap0 = *apSecond;
            *apSecond = *apFirst;
            *apFirst = swap0;
        }
    }
    {
        float right1 = (*apThird)->key;
        float left1 = (*apSecond)->key;
        if (((unsigned char)(right1 > left1 ? 1 : 0)) && apThird != apSecond)
        {
            SortEntry* swap1 = *apThird;
            *apThird = *apSecond;
            *apSecond = swap1;
        }
    }
    {
        float right2 = (*apSecond)->key;
        float left2 = (*apFirst)->key;
        if (((unsigned char)(right2 > left2 ? 1 : 0)) && apSecond != apFirst)
        {
            SortEntry* swap2 = *apSecond;
            *apSecond = *apFirst;
            *apFirst = swap2;
        }
    }
}

struct FUN_00b17e90_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int* m_0c;
    int* m_10;
    int* m_14;

    bool ResizeArray(unsigned int count);
};

struct FUN_00b17e90_pad
{
    unsigned int u00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0c;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1c;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    unsigned int u34;
    unsigned int u38;
    unsigned int u3c;
    unsigned int u40;
    unsigned int u44;
    unsigned int u48;
    unsigned int u4c;
    unsigned int u50;
    unsigned int u54;
    unsigned int u58;
    unsigned int u5c;
    unsigned int u60;
    unsigned int u64;
    unsigned int u68;
    unsigned int u6c;
    unsigned int u70;
    unsigned int u74;
    unsigned int u78;
    unsigned int u7c;
    unsigned int u80;
};

int* FUN_00b16b00(unsigned int count, int zero);

// @fnv 0x00b17e90
bool FUN_00b17e90_cls::ResizeArray(unsigned int count)
{
    FUN_00b17e90_pad scratch;
    unsigned int cap;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (count == 0)
    {
        return false;
    }
    else
    {
        cap = 0x3fffffff;
        if ((cap > 0 ? cap : 1) < count)
        {
            ::xlenb0f::BxVecBase::FUN_00b0fb80();
        }
        else
        {
            m_0c = FUN_00b16b00(count, 0);
            m_10 = m_0c;
            m_14 = m_0c + count;
        }
    }
    return true;
}

namespace fnv_00b00980 {

extern unsigned int DAT_011f826c;
extern CRITICAL_SECTION DAT_011f8254;
void __cdecl FUN_00fdc3f0();

// Initializes the critical section once, then calls the stored callback with a, b, c under the lock, returning 1 if no callback is set.
// @fnv 0x00b00980
unsigned char __cdecl CallLockedCallback(int a, int b, int c)
{
    unsigned char result;
    unsigned char called;
    if ((DAT_011f826c & 1) == 0)
    {
        DAT_011f826c |= 1;
        InitializeCriticalSection(&DAT_011f8254);
        std::atexit(FUN_00fdc3f0);
    }
    EnterCriticalSection(&DAT_011f8254);
    if (DAT_011f8250 != 0)
    {
        result = reinterpret_cast<unsigned char(__cdecl*)(int, int, int)>(DAT_011f8250)(a, b, c);
    }
    else
    {
        result = 1;
    }
    called = result;
    LeaveCriticalSection(&DAT_011f8254);
    return called;
}
}  // namespace fnv_00b00980

struct BufferPos
{
    char* pcData;
    unsigned int uiElapsedMilliseconds;
};
struct FUN_00b01800_shell
{
    char pad00[0x10];
    unsigned int m_uiBufferSize;
    unsigned int m_uiBufferFill;
    unsigned int m_uiBufferPos;
    unsigned int unk1C;
    char* m_pString;
    unsigned int FUN_00b01800(void* pDst, unsigned int uiSize);
};

// @fnv 0x00b01800
unsigned int FUN_00b01800_shell::FUN_00b01800(void* pDst, unsigned int uiSize)
{
    unsigned int uiDone = 0;
    unsigned int uiAvail = m_uiBufferFill - m_uiBufferPos;
    if (uiSize > uiAvail)
    {
        if (uiAvail > 0)
        {
            BufferPos kPos = {m_pString + m_uiBufferPos, 0};
            std::memmove(pDst, kPos.pcData, uiAvail);
            pDst = (char*)pDst + uiAvail;
            uiSize -= uiAvail;
            uiDone = uiAvail;
        }
        m_uiBufferFill = 0;
        m_uiBufferPos = 0;
        if (uiSize > m_uiBufferSize)
        {
            return reinterpret_cast<::Reader078 *>(this)->ReadAtOffset((char *)(pDst), uiSize, uiDone) + uiDone;
        }
        else
        {
            m_uiBufferFill = reinterpret_cast<::Reader078 *>(this)->ReadAtOffset((char *)(m_pString), m_uiBufferSize, uiDone);
            if (m_uiBufferFill < uiSize)
                uiSize = m_uiBufferFill;
        }
    }
    {
        BufferPos kSrc = {m_pString + m_uiBufferPos, 0};
        std::memmove(pDst, kSrc.pcData, uiSize);
    }
    m_uiBufferPos += uiSize;
    return uiDone + uiSize;
}

struct StripDestination
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned short unk24;
    unsigned short stripCount;
};
struct StripBuilder
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int rowCount;
    unsigned short width;
    unsigned int baseIndex;
    void BuildStripIndices(unsigned short id, StripDestination* destination);
};
// @fnv 0x00b135a0
void StripBuilder::BuildStripIndices(unsigned short ausStripId, StripDestination* destination)
{
    if (width >= 2)
    {
        int position = width;
        float columns = position == 0 ? 1.0 : (double)width / position;
        int rows = rowCount;
        unsigned short* step;
        int indices = (rows - 1) * (2 * position + 4);
        step = new unsigned short[indices];
        reinterpret_cast<::Target *>((destination))->FUN_00b2fdc0(ausStripId, step, (unsigned short)indices);
        int count = 0;
        float index = 0.0f;
        for (int row = 0; row < rows - 1; row++)
        {
            int start = (int)index;
            step[count++] = (unsigned short)(baseIndex + (width + 1) + (int)index);
            step[count++] = (unsigned short)(baseIndex + (int)index);
            index += columns;
            for (int column = 1; column < position; column++)
            {
                step[count++] = (unsigned short)(baseIndex + (width + 1) + (int)index);
                step[count++] = (unsigned short)(baseIndex + (int)index);
                index += columns;
            }
            step[count++] = (unsigned short)(baseIndex + (width + 1) + start + width);
            step[count++] = (unsigned short)(baseIndex + start + width);
            index = (float)(start + width + 1);
            step[count++] = (unsigned short)(baseIndex + (width + 1) + start);
            step[count++] = (unsigned short)(baseIndex + (width + 1) + start);
        }
        destination->stripCount++;
    }
}


// @fnv 0x00b16b00
int* FUN_00b16b00(unsigned int count, int aiUnused)
{
    if (count <= 0)
        count = 0;
    else if (0xffffffffu / count < 4)
    {
        throw std::bad_alloc();
    }
    return (int*)::FUN_00401000(count << 2);
}

struct Pad36
{
    unsigned int unk00[9];
};
struct WStr
{
    wchar_t* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    WStr& Append(const wchar_t* text);
};

// Appends text to the string, growing the buffer when needed and updating the length, or assigns it when the string is empty.
// @fnv 0x00b00120
WStr& WStr::Append(const wchar_t* awcText)
{
    unsigned int addLen, newLen;
    if (awcText)
    {
        wchar_t* p = pString;
        if (p)
        {
            wchar_t* s1;
            addLen = awcText ? wcslen(awcText) : 0;
            newLen = (sLen == 0xFFFF ? (s1 = pString, wcslen(s1)) : sLen) + addLen;
            if (newLen > sMaxLen)
            {
                Pad36 pad1;
                wchar_t* s2 = pString;
                reinterpret_cast<::WideString *>(this)->FUN_00afff50((const unsigned short *)(s2), newLen);
            }
            {
                Pad36 pad;
                wchar_t* dst;
                wchar_t* s3;
                dst = pString + (sLen == 0xFFFF ? (s3 = pString, wcslen(s3)) : sLen);
                memmove(dst, awcText, addLen * 2 + 2);
            }
            sLen = newLen <= 0xFFFF ? (unsigned short)newLen : 0xFFFF;
        }
        else
        {
            reinterpret_cast<::WideString *>(this)->FUN_00afff50((const unsigned short *)(awcText), 0);
        }
    }
    return *this;
}

struct DirFileTime
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};
struct DirectoryFindData
{
    unsigned int dwFileAttributes;
    DirFileTime ftCreationTime;
    DirFileTime ftLastAccessTime;
    DirFileTime ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
extern void*(* DAT_00fdf070)(const char* pattern, DirectoryFindData* data);
extern int(* DAT_00fdf068)(void* handle, DirectoryFindData* data);

struct DirAllocator
{
};

// Enumerates files matching pattern, builds full paths from path and adds each to list, then closes the find handle.
// @fnv 0x00b01930
void CollectDirectoryEntries(const char* pattern, const char* path, BSSimpleList<char*>* list)
{
    DirectoryFindData findData_2;
    void* hFind9 = DAT_00fdf070(pattern, &findData_2);
    if (hFind9 != (void*)-1)
    {
        unsigned int dirLen3 = strlen(path);
        const char* slashTmp = strrchr(path, '\\');
        if (slashTmp)
        {
            dirLen3 -= strlen(slashTmp + 1);
        }
        do
        {
            unsigned int total = dirLen3 + strlen(findData_2.cFileName) + 1;
            char* name;
            void* aMem;
            name = (char*)(aMem = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::DirAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(total));
            char* aDest = name;
            memcpy(aDest, path, dirLen3);
            name[dirLen3] = 0;
            char* searchTmp = name;
            char* fileName4 = (char*)strrchr(searchTmp, '\\');
            if (fileName4)
            {
                fileName4++;
                unsigned int remainVal = total - (fileName4 - name);
                strcpy_s(fileName4, remainVal, findData_2.cFileName);
                list->AddHead(name);
                {
                    unsigned int u1, u2, u3;
                }
            }
        } while (DAT_00fdf068(hFind9, &findData_2));
        FindClose(hFind9);
    }
}

// @fnv 0x00b10830
void __cdecl FUN_00b10830(unsigned int count)
{
    if (count <= 0u)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 4u)
        {
            throw std::bad_alloc();
        }
    }
    reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::FUN_00b108e0_pool *>(&::g_memoryManager))))->FUN_00aa3e40(count << 2);
}

typedef struct B10C20Elem
{
    int m00, m04, m08, m0c, m10, m14, m18;
} B10C20Elem;

// Copies each element from the range [first, last) into dest, returning the advanced dest pointer.
// @fnv 0x00b10c20
B10C20Elem* __cdecl FUN_00b10c20(B10C20Elem* first, B10C20Elem* last, B10C20Elem* dest)
{
    B10C20Elem* original = dest;
    try
    {
        for (; first != last; ++dest, ++first)
        {
            B10C20Elem* p = dest;
            B10C20Elem* q = p;
            B10C20Elem* r;
            if (q != 0)
            {
                *q = *first;
                r = q;
            }
            else
            {
                r = 0;
            }
        }
    }
    catch (...)
    {
        for (; original != dest; ++original)
            ;
        throw;
    }
    return dest;
}

struct S_b16cd0
{
    int m0, m4, m8, mc, md, me;
};

// @fnv 0x00b16cd0
void __cdecl CopyStructArray(S_b16cd0* apDest, unsigned int auiCount, S_b16cd0* apSource)
{
    void* v14 = (void*)apDest;
    try
    {
        for (; auiCount > 0; auiCount -= 1, apDest += 1)
        {
            void* v18 = (void*)apDest;
            S_b16cd0* v1c3 = (S_b16cd0*)v18;
            void* v20;
            if (v1c3)
            {
                *v1c3 = *apSource;
                v20 = v1c3;
            }
            else
            {
                v20 = 0;
            }
            (void)v20;
        }
    }
    catch (...)
    {
        for (; v14 != (void*)apDest; v14 = (char*)v14 + 0x18)
        {
        }
        throw;
    }
}

struct CopyElem12
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
};

// Copies each CopyElem12 from the range [src, srcEnd) into dst, returning the advanced destination pointer.
// @fnv 0x00b17b40
CopyElem12* __cdecl FUN_00b17b40(CopyElem12* src, CopyElem12* srcEnd, CopyElem12* dst)
{
    CopyElem12* begin = dst;
    try
    {
        for (; src != srcEnd; dst = dst + 1, src = src + 1)
        {
            CopyElem12* kP = dst;
            CopyElem12* q = kP;
            CopyElem12* res4;
            if (q != 0)
            {
                *q = *src;
                res4 = q;
            }
            else
            {
                res4 = 0;
            }
        }
    }
    catch (...)
    {
        for (; begin != dst; begin = begin + 1)
        {
        }
        throw;
    }
    return dst;
}

typedef DWORD(* ThreadStartFn)(void*);

struct BSSemaphoreStandIn
{
    int count;
    HANDLE semaphore;
    int maxCount;
};

struct CriticalSectionInit
{
    CRITICAL_SECTION* section;
    int state;
};

struct TaskThreadPoolBase
{
    bool bActive;
    bool m_bThirdThreadFlag;
    BSSemaphoreStandIn baseSemaphore;
    TaskThreadPoolBase();
    virtual ~TaskThreadPoolBase();
};

DWORD WorkerThreadProc(void* param);
DWORD MainThreadProc(void* param);

struct FUN_00b01d50 : TaskThreadPoolBase
{
    HANDLE mainThread;
    unsigned int numThreads;
    unsigned int numCreated;
    HANDLE threads[6];
    DWORD threadIDs[6];
    bool unk50;
    CRITICAL_SECTION critSection;
    void* slots[64];
    int unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188;
    int unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8;
    int unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8;
    int unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8;
    int unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208;
    int unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228;
    int unk22c, unk230, unk234, unk238, unk23c, unk240, unk244, unk248;
    int unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268;
    BSSemaphoreStandIn semaphore;

    FUN_00b01d50(unsigned int count);
    virtual ~FUN_00b01d50();
};

// Initializes the thread pool by creating a critical section, a semaphore, and up to six worker threads plus one main thread.
// @fnv 0x00b01d50
FUN_00b01d50::FUN_00b01d50(unsigned int count)
{
    mainThread = 0;
    numThreads = count > 6 ? 6 : count;
    numCreated = 0;
    unk50 = false;
    DWORD threadID;
    {
        CriticalSectionInit initCS;
        initCS.section = &critSection;
        InitializeCriticalSection(initCS.section);
    }
    {
        BSSemaphoreStandIn* pSem = &semaphore;
        pSem->count = 0;
        pSem->maxCount = 0x7fffffff;
        pSem->semaphore = CreateSemaphoreA(0, pSem->count, pSem->maxCount, 0);
    }
    unsigned int i;
    for (i = 0; i < 64; i++)
        slots[i] = 0;
    for (i = 0; i < 6; i++)
    {
        threads[i] = 0;
        threadIDs[i] = 0;
    }
    for (i = 0; i < numThreads; i++)
    {
        threads[i] = CreateThread(0, 0, WorkerThreadProc, this, 4, &threadIDs[i]);
        if (threads[i] == 0)
            break;
        else
            numCreated++;
    }
    bActive = numCreated > 0;
    if (bActive)
        mainThread = CreateThread(0, 0, MainThreadProc, this, 0, &threadID);
}

extern int DAT_010a48ac;

struct FUN_00b02720_shell
{
    const void* vtable;
    unsigned char flag04;
    unsigned char flag05;
    BSSemaphoreStandIn semaphore;
    void* Init();
};

// Initializes the object's vtable, zeroes two bytes, and creates a semaphore with initial count 0 and maximum count 1.
// @fnv 0x00b02720
void* FUN_00b02720_shell::Init()
{
    vtable = &DAT_010a48ac;
    flag04 = 0;
    flag05 = 0;
    semaphore.count = 0;
    semaphore.maxCount = 1;
    semaphore.semaphore = CreateSemaphoreA(0, semaphore.count, semaphore.maxCount, 0);
    return this;
}

extern int DAT_010a48d8;
struct FUN_00b027c0
{
    void* vtable;
    char bActive;
    void* pGroup;
    FUN_00b027c0();
};
struct CSFields
{
    long LockCount;
    HANDLE Semaphore;
    long Pad1;
};
// Constructor that sets the vtable and bActive, creates a semaphore (max count 1) and a critical section, and zeroes several fields.
// @fnv 0x00b027c0
FUN_00b027c0::FUN_00b027c0()
{
    vtable = &DAT_010a48e8;
    bActive = 1;
    vtable = &DAT_010a48d8;
    CSFields* pCS = (CSFields*)((char*)this + 8);
    pCS->LockCount = 0;
    pCS->Pad1 = 1;
    pCS->Semaphore = CreateSemaphoreA(0, 0, 1, 0);
    CRITICAL_SECTION* pCS2 = (CRITICAL_SECTION*)((char*)this + 0x14);
    InitializeCriticalSection(pCS2);
    ((char*)this)[0x2c] = 0;
    ((char*)this)[0x2d] = 0;
    ((char*)this)[0x2e] = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
}

struct B0Elem
{
    int m0, m4, m8, mc, m10, m14, m18;
};
struct B0Vector
{
    int unk00, unk04, unk08;
    B0Elem* m_pHeadNode;
    B0Elem* m_last;
    B0Elem* m_pFreeList;
    void FUN_00b0ea80();
};
struct B0Locals
{
    int current;
    B0Elem* first1;
    B0Elem* last1;
    B0Elem* n;
    B0Elem* tags;
    B0Elem* toFree;
    B0Elem* iter;
    unsigned char pad0, pad1, oldtag, newtag;
};
// Deallocates the B0Elem node array and resets m_pHeadNode, m_last, and m_pFreeList to null.
// @fnv 0x00b0ea80
void B0Vector::FUN_00b0ea80()
{
    if (m_pHeadNode != 0)
    {
        B0Locals v;
        v.last1 = m_last;
        v.n = m_pHeadNode;
        v.tags = v.last1;
        v.toFree = v.n;
        v.newtag = v.oldtag;
        for (v.iter = v.toFree; v.iter != v.tags; ++v.iter)
        {
        }
        v.current = m_pFreeList - m_pHeadNode;
        v.first1 = m_pHeadNode;
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(v.first1);
    }
    m_pHeadNode = 0;
    m_last = 0;
    m_pFreeList = 0;
}

struct FUN_00b10940_cat
{
    bool unk00;
};
struct FUN_00b10940_tag
{
    bool unk00;
};
struct FUN_00b10940_pair
{
    uintptr_t lo;
    uintptr_t hi;
};


// Forwards first, last, dest and al to FUN_00b10c20 along with an uninitialized one-byte tag and a zeroed one-byte kind.
// @fnv 0x00b10940
void __cdecl FUN_00b10940(uintptr_t first, uintptr_t last, uintptr_t dest, uintptr_t al)
{
    FUN_00b10940_tag kind = {};
    FUN_00b10940_cat tag;
    FUN_00b10940_cat iter;
    tag = iter;
    uintptr_t n = last;
    FUN_00b10940_pair val;
    val.lo = first;
    ::FUN_00b10c20((::B10C20Elem *)(val.lo), (::B10C20Elem *)(n), (::B10C20Elem *)(dest));
}


struct FUN_00b15600_cls
{
    int unk00;
    int unk04;
    int unk08;
    uintptr_t m_0c;
    uintptr_t m_10;
    uintptr_t m_14;
    void FUN_00b15600();
};

struct Rng
{
    uintptr_t a;
    uintptr_t b;
};
// If m_0c is set, passes it to FUN_00401030; then zeroes m_0c, m_10 and m_14.
// @fnv 0x00b15600
void FUN_00b15600_cls::FUN_00b15600()
{
    if (!!m_0c)
    {
        unsigned char it;
        char c3;
        Rng pForm;
        pForm.a = m_10;
        pForm.b = m_0c;
        Rng tmp = pForm;
        it = c3;
        uintptr_t c1;
        for (c1 = tmp.b; c1 != tmp.a; c1 += 0x18)
        {
        }
        int kCount;
        kCount = (int)((m_14 - m_0c) / 0x18);
        uintptr_t block = m_0c;
        ::FUN_00401030((void *)(block));
    }
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
}

struct FUN_00afd390_class
{
    const char* text;
    unsigned int flags;
    void* FUN_00afd390(const char*, int);
};
struct DirectoryArchive
{
    int FUN_00b01590(const char* root, const char* directory, const _FILETIME* since);
};
// Recursively walks root plus directory with FindFirstFileA, counting files written after since for which FUN_00afac90 returns true.
// @fnv 0x00b01590
int DirectoryArchive::FUN_00b01590(const char* root, const char* directory, const _FILETIME* since)
{
    int count3 = 0;
    char next[260];
    char data2[260];
    _WIN32_FIND_DATAA data5;
    HANDLE state;
    bool current;
    unsigned char result;
    FUN_00afd390_class meshName3;
    int countB;
    bool value;
    strcpy_s(next, 260, root);
    fnv::crt::strcat_s(next, 260, directory);
    fnv::crt::strcat_s(next, 260, "*.*");
    state = FindFirstFileA(next, &data5);
    if (state == INVALID_HANDLE_VALUE)
        return 0;
    current = true;
    strcpy_s(data2, 260, directory);
    result = (unsigned char)strlen(data2);
    if (result > 1)
        data2[result - 1] = 0;
    meshName3.FUN_00afd390(data2, 2);
    value = false;
    if (reinterpret_cast<::S_af9 *>(this)->FindHashEntry(reinterpret_cast<::FileNameHash *>(&meshName3), &countB, 0))
        value = true;
    while (current)
    {
        if ((data5.dwFileAttributes & 0x10) && data5.cFileName[0] != '.')
        {
            strcpy_s(next, 260, directory);
            fnv::crt::strcat_s(next, 260, data5.cFileName);
            fnv::crt::strcat_s(next, 260, "\\");
            count3 += FUN_00b01590(root, next, since);
        }
        else if (value)
        {
            if (CompareFileTime(&data5.ftLastWriteTime, since) > 0)
            {
                FUN_00afd390_class fileName;
                fileName.FUN_00afd390(data5.cFileName, 0);
                if (reinterpret_cast<::fnv_00afac90::S_af9 *>(this)->FUN_00afac90(countB, reinterpret_cast<::FileNameHash *>(&fileName), 0))
                    count3++;
            }
        }
        current = (bool)FindNextFileA(state, &data5);
    }
    FindClose(state);
    return count3;
}

// Looks up path with DAT_00fdf070, copies the match's last write time into out and closes the handle; returns whether the lookup succeeded.
// @fnv 0x00b01b60
bool FUN_00b01b60(const char* path, DirFileTime* apOutTime)
{
    void* h;
    DirectoryFindData findData;
    h = DAT_00fdf070(path, &findData);
    if (h != reinterpret_cast<void*>(-1))
    {
        *apOutTime = findData.ftLastWriteTime;
        FindClose(h);
        return true;
    }
    return false;
}


// Checks whether a file matching the given pattern exists by calling FindFirstFileA and closing the handle immediately.
// @fnv 0x00b01af0
bool __cdecl FUN_00b01af0(const char* pattern)
{
    _WIN32_FIND_DATAA findData;
    HANDLE handle = FindFirstFileA(pattern, &findData);
    {
        bool found;
        if (handle != (HANDLE)-1)
        {
            found = true;
            FindClose(handle);
        }
        else
        {
            found = false;
        }
        return found;
    }
}

typedef long LONG;
typedef void* HANDLE;

struct FUN_00b02920_class
{
    void FUN_00b02920(int unused);
};

// @fnv 0x00b02920
void FUN_00b02920_class::FUN_00b02920(int unused)
{
    if (*(int*)((char*)this + 0x38) != *(int*)((char*)this + 0x34))
    {
        char* ptr = (char*)this + 8;
        WaitForSingleObject(*(HANDLE*)(ptr + 4), 0xffffffff);
        InterlockedDecrement((LONG*)ptr);
    }
    *(char*)((char*)this + 4) = 1;
    *(char*)((char*)this + 0x2c) = 0;
}

void FUN_00b00970(int value);

unsigned int FUN_00b10730(unsigned int a, unsigned int b, unsigned int c);

extern "C" void FUN_00ec7894(void* err2, const char* msg);

struct FUN_00b108e0_err
{
    void* m_vptr;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00ec78f1(unsigned int* out);
};

void* __cdecl AllocatePoolArray(unsigned int count);


void __cdecl FUN_00b17c20(BB17790Iterator kFirst, BB17790Iterator kLast, int* piDest, void* pvAllocator,
                          BB17790PtrCategory kCategory, BB17790CheckedTag kChecked);

void FUN_00b0fb80();

void* _memmove(void* pDst, const void* pSrc, unsigned int uiSize);

extern "C" void FUN_00ec7894(void* err2, const char* msg);

struct ThreadBaseE8
{
    virtual ~ThreadBaseE8()
    {}
};

struct HandleHolderB0
{
    void* m_hHandle;
    ~HandleHolderB0()
    {
        CloseHandle(m_hHandle);
    }
};

struct CSHolderB0
{
    CRITICAL_SECTION m_cs;
    ~CSHolderB0()
    {
        DeleteCriticalSection(&m_cs);
    }
};

struct OwnerPtrB0
{
    void* m_p;
};

struct OwnerRefB0
{
    OwnerPtrB0* m_r;
    OwnerRefB0(OwnerPtrB0& r) : m_r(&r)
    {}
    ~OwnerRefB0()
    {}
};

struct FUN_00b02860 : ThreadBaseE8
{
    unsigned char m_bStopped;
    int unk08;
    HandleHolderB0 m_kHandle;
    int unk10;
    CSHolderB0 m_kCS;
    virtual void Stop(int a);
    virtual ~FUN_00b02860();
};

// @fnv 0x00b02860
FUN_00b02860::~FUN_00b02860()
{
    OwnerPtrB0 kPtr;
    unsigned char bStopped;
    kPtr.m_p = this;
    OwnerRefB0 rRef(kPtr);
    if (rRef.m_r->m_p)
    {
        bStopped = ((FUN_00b02860*)rRef.m_r->m_p)->m_bStopped;
        if (!bStopped)
            ((FUN_00b02860*)rRef.m_r->m_p)->Stop(0);
    }
}

// @fnv 0x00b02970
void* FUN_00b02970::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_00b02860 *>(this)->FUN_00b02860::~FUN_00b02860();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct B0E1A0Base
{
    ~B0E1A0Base()
    {}
};

struct FUN_00b0e1a0 : B0E1A0Base
{
    void* m_pData;
    ~FUN_00b0e1a0();
};

// @fnv 0x00b0e1a0
FUN_00b0e1a0::~FUN_00b0e1a0()
{
    void* pData = m_pData;
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(pData);
}

struct VecStandIn
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int* m_pHeadNode;
    unsigned int* m_last;
};

struct AuxContStandIn
{
    const VecStandIn* m_cont;
    const VecStandIn* Getcont() const
    {
        return m_cont;
    }
};

struct VecIterStandIn
{
    AuxContStandIn* m_aux;
    unsigned int* m_ptr;
    bool Has_container() const
    {
        return m_aux != 0;
    }
    const VecStandIn* Getmycont() const
    {
        return m_aux ? m_aux->Getcont() : 0;
    }
    VecIterStandIn& FUN_00b105b0(int off);
};

// @fnv 0x00b105b0
VecIterStandIn& VecIterStandIn::FUN_00b105b0(int off)
{
    {
        if (!(Has_container()))
        {
            std::abort();
        }
        do
        {
        } while (0);
    }
    {
        if (!(m_ptr + off <= Getmycont()->m_last && m_ptr + off >= Getmycont()->m_pHeadNode))
        {
            std::abort();
        }
        do
        {
        } while (0);
    }
    m_ptr += off;
    return *this;
}

struct Element470
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};

// Genuine VC9 secure iterator/auxiliary-container accessors. No scalar
// uninitialized-read tricks from the historical near match are retained.
struct Container470;

struct Aux470
{
    const Container470* container;
    const Container470* GetContainer() const
    {
        return container;
    }
};

struct Container470
{
    Aux470* proxy;
};

struct Vector470 : Container470
{
    unsigned allocator04, allocator08;
    Element470* first;
    Element470* last;
};

struct IteratorBase470
{
    const Aux470* aux;
    bool IsContainerSet() const
    {
        return aux != 0;
    }
    const Container470* GetContainer() const
    {
        return aux ? aux->GetContainer() : 0;
    }
};

struct Iterator470 : IteratorBase470
{
    const Element470* pointer;
    Iterator470& FUN_00b0eb30();
};

// @fnv 0x00b0eb30
Iterator470& Iterator470::FUN_00b0eb30()
{
    if (!IsContainerSet())
        std::abort();
    do
    {
    } while (false);
    if (!(pointer < static_cast<const Vector470*>(GetContainer())->last))
        std::abort();
    do
    {
    } while (false);
    ++pointer;
    return *this;
}

struct FUN_00b10e90;

struct TreeEntry
{
    int x, y;
    FUN_00b10e90* child;
};

struct StorageBase
{
    void* proxy;
    __forceinline ~StorageBase()
    {
        delete (char*)proxy;
    }
};

struct EmptyTag
{
};

template <class T> struct Allocator
{
    __forceinline void deallocate(T* pointer, unsigned int count)
    {
        operator delete(pointer);
    }
};

template <class T> __forceinline void destroyRange(T* first, T* last, EmptyTag tag)
{
    for (T* current = first; current != last; ++current)
        current->~T();
}

template <class T> __forceinline void destroyElements(T* first, T* last)
{
    EmptyTag tag;
    destroyRange(first, last, tag);
}

struct OtherEntry
{
    int x, y, z, w, u, v;
};

struct VectorStorage : StorageBase
{
    int unk04;
    Allocator<TreeEntry> allocator;
    TreeEntry* first;
    TreeEntry* last;
    TreeEntry* end;
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline TreeEntry& operator[](unsigned int index)
    {
        if (!(index < size()))
            std::abort();
        return first[index];
    }
    void FUN_00b1fca0()
    {
        if (first)
        {
            TreeEntry* rangeFirst = first;
            TreeEntry* rangeLast = last;
            TreeEntry* destroyFirst = rangeFirst;
            TreeEntry* destroyLast = rangeLast;
            destroyElements(destroyFirst, destroyLast);
            allocator.deallocate(first, end - first);
        }
        first = 0;
        last = 0;
        end = 0;
    }
    __forceinline ~VectorStorage()
    {
        reinterpret_cast<::fnv_00b1fca0::tidyb1f::T1Vector *>(this)->FUN_00b1fca0();
    }
};

struct OtherStorage : StorageBase
{
    int unk04;
    Allocator<OtherEntry> allocator;
    OtherEntry* first;
    OtherEntry* last;
    OtherEntry* end;
    void FUN_00b15600()
    {
        if (first)
        {
            OtherEntry* rangeFirst = first;
            OtherEntry* rangeLast = last;
            OtherEntry* destroyFirst = rangeFirst;
            OtherEntry* destroyLast = rangeLast;
            destroyElements(destroyFirst, destroyLast);
            allocator.deallocate(first, end - first);
        }
        first = 0;
        last = 0;
        end = 0;
    }
    __forceinline ~OtherStorage()
    {
        reinterpret_cast<::FUN_00b15600_cls *>(this)->FUN_00b15600();
    }
};

struct FUN_00b10e90
{
    int unk00;
    int unk04;
    VectorStorage children;
    void* owned;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    OtherStorage other;
    ~FUN_00b10e90();
};

// @fnv 0x00b10e90
FUN_00b10e90::~FUN_00b10e90()
{
    delete (char*)owned;
    owned = 0;
    for (unsigned int index = 0; index < children.size(); ++index)
    {
        delete children[index].child;
        children[index].child = 0;
    }
}

struct input_iterator_tagS
{
};

struct output_iterator_tagS
{
};

struct forward_iterator_tagS : public input_iterator_tagS
{
};

struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};

struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};

struct _Range_checked_iterator_tagS
{
};

struct _Unchanged_checked_iterator_base_type_tagS
{
};

struct _Nonscalar_ptr_iterator_tagS
{
};

struct _Scalar_ptr_iterator_tagS
{
};

template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};

template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};

template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};

template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};

template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}

template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};

template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};

template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}

template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};

template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}

template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}

template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}

template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}

extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);

template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}

struct _Iterator_base_universalS
{
};

class _Container_base_auxS;

class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};

class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};

template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};

template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}

template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};

class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};

template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};

template <class _Ty> class vectorS;

template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            std::abort();
        do
        {
        } while (0);
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            std::abort();
        do
        {
        } while (0);
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            std::abort();
        do
        {
        } while (0);
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            std::abort();
        do
        {
        } while (0);
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};

template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};

template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}

template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}

template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}

template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}

template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};

template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            std::abort();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};

class FUN_00b0dc10_Vector : public vectorS<int>
{
  public:
    void FUN_00b0dc10();
};

// @fnv 0x00b0dc10
void FUN_00b0dc10_Vector::FUN_00b0dc10()
{
    const ::_Vector_const_iteratorS<int> &first = begin();
    const ::_Vector_const_iteratorS<int> &last = end();
    ::FUN_00b0e510_pair result;
    reinterpret_cast<::FUN_00b0e510_cls *>(this)->FUN_00b0e510(&result, (uintptr_t)(((void *const *)&(first))[0]), (uintptr_t)(((void *const *)&(first))[1]), (uintptr_t)(((void *const *)&(last))[0]), (uintptr_t)(((void *const *)&(last))[1]));
}

struct DceAux;

struct DceCont;

struct DceAux
{
    const DceCont* container;
    explicit DceAux(const DceCont* parent) : container(parent)
    {}
};

struct DceCont
{
    DceAux* owned;
    DceCont()
    {}
    ~DceCont()
    {}
};

int* __cdecl FUN_00b10830(unsigned int count, int* hint);

struct DceAllocVal
{
    DceAllocVal() throw()
    {}
    DceAllocVal(const DceAllocVal&) throw()
    {}
    int* allocate(unsigned int count)
    {
        return FUN_00b10830(count, (int*)0);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(int);
        return 0 < count ? count : 1;
    }
};

struct DceAllocAux
{
    DceAllocAux() throw()
    {}
    DceAllocAux(const DceAllocAux&) throw()
    {}
    DceAllocAux(const DceAllocVal&) throw()
    {}
    DceAux* allocate(unsigned int count)
    {
        return ((::DceAux *)(::FUN_0044d670(count)));
    }
    void deallocate(DceAux* pointer, unsigned int)
    {
        ::FUN_00401030(pointer);
    }
};

struct DceBase : DceCont
{
    DceAllocAux alaux;
    explicit DceBase(DceAllocVal al) : alaux(al)
    {
        owned = new (alaux.allocate(1)) DceAux(this);
    }
    ~DceBase()
    {
        owned->~DceAux();
        alaux.deallocate(owned, 1);
    }
};

struct DceVal : DceBase
{
    DceAllocVal alval;
    int* first;
    int* last;
    int* end;
    static void Xlen()
    {
        throw 0;
    }
    unsigned int maxSize() const
    {
        return alval.max_size();
    }
    bool FUN_00b0e730(unsigned int capacity)
    {
        // Declined /Ob1 inline of this _Buy keeps these slots in the constructor frame.
        int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9;
        int s10, s11, s12, s13, s14, s15, s16, s17, s18, s19;
        int s20, s21, s22, s23, s24, s25, s26, s27, s28;
        s0 = s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = 0;
        s10 = s11 = s12 = s13 = s14 = s15 = s16 = s17 = s18 = s19 = 0;
        s20 = s21 = s22 = s23 = s24 = s25 = s26 = s27 = s28 = 0;
        first = 0, last = 0, end = 0;
        if (capacity == 0)
            return false;
        else if (maxSize() < capacity)
            Xlen();
        else
        {
            first = alval.allocate(capacity);
            last = first;
            end = first + capacity;
        }
        return true;
    }
    DceVal(DceAllocVal al = DceAllocVal()) : DceBase(al), alval(al)
    {}
};

struct FUN_00b0dce0 : DceVal
{
    FUN_00b0dce0();
};

// @fnv 0x00b0dce0
FUN_00b0dce0::FUN_00b0dce0() : DceVal()
{
    FUN_00b0e730(0);
}

// VS2008 SP1 retail (_SECURE_SCL=1, no iterator debugging) std::vector<char>::resize(size_type, char)
  // _invalid_parameter_noinfo
int FUN_00ec7ce3(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _Count);

// memmove_s

struct VcInputTag
{
};

struct VcForwardTag : VcInputTag
{
};

struct VcBidirTag : VcForwardTag
{
};

struct VcRandomTag : VcBidirTag
{
};

struct VcScalarPtrTag
{
};

struct VcRangeCheckedTag
{
};

inline VcRandomTag VcIterRandom(char* const&, char* const&)
{  // return category for two pointers
    VcRandomTag _Cat;
    return (_Cat);
}

inline VcScalarPtrTag VcPtrCat(char*&, char*&)
{  // return category for scalar pointers
    VcScalarPtrTag _Cat;
    return (_Cat);
}

inline char* VcCopyOpt(char* _First, char* _Last, char* _Dest, VcRandomTag, VcScalarPtrTag, VcRangeCheckedTag)
{  // copy [_First, _Last) to [_Dest, ...), pointers to scalars
    int _Off = _Last - _First;
    char* _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7ce3(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}

struct VcCheckedBaseHelper
{
    static char* _Checked_base(char* const& _It)
    {  // pointers are their own checked base
        return _It;
    }
};

inline char* VcCheckedBase(char* const& _It)
{  // return the checked base of an iterator
    return VcCheckedBaseHelper::_Checked_base(_It);
}

inline char* FUN_00b10730(char* _First, char* _Last, char* _Dest)  // stdext::unchecked_copy
{                                                                  // copy [_First, _Last) to [_Dest, ...)
    char* _Result = VcCopyOpt(VcCheckedBase(_First), VcCheckedBase(_Last), _Dest, VcIterRandom(_First, _Dest),
                              VcPtrCat(_First, _Dest), VcRangeCheckedTag());
    return (_Result);
}

struct VcAl
{  // allocator<char>
    unsigned int max_size() const;
    char* allocate(unsigned int count);
    void deallocate(char* ptr, unsigned int count);
};

inline void VcDestroyRange(char*, char*, VcAl&, VcScalarPtrTag)
{  // destroy [_First, _Last), scalar type (do nothing)
}

inline void VcDestroyRange(char* _First, char* _Last, VcAl& _Al)
{  // destroy [_First, _Last)
    VcDestroyRange(_First, _Last, _Al, VcPtrCat(_First, _Last));
}

struct VcContBase;

struct VcAuxCont
{  // _Aux_cont
    const VcContBase* _Mycontainer;
    const VcContBase* _Getcont() const
    {  // get the container
        return (_Mycontainer);
    }
};

struct VcContBase
{  // _Container_base_aux
    VcAuxCont* _Myownedaux;
};

struct VcContBaseAuxAlloc : VcContBase
{  // _Container_base_aux_alloc_real
    VcAl _Alaux;
};

struct VcVecVal : VcContBaseAuxAlloc
{  // _Vector_val
    VcAl _Alval;
};

struct VcIterBase
{  // _Iterator_base_aux
    const VcAuxCont* _Myaux;
    VcIterBase() : _Myaux(0)
    {}
    void _Set_container(const VcContBase* const _Container)
    {  // set the container
        _Myaux = _Container->_Myownedaux;
    }
    const VcContBase* _Getmycont() const
    {  // go through the aux object to get the container
        return (_Myaux ? _Myaux->_Getcont() : 0);
    }
    bool _Same_container(const VcIterBase& _Other) const
    {  // test for the same container
        return (_Myaux == _Other._Myaux);
    }
    bool _Has_container() const
    {  // test for a container
        return (_Myaux != 0);
    }
};

struct VcConstIter : VcIterBase
{  // _Vector_const_iterator
    char* _Myptr;
    VcConstIter(char* _Ptr, const VcContBase* _Pvector);
    VcConstIter& FUN_00b10670(int _Off);  // operator+=
    bool operator==(const VcConstIter& _Right) const
    {  // test for iterator equality
        if (!(this->_Has_container() && this->_Same_container(_Right)))
        {
            std::abort();
        }
        do
        {
        } while (0);
        return (_Myptr == _Right._Myptr);
    }
    bool FUN_00b10490(const VcConstIter& _Right) const  // operator!=
    {                                                   // test for iterator inequality
        return (!(*this == _Right));
    }
};

struct VcIter : VcConstIter
{  // _Vector_iterator
    VcIter(char* _Ptr, const VcContBase* _Pvector) : VcConstIter(_Ptr, _Pvector)
    {}
    VcIter& operator+=(int _Off)
    {  // increment by integer
        (*(VcConstIter*)this).FUN_00b10670(_Off);
        return (*this);
    }
    VcIter operator+(int _Off) const
    {  // return this + integer
        VcIter _Tmp = *this;
        return (_Tmp += _Off);
    }
};

struct VcVec : VcVecVal
{  // vector<char>
    char* _Myfirst;
    char* _Mylast;
    char* _Myend;

    unsigned int size() const
    {  // return length of sequence
        return (_Mylast - _Myfirst);
    }
    VcIter begin()
    {  // return iterator for beginning of sequence
        return (VcIter(_Myfirst, this));
    }
    VcIter end()
    {  // return iterator for end of sequence
        return (VcIter(_Mylast, this));
    }
    VcIter _Make_iter(const VcConstIter _Where) const
    {  // make iterator from const_iterator
        return (VcIter(_Where._Myptr, this));
    }
      // _Insert_n
    VcIter FUN_00b0e510(VcConstIter _First_arg, VcConstIter _Last_arg)             // erase
    {                                                                              // erase [_First, _Last)
        VcIter _First = _Make_iter(_First_arg);
        VcIter _Last = _Make_iter(_Last_arg);
        if (_First.FUN_00b10490(_Last))
        {  // worth doing, copy down over hole
            char* _Ptr = FUN_00b10730(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void _Destroy(char* _First, char* _Last)
    {  // destroy [_First, _Last) using allocator
        VcDestroyRange(_First, _Last, this->_Alval);
    }
    void FUN_00b0e200(unsigned int _Newsize, char _Val);
};

inline VcConstIter::VcConstIter(char* _Ptr, const VcContBase* _Pvector)
{  // construct with pointer _Ptr
    if (!(_Pvector != 0 && ((VcVec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((VcVec*)_Pvector)->_Mylast))
    {
        std::abort();
    }
    do
    {
    } while (0);
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}

inline VcConstIter& VcConstIter::FUN_00b10670(int _Off)
{  // increment by integer
    if (!(this->_Has_container()))
    {
        std::abort();
    }
    do
    {
    } while (0);
    if (!(_Myptr + _Off <= ((VcVec*)(this->_Getmycont()))->_Mylast &&
          _Myptr + _Off >= ((VcVec*)(this->_Getmycont()))->_Myfirst))
    {
        std::abort();
    }
    do
    {
    } while (0);
    _Myptr += _Off;
    return (*this);
}

typedef char ElQ_aceeb0;

struct AlQ_aceeb0
{
};

struct CatQ_aceeb0
{
};

struct TagQ_aceeb0
{
};

inline CatQ_aceeb0 PtrCat_aceeb0(ElQ_aceeb0*&, ElQ_aceeb0*&)
{
    CatQ_aceeb0 c;
    return c;
}

void __cdecl FUN_00ac20d0(ElQ_aceeb0* _First, unsigned int _Count, const ElQ_aceeb0& _Val, AlQ_aceeb0& _Al, CatQ_aceeb0,
                          TagQ_aceeb0);

inline void UFillN_aceeb0(ElQ_aceeb0* _First, unsigned int _Count, const ElQ_aceeb0& _Val, AlQ_aceeb0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_aceeb0(_First, _First), TagQ_aceeb0());
}

struct VecQ_aceeb0;

inline void Dead2_q()
{
    int a[2];
}

struct CItQ_aceeb0
{
    void* _Myaux;
    ElQ_aceeb0* _Myptr;
    CItQ_aceeb0()
    {}
    CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_aceeb0& r) const
    {
        return _Myaux == r._Myaux;
    }
    int operator-(const CItQ_aceeb0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            std::abort();
        do
        {
        } while (0);
        return _Myptr - _Right._Myptr;
    }
};

struct ItQ_aceeb0 : CItQ_aceeb0
{
    ItQ_aceeb0()
    {}
    ItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : CItQ_aceeb0(_Ptr, _Pvector)
    {}
    ItQ_aceeb0& operator+=(int _Off)
    {
        reinterpret_cast<::VcConstIter *>(this)->FUN_00b10670(_Off);
        return *this;
    }
    ItQ_aceeb0 operator+(int _Off) const
    {
        ItQ_aceeb0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};

struct VecQ_aceeb0
{
    void* _Myownedaux;
    int m04;
    AlQ_aceeb0 _Alval;
    char p09[3];
    ElQ_aceeb0* _Myfirst;
    ElQ_aceeb0* _Mylast;
    ElQ_aceeb0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_aceeb0 begin()
    {
        return ItQ_aceeb0(_Myfirst, this);
    }
    ItQ_aceeb0 end()
    {
        return ItQ_aceeb0(_Mylast, this);
    }
    ElQ_aceeb0* _Ufill(ElQ_aceeb0* _Ptr, unsigned int _Count, const ElQ_aceeb0& _Val)
    {
        UFillN_aceeb0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_aceeb0 FUN_00b0e3e0(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val);
};

inline CItQ_aceeb0::CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}

namespace fnv_00b0e600 {
typedef int ElQ_aceeb0;
struct AlQ_aceeb0
{
};
struct CatQ_aceeb0
{
};
struct TagQ_aceeb0
{
};

inline CatQ_aceeb0 PtrCat_aceeb0(ElQ_aceeb0*&, ElQ_aceeb0*&)
{
    CatQ_aceeb0 c;
    return c;
}
void __cdecl FUN_00ac20d0(ElQ_aceeb0* _First, unsigned int _Count, const ElQ_aceeb0& _Val, AlQ_aceeb0& _Al, CatQ_aceeb0,
                          TagQ_aceeb0);
inline void UFillN_aceeb0(ElQ_aceeb0* _First, unsigned int _Count, const ElQ_aceeb0& _Val, AlQ_aceeb0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_aceeb0(_First, _First), TagQ_aceeb0());
}
struct VecQ_aceeb0;
inline void Dead2_q()
{
    int a[2];
}
struct CItQ_aceeb0
{
    void* _Myaux;
    ElQ_aceeb0* _Myptr;
    CItQ_aceeb0()
    {}
    CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_aceeb0& r) const
    {
        return _Myaux == r._Myaux;
    }
    int operator-(const CItQ_aceeb0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            std::abort();
        do
        {
        } while (0);
        return _Myptr - _Right._Myptr;
    }
};
struct ItQ_aceeb0 : CItQ_aceeb0
{
    ItQ_aceeb0()
    {}
    ItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : CItQ_aceeb0(_Ptr, _Pvector)
    {}
    ItQ_aceeb0& operator+=(int _Off)
    {
        reinterpret_cast<::VecIterStandIn *>(this)->FUN_00b105b0(_Off);
        return *this;
    }
    ItQ_aceeb0 operator+(int _Off) const
    {
        ItQ_aceeb0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};
struct VecQ_aceeb0
{
    void* _Myownedaux;
    int m04;
    AlQ_aceeb0 _Alval;
    char p09[3];
    ElQ_aceeb0* _Myfirst;
    ElQ_aceeb0* _Mylast;
    ElQ_aceeb0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_aceeb0 begin()
    {
        return ItQ_aceeb0(_Myfirst, this);
    }
    void FUN_00b0f410(CItQ_aceeb0 _Where, unsigned int _Count, const ElQ_aceeb0& _Val);
    ItQ_aceeb0 end()
    {
        return ItQ_aceeb0(_Mylast, this);
    }
    ElQ_aceeb0* _Ufill(ElQ_aceeb0* _Ptr, unsigned int _Count, const ElQ_aceeb0& _Val)
    {
        UFillN_aceeb0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_aceeb0 FUN_00b0e600(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val);
};
inline CItQ_aceeb0::CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b0e600
ItQ_aceeb0 VecQ_aceeb0::FUN_00b0e600(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b0f410(_Where, 1, _Val);
    return begin() + _Off;
}
}

// namespace fnv_00b0e600

namespace fnv_00b0e880 {
struct ElQ_ab9bc0
{
    int m[7];
};
struct AlQ_ab9bc0
{
};
struct CatQ_ab9bc0
{
};
struct TagQ_ab9bc0
{
};
struct ElQ_ab9bc0;
inline CatQ_ab9bc0 PtrCat_ab9bc0(ElQ_ab9bc0*&, ElQ_ab9bc0*&)
{
    CatQ_ab9bc0 c;
    return c;
}
void __cdecl FUN_00ac20d0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al, CatQ_ab9bc0,
                          TagQ_ab9bc0);
inline void UFillN_ab9bc0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_ab9bc0(_First, _First), TagQ_ab9bc0());
}
struct VecQ_ab9bc0;
inline void Dead2_q()
{
    int a[2];
}
struct CItQ_ab9bc0
{
    void* _Myaux;
    ElQ_ab9bc0* _Myptr;
    CItQ_ab9bc0()
    {}
    CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_ab9bc0& r) const
    {
        return _Myaux == r._Myaux;
    }
    CItQ_ab9bc0& FUN_00b104f0(int _Off);
    int operator-(const CItQ_ab9bc0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            std::abort();
        do
        {
        } while (0);
        return _Myptr - _Right._Myptr;
    }
};
struct ItQ_ab9bc0 : CItQ_ab9bc0
{
    ItQ_ab9bc0()
    {}
    ItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : CItQ_ab9bc0(_Ptr, _Pvector)
    {}
    ItQ_ab9bc0& operator+=(int _Off)
    {
        FUN_00b104f0(_Off);
        return *this;
    }
    ItQ_ab9bc0 operator+(int _Off) const
    {
        ItQ_ab9bc0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};
struct VecQ_ab9bc0
{
    void* _Myownedaux;
    int m04;
    AlQ_ab9bc0 _Alval;
    char p09[3];
    ElQ_ab9bc0* _Myfirst;
    ElQ_ab9bc0* _Mylast;
    ElQ_ab9bc0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_ab9bc0 begin()
    {
        return ItQ_ab9bc0(_Myfirst, this);
    }
    void FUN_00b0fc00(CItQ_ab9bc0 _Where, unsigned int _Count, const ElQ_ab9bc0& _Val);
    ItQ_ab9bc0 end()
    {
        return ItQ_ab9bc0(_Mylast, this);
    }
    ElQ_ab9bc0* _Ufill(ElQ_ab9bc0* _Ptr, unsigned int _Count, const ElQ_ab9bc0& _Val)
    {
        UFillN_ab9bc0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_ab9bc0 FUN_00b0e880(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val);
};
inline CItQ_ab9bc0::CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b0e880
ItQ_ab9bc0 VecQ_ab9bc0::FUN_00b0e880(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b0fc00(_Where, 1, _Val);
    return begin() + _Off;
}
}

// namespace fnv_00b0e880

namespace vc9_std {
class exception
{
  public:
    exception();
    exception(const char* const&);
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;

  private:
    const char* message;
    int ownsMessage;
};
class bad_alloc : public exception
{
  public:
    bad_alloc(const char* message) throw() : exception(message)
    {}
    virtual ~bad_alloc() throw()
    {}
};
template <class T> inline T* allocateElements(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(T))
        throw bad_alloc(0);
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    template <class U> allocator(const allocator<U>&) throw()
    {}
    T* allocate(unsigned int count)
    {
        return allocateElements(count, (T*)0);
    }
    void deallocate(T* p, unsigned int)
    {
        operator delete(p);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
}

unsigned int __cdecl stringLength(const char*);

int __cdecl stringCopy(void*, unsigned int, const void*, unsigned int);

namespace vc9_std {
template <class E> struct char_traits
{
    typedef E char_type;
    static unsigned int length(const E* p)
    {
        return stringLength(p);
    }
    static void assign(E& a, const E& b)
    {
        a = b;
    }
    static E* _Copy_s(E* dst, unsigned int size, const E* src, unsigned int count)
    {
        stringCopy(dst, size, src, count);
        return dst;
    }
};
struct SecureTraitsTag
{
};
template <class Tr> inline SecureTraitsTag traitsCategory()
{
    SecureTraitsTag secure;
    return secure;
}
namespace TraitsHelper {
template <class Tr>
inline typename Tr::char_type* copy_s(typename Tr::char_type* dst, unsigned int size, const typename Tr::char_type* src,
                                      unsigned int count, SecureTraitsTag)
{
    return Tr::_Copy_s(dst, size, src, count);
}
template <class Tr>
inline typename Tr::char_type* copy_s(typename Tr::char_type* dst, unsigned int size, const typename Tr::char_type* src,
                                      unsigned int count)
{
    return copy_s<Tr>(dst, size, src, count, traitsCategory<Tr>());
}
}
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
template <class E, class A> struct StringStorage : StringBase
{
    A alloc;
    StringStorage(A a = A()) : alloc(a)
    {}
};
template <class E, class Tr, class A> class basic_string : public StringStorage<E, A>
{
  public:
    union Buffer
    {
        E data[16 / sizeof(E)];
        E* ptr;
    } bx;
    unsigned int mySize;
    unsigned int myRes;
    basic_string(const E* p) : StringStorage<E, A>()
    {
        _Tidy();
        assign(p);
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    basic_string& assign(const E* p)
    {
        return assign(p, Tr::length(p));
    }
    basic_string& assign(const E* p, unsigned int count)
    {
        if (_Inside(p))
            return assign(*this, p - _Myptr(), count);
        if (_Grow(count))
        {
            TraitsHelper::copy_s<Tr>(_Myptr(), myRes, p, count);
            _Eos(count);
        }
        return *this;
    }
    unsigned int size() const
    {
        return mySize;
    }
    basic_string& erase(unsigned int off = 0, unsigned int count = (unsigned int)-1);
    basic_string& assign(const basic_string& right, unsigned int off, unsigned int count)
    {
        if (right.size() < off)
            StringBase::_Xran();
        unsigned int num = right.size() - off;
        if (count < num)
            num = count;
        if (this == &right)
            erase(off + num), erase(0, off);
        else if (_Grow(num))
        {
            TraitsHelper::copy_s<Tr>(_Myptr(), myRes, right._Myptr() + off, num);
            _Eos(num);
        }
        return *this;
    }
    unsigned int max_size() const
    {
        unsigned int num = this->alloc.max_size();
        return num <= 1 ? 1 : num - 1;
    }

  protected:
    E* _Myptr()
    {
        return 16 / sizeof(E) <= myRes ? bx.ptr : bx.data;
    }
    const E* _Myptr() const
    {
        return 16 / sizeof(E) <= myRes ? bx.ptr : bx.data;
    }
    void _Eos(unsigned int size)
    {
        Tr::assign(_Myptr()[mySize = size], E());
    }
    bool _Inside(const E* p)
    {
        if (p == 0 || p < _Myptr() || _Myptr() + mySize <= p)
            return false;
        else
            return true;
    }
    void _Copy(unsigned int size, unsigned int oldlen)
    {
        unsigned int res = size | 15;
        if (max_size() < res)
            res = size;
        else if (res / 3 < myRes / 2 && myRes <= max_size() - myRes / 2)
            res = myRes + myRes / 2;
        E* p = 0;
        try
        {
            p = this->alloc.allocate(res + 1);
        }
        catch (...)
        {
            res = size;
            try
            {
                p = this->alloc.allocate(res + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < oldlen)
            TraitsHelper::copy_s<Tr>(p, res + 1, _Myptr(), oldlen);
        _Tidy(true);
        bx.ptr = p;
        myRes = res;
        _Eos(oldlen);
    }
    bool _Grow(unsigned int size, bool trim = false)
    {
        if (max_size() < size)
            StringBase::_Xlen();
        if (myRes < size)
            _Copy(size, mySize);
        else if (trim && size < 16 / sizeof(E))
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, size < mySize ? size : mySize);
        else if (size == 0)
            _Eos(0);
        return 0 < size;
    }
    void _Tidy(bool built = false, unsigned int size = 0)
    {
        if (!built)
            ;
        else if (16 / sizeof(E) <= myRes)
        {
            E* p = bx.ptr;
            if (0 < size)
                TraitsHelper::copy_s<Tr>(bx.data, 16 / sizeof(E), p, size);
            this->alloc.deallocate(p, myRes + 1);
        }
        myRes = 16 / sizeof(E) - 1;
        _Eos(size);
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern char DAT_010173c4[];

namespace vc9_std {
class logic_error : public exception
{
    string text;

  public:
    explicit logic_error(const string& message);
    virtual ~logic_error() throw()
    {}
};
class length_error : public logic_error
{
  public:
    explicit length_error(const string& message) : logic_error(message)
    {}
    virtual ~length_error() throw()
    {}
};
}

struct B0E9Rec
{
    int a, b, c, d, e, f, g;
};

struct B0E9Base
{
    void* proxy;
};

struct B0E9Proxy : B0E9Base
{
    vc9_std::allocator<int> auxAlloc;
};

struct B0E9Vec : B0E9Proxy
{
    vc9_std::allocator<B0E9Rec> alval;
    B0E9Rec* first;
    B0E9Rec* last;
    B0E9Rec* end;
    unsigned int max_size() const
    {
        return alval.max_size();
    }
    static void Xlen()
    {
        throw vc9_std::length_error(vc9_std::string(DAT_010173c4));
    }
    bool FUN_00b0e9c0(unsigned int capacity);
};

// @fnv 0x00b0e9c0
bool B0E9Vec::FUN_00b0e9c0(unsigned int capacity)
{
    first = 0, last = 0, end = 0;
    if (capacity == 0)
        return (false);
    else if (max_size() < capacity)
        ::xlenb0f::BxVecBase::FUN_00b0fb80();
    else
    {
        first = this->alval.allocate(capacity);
        last = first;
        end = first + capacity;
    }
    return (true);
}

namespace iterb0e {
struct IxContainer;
struct IxProxy
{
    const IxContainer* _Mycontainer;
    const IxContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct IxContainer
{
    IxProxy* _Myownedaux;
};
struct IxVector : IxContainer
{
    int _Alaux;
    int _Alval;
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
};
struct IxIterBase
{
    IxProxy* _Myaux;
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const IxContainer* _Getmycont() const
    {
        return _Myaux != 0 ? _Myaux->_Getmycont() : 0;
    }
};
struct IxConstIterator : IxIterBase
{
    int* _Myptr;
    IxConstIterator& FUN_00b0ec20();
};
}
using namespace iterb0e;

// @fnv 0x00b0ec20
IxConstIterator& IxConstIterator::FUN_00b0ec20()
{
    if (!this->_Has_container())
    {
        std::abort();
    }
    do
    {
    } while (0);
    if (!(_Myptr < ((IxVector*)this->_Getmycont())->_Mylast))
    {
        std::abort();
    }
    do
    {
    } while (0);
    ++_Myptr;
    return *this;
}

struct ByteAllocator;

struct MemoryAlloc
{
    void* Allocate(unsigned int);
};

struct AllocationBase
{
    virtual ~AllocationBase() throw();
    const char* message;
    int ownsMessage;
    AllocationBase(const char* const&) throw();
    AllocationBase(const AllocationBase&) throw();
};

struct AllocationError : AllocationBase
{
    AllocationError(const char* message) throw() : AllocationBase(message)
    {}
    virtual ~AllocationError() throw()
    {}
};

template <class T> inline T* __cdecl AllocateChecked(unsigned int, T*);

struct ErrorString
{
    unsigned int _Allocator;
    union
    {
        char _Buffer[16];
        char* _Pointer;
    };
    unsigned int _Size;
    unsigned int _Reserved;
    ErrorString(const char*);
    ~ErrorString();
};

struct VectorErrorBase
{
    virtual ~VectorErrorBase();
    char* _What;
    bool _DoFree;
};

struct VectorLengthError : VectorErrorBase
{
    ErrorString _Message;
    VectorLengthError(const ErrorString&);
};

inline void __cdecl ThrowVectorTooLong()
{
    throw VectorLengthError("vector<T> too long");
}
__declspec(noinline) inline char* __cdecl FUN_00b10d60(char*, char*, char*, ByteAllocator&);

__declspec(noinline) inline void __cdecl FUN_00b10cf0(char*, unsigned int, const char&);

inline char* __cdecl FUN_00b10a60(char*, char*, char*, ByteAllocator&);

inline char* __cdecl FUN_00b107a0(char*, char*, char*);

struct ByteAllocator
{
    __forceinline unsigned int max_size() const
    {
        unsigned int _Count = 0xffffffff;
        return 0 < _Count ? _Count : 1;
    }
    __forceinline char* allocate(unsigned int _Count)
    {
        return ((char *)(::fnv_0065fa30::AllocateChecked(_Count)));
    }
    __forceinline void deallocate(char* _Ptr, unsigned int _Count)
    {
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::FUN_00b108e0_pool *>(&::g_memoryManager)))))->FUN_00aa4060(_Ptr);
    }
};

struct ScalarTag
{
};

struct CheckedTag
{
};

struct UnchangedIteratorBase
{
};

template <class T> inline T CheckedBase(T& _It, UnchangedIteratorBase)
{
    return _It;
}

template <class T> inline T CheckedBase(T& _It)
{
    UnchangedIteratorBase tag;
    return CheckedBase(_It, tag);
}
__forceinline ScalarTag PointerCategory(char*& _First, char*& _Last)
{
    ScalarTag _Cat;
    return _Cat;
}

inline ScalarTag MoveCategory(char* const& _Dest)
{
    ScalarTag _Cat;
    return _Cat;
}

int __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);

inline char* ScalarCopy(char* _First, char* _Last, char* _Dest, ByteAllocator&, ScalarTag, CheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    char* _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7ce3(_Dest, _Count, _First, _Count);
    return _Result;
}
__declspec(noinline) inline char* __cdecl FUN_00b10d60(char* _First, char* _Last, char* _Dest, ByteAllocator& _Al)
{
    return ScalarCopy(_First, _Last, _Dest, _Al, PointerCategory(_First, _Dest), CheckedTag());
}
__forceinline char* UninitMove(char* _First, char* _Last, char* _Dest, ByteAllocator& _Al, ScalarTag, CheckedTag)
{
    return FUN_00b10d60(_First, _Last, _Dest, _Al);
}

inline char* TailCopy(char* _First, char* _Last, char* _Dest, ByteAllocator& _Al)
{
    return ScalarCopy(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PointerCategory(_First, _Dest),
                      CheckedTag());
}

inline char* TailMove(char* _First, char* _Last, char* _Dest, ByteAllocator& _Al, ScalarTag, CheckedTag)
{
    return TailCopy(_First, _Last, _Dest, _Al);
}

inline char* __cdecl FUN_00b10a60(char* _First, char* _Last, char* _Dest, ByteAllocator& _Al)
{
    return TailMove(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, MoveCategory(_Dest), CheckedTag());
}
__forceinline char* UncheckedMove(char* _First, char* _Last, char* _Dest, ByteAllocator& _Al)
{
    return UninitMove(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, MoveCategory(_Dest), CheckedTag());
}

inline void FillN(char* _First, unsigned int _Count, const char& _Val, CheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}

struct RandomTag
{
};

inline RandomTag IteratorCategory(char* const& _Iter)
{
    return RandomTag();
}

inline void CheckedFillN(char* _First, unsigned int _Count, const char& _Val, RandomTag, CheckedTag)
{
    char* _Last = _First + _Count;
    (void)_Last;
    FillN(CheckedBase(_First), _Count, _Val, CheckedTag());
}
__declspec(noinline) inline void __cdecl FUN_00b10cf0(char* _First, unsigned int _Count, const char& _Val)
{
    CheckedFillN(_First, _Count, _Val, IteratorCategory(_First), CheckedTag());
}

inline void UninitFill(char* _First, unsigned int _Count, const char& _Val, ByteAllocator&, ScalarTag, CheckedTag)
{
    FUN_00b10cf0(_First, _Count, _Val);
}

inline void UncheckedFill(char* _First, unsigned int _Count, const char& _Val, ByteAllocator& _Al)
{
    UninitFill(_First, _Count, _Val, _Al, PointerCategory(_First, _First), CheckedTag());
}

inline void DestroyRange2(char* _First, char* _Last, ByteAllocator&, ScalarTag)
{}

inline void DestroyRange(char* _First, char* _Last, ByteAllocator& _Al)
{
    DestroyRange2(_First, _Last, _Al, PointerCategory(_First, _Last));
}

inline void DoFill(char* _First, char* _Last, const char& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}

inline void Fill(char* _First, char* _Last, const char& _Val)
{
    DoFill(CheckedBase(_First), CheckedBase(_Last), _Val);
}

struct BidirectionalTag
{
};

inline BidirectionalTag IterRandom(char* const&, char* const&)
{
    BidirectionalTag _Cat;
    return _Cat;
}

inline char* BackScalar(char* _First, char* _Last, char* _Dest, ScalarTag, CheckedTag)
{
    int _Count = _Last - _First;
    char* _Result = _Dest - _Count;
    if (0 < _Count)
        FUN_00ec7ce3(_Result, _Count, _First, _Count);
    return _Result;
}

inline char* BackMove(char* _First, char* _Last, char* _Dest, BidirectionalTag, ScalarTag, CheckedTag)
{
    return BackScalar(CheckedBase(_First), _Last, _Dest, PointerCategory(_First, _Dest), CheckedTag());
}

inline char* __cdecl FUN_00b107a0(char* _First, char* _Last, char* _Dest)
{
    return BackMove(CheckedBase(_First), CheckedBase(_Last), _Dest, IterRandom(_First, _Dest),
                    PointerCategory(_First, _Dest), CheckedTag());
}

struct ByteIterator
{
    void* owner;
    char* pointer;
};

struct ByteVector
{
    int unk00;
    int unk04;
    ByteAllocator _Alval;
    char* _Myfirst;
    char* _Mylast;
    char* _Myend;
    __forceinline unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : (unsigned int)(_Myend - _Myfirst);
    }
    __forceinline unsigned int size() const
    {
        return (unsigned int)(_Mylast - _Myfirst);
    }
    __forceinline unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    __forceinline char* _Umove(char* _First, char* _Last, char* _Ptr)
    {
        return UncheckedMove(_First, _Last, _Ptr, _Alval);
    }
    inline char* _Umove2(char* _First, char* _Last, char* _Ptr)
    {
        return FUN_00b10a60(_First, _Last, _Ptr, _Alval);
    }
    __forceinline void _Destroy(char* _First, char* _Last)
    {
        DestroyRange(_First, _Last, _Alval);
    }
    __forceinline void _DestroyTail(char* _First, char* _Last)
    {
        int unused[6];
        (void)unused;
        DestroyRange(_First, _Last, _Alval);
    }
    __declspec(noinline) inline char* FUN_00b0f3c0(char* _Ptr, unsigned int _Count, const char& _Val)
    {
        UncheckedFill(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    void FUN_00b0ecf0(ByteIterator, unsigned int, const char&);
};

// @fnv 0x00b0e200
void VcVec::FUN_00b0e200(unsigned int _Newsize, char _Val)
{  // determine new length, padding with _Val elements as needed
    if (size() < _Newsize)
        reinterpret_cast<::ByteVector *>(this)->FUN_00b0ecf0((*(::ByteIterator *)&(const ::VcConstIter &)(end())), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        const ::VcConstIter &first = begin() + _Newsize;
        const ::VcConstIter &last = end();
        ::FUN_00b0e510_pair result;
        reinterpret_cast<::FUN_00b0e510_cls *>(this)->FUN_00b0e510(&result, (uintptr_t)(((void *const *)&(first))[0]), (uintptr_t)(((void *const *)&(first))[1]), (uintptr_t)(((void *const *)&(last))[0]), (uintptr_t)(((void *const *)&(last))[1]));
    }
}

// @fnv 0x00b0e3e0
ItQ_aceeb0 VecQ_aceeb0::FUN_00b0e3e0(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    reinterpret_cast<::ByteVector *>(this)->FUN_00b0ecf0((*(::ByteIterator *)&(const ::CItQ_aceeb0 &)(_Where)), 1, _Val);
    return begin() + _Off;
}

// @fnv 0x00b0ecf0
void ByteVector::FUN_00b0ecf0(ByteIterator _Where, unsigned int _Count, const char& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else
    {
        if (max_size() - size() < _Count)
            ::fnv_0065f640::ThrowVectorTooLong();
        else if (_Capacity < size() + _Count)
        {
            _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
            if (_Capacity < size() + _Count)
                _Capacity = size() + _Count;
            char* _Newvec = _Alval.allocate(_Capacity);
            char* _Newlast = _Newvec;
            try
            {
                _Newlast = _Umove(_Myfirst, _Where.pointer, _Newvec);
                UncheckedFill(_Newlast, _Count, _Val, _Alval);
                _Newlast += _Count;
                _Umove(_Where.pointer, _Mylast, _Newlast);
            }
            catch (...)
            {
                _Destroy(_Newvec, _Newlast);
                _Alval.deallocate(_Newvec, _Capacity);
                throw;
            }
            _Count += size();
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            _Myend = _Newvec + _Capacity;
            _Mylast = _Newvec + _Count;
            _Myfirst = _Newvec;
        }
        else if ((unsigned int)(_Mylast - _Where.pointer) < _Count)
        {
            char _Tmp = _Val;
            _Umove(_Where.pointer, _Mylast, _Where.pointer + _Count);
            try
            {
                FUN_00b0f3c0(_Mylast, _Count - (_Mylast - _Where.pointer), _Tmp);
            }
            catch (...)
            {
                _DestroyTail(_Where.pointer + _Count, _Mylast + _Count);
                throw;
            }
            _Mylast += _Count;
            Fill(_Where.pointer, _Mylast - _Count, _Tmp);
        }
        else
        {
            char _Tmp = _Val;
            char* _Oldend = _Mylast;
            _Mylast = _Umove2(_Oldend - _Count, _Oldend, _Mylast);
            FUN_00b107a0(_Where.pointer, _Oldend - _Count, _Oldend);
            Fill(_Where.pointer, _Where.pointer + _Count, _Tmp);
        }
    }
}

template <class T> inline T* __cdecl AllocateChecked(unsigned int _Count, T*)
{
    if (_Count <= 0)
        _Count = 0;
    else if (0xffffffffu / _Count < sizeof(T))
        throw AllocationError(0);
    return (T*)::FUN_00401000(_Count * sizeof(T));
}

namespace fnv_00b0f410 {
void allocationError();
void lengthError();
namespace std {
class exception
{
  public:
    exception();
    exception(const char* const&);
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;

  private:
    const char* message;
    int ownsMessage;
};
class bad_alloc : public exception
{
  public:
    bad_alloc(const char* message) throw() : exception(message)
    {}
    virtual ~bad_alloc() throw()
    {}
};
template <class T> inline T* allocateElements(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(T))
        throw bad_alloc(0);
    return (T*)operator new(count * sizeof(T));
}
template <class T> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    template <class U> allocator(const allocator<U>&) throw()
    {}
    T* allocate(unsigned int count)
    {
        return allocateElements(count, (T*)0);
    }
    void deallocate(T* p, unsigned int)
    {
        operator delete(p);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
}
unsigned int __cdecl stringLength(const char*);
int __cdecl stringCopy(void*, unsigned int, const void*, unsigned int);
namespace std {
template <class E> struct char_traits
{
    typedef E char_type;
    static unsigned int length(const E* p)
    {
        return stringLength(p);
    }
    static void assign(E& a, const E& b)
    {
        a = b;
    }
    static E* _Copy_s(E* dst, unsigned int size, const E* src, unsigned int count)
    {
        stringCopy(dst, size, src, count);
        return dst;
    }
};
struct SecureTraitsTag
{
};
template <class Tr> inline SecureTraitsTag traitsCategory()
{
    SecureTraitsTag secure;
    return secure;
}
namespace TraitsHelper {
template <class Tr>
inline typename Tr::char_type* copy_s(typename Tr::char_type* dst, unsigned int size, const typename Tr::char_type* src,
                                      unsigned int count, SecureTraitsTag)
{
    return Tr::_Copy_s(dst, size, src, count);
}
template <class Tr>
inline typename Tr::char_type* copy_s(typename Tr::char_type* dst, unsigned int size, const typename Tr::char_type* src,
                                      unsigned int count)
{
    return copy_s<Tr>(dst, size, src, count, traitsCategory<Tr>());
}
}
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
template <class E, class A> struct StringStorage : StringBase
{
    A alloc;
    StringStorage(A a = A()) : alloc(a)
    {}
};
template <class E, class Tr, class A> class basic_string : public StringStorage<E, A>
{
  public:
    union Buffer
    {
        E data[16 / sizeof(E)];
        E* ptr;
    } bx;
    unsigned int mySize;
    unsigned int myRes;
    basic_string(const E* p) : StringStorage<E, A>()
    {
        _Tidy();
        assign(p);
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    basic_string& assign(const E* p)
    {
        return assign(p, Tr::length(p));
    }
    basic_string& assign(const E* p, unsigned int count)
    {
        if (_Inside(p))
            return assign(*this, p - _Myptr(), count);
        if (_Grow(count))
        {
            TraitsHelper::copy_s<Tr>(_Myptr(), myRes, p, count);
            _Eos(count);
        }
        return *this;
    }
    unsigned int size() const
    {
        return mySize;
    }
    basic_string& erase(unsigned int off = 0, unsigned int count = (unsigned int)-1);
    basic_string& assign(const basic_string& right, unsigned int off, unsigned int count)
    {
        if (right.size() < off)
            StringBase::_Xran();
        unsigned int num = right.size() - off;
        if (count < num)
            num = count;
        if (this == &right)
            erase(off + num), erase(0, off);
        else if (_Grow(num))
        {
            TraitsHelper::copy_s<Tr>(_Myptr(), myRes, right._Myptr() + off, num);
            _Eos(num);
        }
        return *this;
    }
    unsigned int max_size() const
    {
        unsigned int num = this->alloc.max_size();
        return num <= 1 ? 1 : num - 1;
    }

  protected:
    E* _Myptr()
    {
        return 16 / sizeof(E) <= myRes ? bx.ptr : bx.data;
    }
    const E* _Myptr() const
    {
        return 16 / sizeof(E) <= myRes ? bx.ptr : bx.data;
    }
    void _Eos(unsigned int size)
    {
        Tr::assign(_Myptr()[mySize = size], E());
    }
    bool _Inside(const E* p)
    {
        if (p == 0 || p < _Myptr() || _Myptr() + mySize <= p)
            return false;
        else
            return true;
    }
    void _Copy(unsigned int size, unsigned int oldlen)
    {
        unsigned int res = size | 15;
        if (max_size() < res)
            res = size;
        else if (res / 3 < myRes / 2 && myRes <= max_size() - myRes / 2)
            res = myRes + myRes / 2;
        E* p = 0;
        try
        {
            p = this->alloc.allocate(res + 1);
        }
        catch (...)
        {
            res = size;
            try
            {
                p = this->alloc.allocate(res + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < oldlen)
            TraitsHelper::copy_s<Tr>(p, res + 1, _Myptr(), oldlen);
        _Tidy(true);
        bx.ptr = p;
        myRes = res;
        _Eos(oldlen);
    }
    bool _Grow(unsigned int size, bool trim = false)
    {
        if (max_size() < size)
            StringBase::_Xlen();
        if (myRes < size)
            _Copy(size, mySize);
        else if (trim && size < 16 / sizeof(E))
            _Tidy(true, size < mySize ? size : mySize);
        else if (size == 0)
            _Eos(0);
        return 0 < size;
    }
    void _Tidy(bool built = false, unsigned int size = 0)
    {
        if (!built)
            ;
        else if (16 / sizeof(E) <= myRes)
        {
            E* p = bx.ptr;
            if (0 < size)
                TraitsHelper::copy_s<Tr>(bx.data, 16 / sizeof(E), p, size);
            this->alloc.deallocate(p, myRes + 1);
        }
        myRes = 16 / sizeof(E) - 1;
        _Eos(size);
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
extern const char DAT_010173c4[];
namespace std {
class logic_error : public exception
{
    string text;

  public:
    explicit logic_error(const string& message);
    virtual ~logic_error() throw()
    {}
};
class length_error : public logic_error
{
  public:
    explicit length_error(const string& message) : logic_error(message)
    {}
    virtual ~length_error() throw()
    {}
};
}

inline void FUN_00b0fb80()
{
    throw std::length_error(std::string(DAT_010173c4));
}

struct B0MemoryInterface
{
    void* Allocate(unsigned int);
};
inline int* FUN_00b10830(unsigned int count, int zero)
{
    if (count > 0 && 0xffffffffU / count < sizeof(int))
        throw std::bad_alloc(0);
    return (int*)reinterpret_cast<B0MemoryInterface&>(g_memoryManager).Allocate(count * sizeof(int));
}

struct B0Allocator
{
    int state;
    typedef int* pointer;
    __forceinline int* allocate(unsigned int _Count)
    {
        return FUN_00b10830(_Count, 0);
    }
    __forceinline void deallocate(int* _Ptr, unsigned int _Count)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(_Ptr);
    }
    __forceinline unsigned int max_size() const
    {
        unsigned int _Count = 0x3fffffff;
        return 0 < _Count ? _Count : 1;
    }
};

struct B0Scalar
{
};
struct B0Checked
{
};
struct B0Unchanged
{
};
template <class _Iter> __forceinline _Iter b0base(const _Iter& _It, B0Unchanged)
{
    return _It;
}
template <class _Iter> __forceinline _Iter b0base(const _Iter& _It)
{
    B0Unchanged _Base_tag;
    return b0base(_It, _Base_tag);
}
__forceinline B0Scalar b0category(int*&, int*&)
{
    B0Scalar _Cat;
    return _Cat;
}
__forceinline int* b0copy_inner(int* _First, int* _Last, int* _Dest, B0Allocator& _Al, B0Scalar, B0Checked)
{
    return ::fnv_00b0f410::tail_target(_First, _Last, _Dest, &_Al.state);
}
__forceinline int* b0copy(int* _First, int* _Last, int* _Dest, B0Allocator& _Al)
{
    return b0copy_inner(b0base(_First), b0base(_Last), _Dest, _Al, b0category(_First, _Dest), B0Checked());
}
__forceinline void b0fill_inner(int* _First, unsigned int _Count, const int& _Val, B0Allocator&, B0Scalar, B0Checked)
{
    ::fnv_00b36b10::FUN_00b36b10((unsigned int *)(int *)(b0base(_First)), _Count, (*(const unsigned int *)(&_Val)));
}
__forceinline void b0fill(int* _First, unsigned int _Count, const int& _Val, B0Allocator& _Al)
{
    b0fill_inner(_First, _Count, _Val, _Al, b0category(_First, _First), B0Checked());
}
__forceinline void b0destroy_inner(int* _First, int* _Last, B0Allocator&, B0Scalar)
{}
__forceinline void b0destroy(int* _First, int* _Last, B0Allocator& _Al)
{
    b0destroy_inner(_First, _Last, _Al, b0category(_First, _Last));
}
__forceinline void b0debug(int*&, int*&)
{}
__forceinline void b0assign_inner(int* _First, int* _Last, const int& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
__forceinline void b0assign(int* _First, int* _Last, const int& _Val)
{
    b0assign_inner(b0base(_First), b0base(_Last), _Val);
}
struct B0Random
{
};
__forceinline B0Random b0random(int*&, int*&)
{
    B0Random tag;
    return tag;
}
int __cdecl secure_move(void*, unsigned int, const void*, unsigned int);
__forceinline int* b0backward_inner(int* first, int* last, int* dest, B0Random, B0Scalar, B0Checked)
{
    int offset = last - first;
    int* result = dest - offset;
    if (offset > 0)
        secure_move(result, offset * sizeof(int), first, offset * sizeof(int));
    return result;
}
struct B0Move
{
};
__forceinline B0Move b0move(int*&)
{
    B0Move tag;
    return tag;
}
inline int* b0moveback(int* first, int* last, int* dest, B0Random tag, B0Move, B0Checked)
{
    return b0backward_inner(first, last, dest, tag, b0category(first, dest), B0Checked());
}
inline int* FUN_00b16a60(int* first, int* last, int* dest)
{
    return b0moveback(b0base(first), b0base(last), dest, b0random(first, dest), b0move(dest), B0Checked());
}
struct FRandom
{
};
template <class T> inline FRandom fcat(const T&)
{
    FRandom tag;
    return tag;
}
template <class T> inline void floop(T first, unsigned n, const int& val, B0Checked)
{
    for (; 0 < n; --n, ++first)
        *first = val;
}
template <class T> inline void fdispatch(T first, unsigned n, const int& val, FRandom, const B0Checked&)
{
    T last = first + n;
    (void)last;
    floop(first, n, val, B0Checked());
}
template <class T> __forceinline void fworker(T first, unsigned n, const int& val)
{
    fdispatch(first, n, val, FRandom(), B0Checked());
}
template <class T> inline void finnit(T first, unsigned n, const int& val, B0Allocator&, B0Scalar, B0Checked)
{
    fworker(first, n, val);
}
template <class T> __forceinline void fouter(T first, unsigned n, const int& val, B0Allocator& al)
{
    finnit(first, n, val, al, B0Scalar(), B0Checked());
}
int __cdecl local_memmove(void*, unsigned, const void*, unsigned);
template <class T> inline int* tail_scalar(T first, T last, int* dest, int* al, B0Scalar, B0Checked)
{
    unsigned count = last - first;
    int* result = dest + count;
    if (count > 0)
        local_memmove(dest, count * sizeof(int), first, count * sizeof(int));
    return result;
}
inline int* tail_target(int* first, int* last, int* dest, int* al)
{
    return tail_scalar(b0base(first), b0base(last), dest, al, b0category(first, dest), B0Checked());
}
__forceinline int* tail_wrapper(int* first, int* last, int* dest, B0Allocator& al, B0Scalar, B0Checked)
{
    return tail_target(first, last, dest, &al.state);
}
__forceinline int* tail_copy(int* first, int* last, int* dest, B0Allocator& al)
{
    return tail_wrapper(b0base(first), b0base(last), dest, al, b0category(first, dest), B0Checked());
}
struct VecB0
{
    int m00;
    int m04;
    B0Allocator _Alval;
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
    inline int* FUN_00b167e0(int* p, unsigned int n, const int& value)
    {
        fouter(p, n, value, _Alval);
        return p + n;
    }
    __forceinline unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    __forceinline unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    __forceinline unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    template <class _Iter> __forceinline int* _Ucopy(_Iter _First, _Iter _Last, int* _Ptr)
    {
        return b0copy(_First, _Last, _Ptr, _Alval);
    }
    __forceinline int* _Utail(int* first, int* last, int* dest)
    {
        return tail_copy(first, last, dest, _Alval);
    }
    __forceinline void _Destroy(int* firstArg, int* lastArg)
    {
        b0destroy(firstArg, lastArg, _Alval);
    }
    void FUN_00b0f410(int unused, int* _Where, unsigned int _Count, const int& _Val);
};

// @fnv 0x00b0f410
void VecB0::FUN_00b0f410(int unused, int* _Where, unsigned int _Count, const int& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ::xlenb0f::BxVecBase::FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        int* _Newvec = _Alval.allocate(_Capacity);
        int* _Ptr = _Newvec;
        try
        {
            _Ptr = _Ucopy(_Myfirst, _Where, _Newvec);
            b0fill(_Ptr, _Count, _Val, _Alval);
            _Ptr += _Count;
            _Ucopy(_Where, _Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(_Newvec);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where) < _Count)
    {
        int _Tmp = _Val;
        _Ucopy(_Where, _Mylast, _Where + _Count);
        try
        {
            FUN_00b167e0(_Mylast, _Count - (_Mylast - _Where), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        b0assign(_Where, _Mylast - _Count, _Tmp);
    }
    else
    {
        int _Tmp = _Val;
        int* _Oldend = _Mylast;
        _Mylast = _Utail(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00b16a60(_Where, _Oldend - _Count, _Oldend);
        b0assign(_Where, _Where + _Count, _Tmp);
    }
}
}

// namespace fnv_00b0f410

namespace fnv_00b0fc00 {
// Insertion into a vector of 28-byte records. The iterator carries its owner.
struct RecordErrorString
{
    void* proxy;
    union
    {
        char text[16];
        char* pointer;
    } buffer;
    unsigned int size, capacity;
    RecordErrorString(const char*);
    ~RecordErrorString();
};
struct RecordLengthError
{
    void* vtable;
    char* message;
    bool ownsMessage;
    RecordErrorString text;
    RecordLengthError(const RecordErrorString&);
    RecordLengthError(const RecordLengthError&);
    ~RecordLengthError();
};
inline void FUN_00b0fb80()
{
    throw RecordLengthError(RecordErrorString("vector<T> too long"));
}
struct VectorRecord
{
    unsigned int field00, field04, field08, field0c;
    unsigned int field10, field14, field18;
};
struct VectorPosition
{
    void* owner;
    VectorRecord* pointer;
};
struct VectorAllocator
{
    typedef VectorRecord* pointer;
    inline unsigned int max_size() const
    {
        unsigned int _Count = 0xffffffffU / sizeof(VectorRecord);
        return 0 < _Count ? _Count : 1;
    }
    inline void deallocate(VectorRecord* _Ptr, unsigned int _Count)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(_Ptr);
    }
};
struct VectorPointerCategory
{
};
struct VectorUncheckedTag
{
};
struct VectorMoveCategory
{
};
struct UnchangedIteratorBase
{
};
template <class T> inline T checked_base(T& _It, UnchangedIteratorBase)
{
    return _It;
}
template <class T> inline T checked_base(T& _It)
{
    UnchangedIteratorBase _Base_tag;
    return checked_base(_It, _Base_tag);
}
struct RecordBadAlloc
{
    void* vtable;
    char* message;
    bool ownsMessage;
    RecordBadAlloc();
    RecordBadAlloc(const RecordBadAlloc&);
    ~RecordBadAlloc();
};
struct RecordMemoryInterface
{
    void* Allocate(unsigned int);
};
inline VectorRecord* __cdecl AllocatePoolArray(unsigned int count, const void* hint)
{
    if (count == 0)
        count = 0;
    else if (0xffffffffU / count < sizeof(VectorRecord))
        throw RecordBadAlloc();
    return static_cast<VectorRecord*>(
        reinterpret_cast<RecordMemoryInterface&>(g_memoryManager).Allocate(count * sizeof(VectorRecord)));
}
VectorRecord* __cdecl FUN_00b10940(VectorRecord* first, VectorRecord* last, VectorRecord* destination,
                                   VectorAllocator& allocator);
void __cdecl FUN_00b10990(VectorRecord* destination, unsigned int count, const VectorRecord& value,
                          VectorAllocator& allocator, VectorPointerCategory category, VectorUncheckedTag checked);
VectorRecord* __cdecl FUN_00b10b00(VectorRecord* first, VectorRecord* last, VectorRecord* destination,
                                   VectorAllocator& allocator);

template <class T> inline VectorPointerCategory record_category(const T&, const T&)
{
    VectorPointerCategory _Cat;
    return _Cat;
}
template <class T> inline VectorMoveCategory move_category(const T&)
{
    VectorMoveCategory _Cat;
    return _Cat;
}
template <class T>
inline VectorRecord* uninit_move(T _First, T _Last, VectorRecord* _Dest, VectorAllocator& _Al, VectorMoveCategory,
                                 VectorUncheckedTag)
{
    return FUN_00b10940(_First, _Last, _Dest, _Al);
}
template <class T> inline VectorRecord* unchecked_move(T _First, T _Last, VectorRecord* _Dest, VectorAllocator& _Al)
{
    return uninit_move(checked_base(_First), checked_base(_Last), _Dest, _Al, move_category(_Dest),
                       VectorUncheckedTag());
}
VectorRecord* FUN_00b10c20(VectorRecord*, VectorRecord*, VectorRecord*, VectorAllocator&, VectorPointerCategory,
                           VectorUncheckedTag);
inline VectorRecord* tail_unchecked_copy(VectorRecord* _First, VectorRecord* _Last, VectorRecord* _Dest,
                                         VectorAllocator& _Al)
{
    return FUN_00b10c20(checked_base(_First), checked_base(_Last), _Dest, _Al, record_category(_First, _Dest),
                        VectorUncheckedTag());
}
inline VectorRecord* tail_uninit_move(VectorRecord* _First, VectorRecord* _Last, VectorRecord* _Dest,
                                      VectorAllocator& _Al, VectorMoveCategory, VectorUncheckedTag)
{
    return tail_unchecked_copy(_First, _Last, _Dest, _Al);
}
inline VectorRecord* FUN_00b10b00(VectorRecord* _First, VectorRecord* _Last, VectorRecord* _Dest, VectorAllocator& _Al)
{
    return tail_uninit_move(checked_base(_First), checked_base(_Last), _Dest, _Al, move_category(_Dest),
                            VectorUncheckedTag());
}
struct RecordInputTag
{
};
struct RecordForwardTag : RecordInputTag
{
};
struct RecordBidirectionalTag : RecordForwardTag
{
};
struct RecordRandomTag : RecordBidirectionalTag
{
};
template <class T> inline RecordRandomTag random_category(const T&, const T&)
{
    RecordRandomTag _Cat;
    return _Cat;
}
template <class T>
inline T copy_backward_loop(T _First, T _Last, T _Dest, RecordForwardTag, VectorPointerCategory, VectorUncheckedTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
template <class T>
inline T copy_backward_opt(T _First, T _Last, T _Dest, RecordRandomTag, VectorPointerCategory, VectorUncheckedTag)
{
    T _Result = _Dest - (_Last - _First);
    copy_backward_loop(_First, _Last, checked_base(_Dest), RecordForwardTag(), VectorPointerCategory(),
                       VectorUncheckedTag());
    return _Result;
}
template <class T>
inline T FUN_00b10b80(T _First, T _Last, T _Dest, RecordRandomTag _First_dest_cat, VectorMoveCategory,
                      VectorUncheckedTag)
{
    return copy_backward_opt(_First, _Last, _Dest, _First_dest_cat, record_category(_First, _Dest),
                             VectorUncheckedTag());
}
template <class T, class U> inline U FUN_00b10890(T _First, T _Last, U _Dest)
{
    return FUN_00b10b80(checked_base(_First), checked_base(_Last), _Dest, random_category(_First, _Dest),
                        move_category(_Dest), VectorUncheckedTag());
}
inline void unchecked_fill(VectorRecord* _First, unsigned int _Count, const VectorRecord& _Val, VectorAllocator& _Al)
{
    FUN_00b10990(_First, _Count, _Val, _Al, record_category(_First, _First), VectorUncheckedTag());
}
inline void destroy_range(VectorRecord* _First, VectorRecord* _Last, VectorAllocator& _Al, VectorPointerCategory)
{
    for (; _First != _Last; ++_First)
        _First->~VectorRecord();
}
inline void destroy_range(VectorRecord* _First, VectorRecord* _Last, VectorAllocator& _Al)
{
    destroy_range(_First, _Last, _Al, record_category(_First, _Last));
}
inline void fill_range(VectorRecord* _First, VectorRecord* _Last, const VectorRecord& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void fill_records(VectorRecord* _First, VectorRecord* _Last, const VectorRecord& _Val)
{
    fill_range(checked_base(_First), checked_base(_Last), _Val);
}
struct RecordVector
{
    void* containerProxy;
    void* firstIterator;
    VectorAllocator allocator;
    VectorRecord* first;
    VectorRecord* last;
    VectorRecord* limit;

    inline unsigned int capacity() const
    {
        return first == 0 ? 0 : limit - first;
    }
    inline unsigned int size() const
    {
        return last - first;
    }
    inline unsigned int max_size() const
    {
        return allocator.max_size();
    }
    inline VectorRecord* copy(VectorRecord* begin, VectorRecord* end, VectorRecord* destination)
    {
        return unchecked_move(begin, end, destination, allocator);
    }
    inline VectorRecord* fill_uninitialized(VectorRecord* destination, unsigned int count, const VectorRecord& value)
    {
        unchecked_fill(destination, count, value, allocator);
        return destination + count;
    }
    inline VectorRecord* copy_tail(VectorRecord* _First, VectorRecord* _Last, VectorRecord* _Ptr)
    {
        return FUN_00b10b00(_First, _Last, _Ptr, allocator);
    }
    inline void destroy(VectorRecord* begin, VectorRecord* end)
    {
        destroy_range(begin, end, allocator);
    }
    inline void fill(VectorRecord* begin, VectorRecord* end, const VectorRecord& value)
    {
        fill_records(begin, end, value);
    }
    void FUN_00b0fc00(VectorPosition where, unsigned int count, const VectorRecord& value);
};
// @fnv 0x00b0fc00
void RecordVector::FUN_00b0fc00(VectorPosition where, unsigned int count, const VectorRecord& value)
{
    unsigned int newCapacity = capacity();
    if (count == 0)
    {
    }
    else if (max_size() - size() < count)
    {
        ::xlenb0f::BxVecBase::FUN_00b0fb80();
    }
    else if (newCapacity < size() + count)
    {
        newCapacity = max_size() - newCapacity / 2 < newCapacity ? 0 : newCapacity + newCapacity / 2;
        if (newCapacity < size() + count)
            newCapacity = size() + count;
        VectorRecord* newVector = AllocatePoolArray(newCapacity, 0);
        VectorRecord* constructedEnd = newVector;
        try
        {
            constructedEnd = copy(first, where.pointer, newVector);
            fill_uninitialized(constructedEnd, count, value);
            constructedEnd += count;
            copy(where.pointer, last, constructedEnd);
        }
        catch (...)
        {
            destroy(newVector, constructedEnd);
            allocator.deallocate(newVector, newCapacity);
            throw;
        }
        count += size();
        if (first != 0)
        {
            destroy(first, last);
            allocator.deallocate(first, limit - first);
        }
        limit = newVector + newCapacity;
        last = newVector + count;
        first = newVector;
    }
    else if ((unsigned int)(last - where.pointer) < count)
    {
        VectorRecord saved = value;
        copy(where.pointer, last, where.pointer + count);
        try
        {
            fill_uninitialized(last, count - (last - where.pointer), saved);
        }
        catch (...)
        {
            destroy(where.pointer + count, last + count);
            throw;
        }
        last += count;
        fill_records(where.pointer, last - count, saved);
    }
    else
    {
        VectorRecord _Tmp = value;
        VectorRecord* _Oldend = last;
        last = copy_tail(_Oldend - count, _Oldend, last);
        FUN_00b10890(where.pointer, _Oldend - count, _Oldend);
        fill_records(where.pointer, where.pointer + count, _Tmp);
    }
}
}

// namespace fnv_00b0fc00

struct ContainerBaseAuxX104F0
{
};

class AuxContX104F0
{
  public:
    const ContainerBaseAuxX104F0* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX104F0* _Mycontainer;
};

class IteratorBaseAuxX104F0
{
  public:
    const ContainerBaseAuxX104F0* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX104F0* _Myaux;
};

struct ElemX104F0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct VectorX104F0 : public ContainerBaseAuxX104F0
{
    AuxContX104F0* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX104F0* _Myfirst;
    ElemX104F0* _Mylast;
    ElemX104F0* _Myend;
};

class FUN_00b104f0_It : public IteratorBaseAuxX104F0
{
  public:
    FUN_00b104f0_It& FUN_00b104f0(int _Off);
    ElemX104F0* _Myptr;
};

// @fnv 0x00b104f0
FUN_00b104f0_It& FUN_00b104f0_It::FUN_00b104f0(int _Off)
{
    if (!(this->_Has_container()))
        std::abort();
    do
    {
    } while (0);
    if (!(_Myptr + _Off <= ((VectorX104F0*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorX104F0*)this->_Getmycont())->_Myfirst))
        std::abort();
    do
    {
    } while (0);
    _Myptr += _Off;
    return *this;
}


struct Mat3Rot : Mat3
{
    void FUN_00b12c00(float a, float b);
};

// @fnv 0x00b12c00
void Mat3Rot::FUN_00b12c00(float a, float b)
{
    Mat3 rot;
    float fCY;
    float fSinY;
    float cs;
    float fSZ;
    fCY = (float)((double)(float)::std::cos((float)(a / DAT_010a4d90)));
    fSinY = (float)((double)(float)::std::sin((float)(a / DAT_010a4d90)));
    cs = (float)((double)(float)::std::cos((float)(b / DAT_010a4d90)));
    fSZ = (float)((double)(float)::std::sin((float)(b / DAT_010a4d90)));
    rot.m00 = fCY * cs;
    rot.m01 = fCY * fSZ;
    rot.m02 = -fSinY;
    rot.m10 = -fSZ;
    rot.m11 = cs;
    rot.m12 = 0.0f;
    rot.m20 = fSinY * cs;
    rot.m21 = fSinY * fSZ;
    rot.m22 = fCY;
    *(Mat3*)this = rot.Multiply(*this);
}

struct FUN_00b13040_class
{
    float x;
    float y;
    float z;

// @fnv 0x00b13040
    FUN_00b13040_class()
    {}
    FUN_00b13040_class(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    FUN_00b13040_class FUN_00b13040(const FUN_00b13040_class& pt) const;
};

FUN_00b13040_class FUN_00b13040_class::FUN_00b13040(const FUN_00b13040_class& pt) const
{
    return FUN_00b13040_class(x - pt.x, y - pt.y, z - pt.z);
}

namespace fnv_00b13100 {
extern "C" double __cdecl FUN_00ec6054(double);
extern "C" double __cdecl FUN_00ec9f30(double);
extern "C" double __cdecl FUN_00eca060(double);
template <class T> inline const T& max_value(const T& _Left, const T& _Right)
{
    return _Left < _Right ? _Right : _Left;
}
struct Vector3
{
    float x, y, z;
    Vector3()
    {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }
    Vector3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vector3 AddVector(const Vector3& other) const
    {
        return Vector3(other.x + x, other.y + y, other.z + z);
    }
    Vector3 ScaleSwizzled(float scale) const
    {
        return Vector3(scale * x, scale * y, scale * z);
    }
    Vector3 FUN_00b13040(const Vector3& other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    Vector3 FUN_00b12890(const struct FloatMatrix3&) const;
    void FUN_00b12790()
    {
        float lengthSquared = x * x + y * y + z * z;
        float inverseLength = 1.0f / (float)FUN_00ec6054(lengthSquared);
        x *= inverseLength;
        y *= inverseLength;
        z *= inverseLength;
    }
};
struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vector3 TransformVector(const Vector3& v) const
    {
        return Vector3(v.z * m02 + (v.y * m01 + v.x * m00), v.z * m12 + (v.y * m11 + v.x * m10),
                       v.z * m22 + (v.y * m21 + v.x * m20));
    }
    void FUN_00b12d50(float, Vector3);
    FloatMatrix3() : m00(1), m01(0), m02(0), m10(0), m11(1), m12(0), m20(0), m21(0), m22(1)
    {}
    FloatMatrix3 Multiply(const FloatMatrix3&) const;
    void FUN_00b134d0(float angle)
    {
        FloatMatrix3 spin;
        float cosine = (float)FUN_00ec9f30((float)(angle / DAT_010a4d90));
        float sine = (float)FUN_00eca060((float)(angle / DAT_010a4d90));
        spin.m00 = cosine;
        spin.m01 = 0;
        spin.m02 = -sine;
        spin.m10 = 0;
        spin.m11 = 1;
        spin.m12 = 0;
        spin.m20 = sine;
        spin.m21 = 0;
        spin.m22 = cosine;
        *this = spin.Multiply(*this);
    }
};
inline Vector3 Vector3::FUN_00b12890(const FloatMatrix3& m) const
{
    return Vector3(m.m20 * z + (m.m10 * y + m.m00 * x), m.m21 * z + (m.m11 * y + m.m01 * x),
                   m.m22 * z + (m.m12 * y + m.m02 * x));
}
namespace TransformRecord {
struct TransformData
{
    Vector3 direction;
    Vector3 position;
    float scale;
    FloatMatrix3 rotation;
    float extent;
    float weight;
    TransformData()
    {}
};
}
struct Curve
{
};
struct Config
{
    Curve* GetCurve()
    {
        return curve;
    }
    int unk00, count, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    Curve* curve;
};
template <class T> struct ConfigVector
{
    void* m_pContainerProxy;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    T& operator[](unsigned int _Pos)
    {
        if (!(_Pos < size()))
        {
            std::abort();
        }
        return *(_Myfirst + _Pos);
    }
};
extern ConfigVector<Config*> DAT_011f8c58;
struct RandomSource
{
};
struct ParentNode
{
    ParentNode* parent;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    TransformRecord::TransformData* transform;
    int enabled;
};
struct Settings
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int parentDepth;
};
inline void DeadEnd()
{
    int aiE[5];
}
struct Effect
{
    void FUN_00b13100(ParentNode*, float, unsigned int, const Vector3&, float, const FloatMatrix3&, const Vector3&, void*,
                      float, int);
};
// @fnv 0x00b13100
void Effect::FUN_00b13100(ParentNode* node, float amount, unsigned int index, const Vector3& position, float time,
                          const FloatMatrix3& rotation, const Vector3& axis, void* flags, float speed, int mode)
{
    Config* profile = DAT_011f8c58[index];
    float arc = 60.0f;
    const int samplesCount = 2;
    TransformRecord::TransformData transforms[samplesCount];
    float distance = reinterpret_cast<::FUN_00b37ad0_class *>((profile->GetCurve()))->FUN_00b37ad0(time) * amount;
    float step = max_value(distance / profile->count, 0.01f);
    float randomAngle = reinterpret_cast<::FUN_00b3f130_shell *>(&((*reinterpret_cast<::fnv_00b13100::RandomSource *>(&::g_011f8c05))))->FUN_00b3f130(-180.0f, 180.0f);
    Vector3 rotated;
    reinterpret_cast<::FUN_00b12b50_class *>((void *)&(rotation))->TransformVector((float *)(void *)(&rotated), (const float *)(void *)(&axis));
    TransformRecord::TransformData* from = &transforms[0];
    from->position = position;
    from->rotation = rotation;
    from->rotation.FUN_00b12d50(randomAngle, rotated);
    from->rotation.FUN_00b134d0(arc);
    from->direction = (*reinterpret_cast<::fnv_00b13100::Vector3 *>(&::DAT_011f8c40)).FUN_00b12890(from->rotation);
    TransformRecord::TransformData* pOther = &transforms[1];
    Vector3 scaled = from->direction.ScaleSwizzled(step);
    Vector3 moved;
    reinterpret_cast<::FUN_00b0cf90_class *>((void *)&(from->position))->AddVector((float *)(void *)(&moved), (const float *)(void *)(&scaled));
    pOther->position = moved;
    Vector3 forward = transforms[1].position.FUN_00b13040(transforms[0].position);
    reinterpret_cast<::FUN_00b12790_class *>(&(forward))->FUN_00b12790();
    Vector3 towardParent;
    if (!node || !node->enabled)
    {
        towardParent = forward;
    }
    else
    {
        Vector3 origin = node->transform->position;
        if ((*reinterpret_cast<::fnv_00b13100::Settings * *>(&::DAT_011f8bf4))->parentDepth != 0)
        {
            int level = 0;
            ParentNode* parent = node;
            while (parent && level < (*reinterpret_cast<::fnv_00b13100::Settings * *>(&::DAT_011f8bf4))->parentDepth)
            {
                parent = parent->parent;
                level++;
            }
            if (parent)
                origin = parent->transform->position;
        }
        towardParent = transforms[1].position.FUN_00b13040(origin);
    }
    reinterpret_cast<::FUN_00b12790_class *>(&(towardParent))->FUN_00b12790();
    reinterpret_cast<::fnv_00b13c10::Host *>(this)->FUN_00b13c10((void *)&(transforms[1].position), time, (::Link *)(::fnv_00b13100::Effect *)(this), (::fnv_00b13c10::MathPoint *)&(forward), (::fnv_00b13c10::MathPoint *)&(towardParent), speed, mode, (void *)(flags));
    DeadEnd();
}
}

// namespace fnv_00b13100

namespace fnv_00b13820 {

template <class T> struct NodeVec
{
    void* aux;
    int pad4;
    int pad8;
    T* first;
    T* last;
    T* endp;

    unsigned size() const
    {
        return last - first;
    }

    T& operator[](unsigned pos)
    {
        {
            if (!(pos < size()))
            {
                std::abort();
            }
        }
        return *(first + pos);
    }

    // /Ob1 tries to inline push_back, refuses the recursive body, and keeps these slots.
    void push_back(const T& val)
    {
        unsigned d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
        unsigned d12, d13, d14, d15, d16, d17, d18, d19, d20, d21;
        if (d0 == 1)
        {
            d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = d9 = d10 = d11 = d12 = 0;
            d13 = d14 = d15 = d16 = d17 = d18 = d19 = d20 = d21 = 0;
        }
        reinterpret_cast<::IndexSet *>(this)->FUN_00b15390((const unsigned int &)(val));
    }
};

struct ChildNode
{
    int x;
    int y;
    struct SceneNode* child;
};

struct SceneNode
{
    int unk00;
    int unk04;
    NodeVec<ChildNode> children;

    void FUN_00b13820(NodeVec<SceneNode*>* arg);
};

// @fnv 0x00b13820
void SceneNode::FUN_00b13820(NodeVec<SceneNode*>* arg)
{
    reinterpret_cast<::IndexSet *>((arg))->FUN_00b15390((const unsigned int &)((const ::fnv_00b13820::SceneNode *const &)(this)));
    for (unsigned int i = 0; i < children.size(); ++i)
        children[i].child->FUN_00b13820(arg);
}
}

// namespace fnv_00b13820

namespace fnv_00b138c0 {
struct RangeTag
{
};
struct CheckedRange
{
    unsigned int owner;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int begin;
    unsigned int end;
};

inline void FUN_00b16950(unsigned int a, unsigned int b, unsigned int c, unsigned int d, RangeTag e)
{
    int a0, a6, aAC, aArg, aArr2, aAvailable, aAvoided, aB1, aB6, aBDD;
    int aBaactorPose, aBase6, aBaseObj, aBend, aBi, aBip, aBit, aBlend5, CNVal, CN_;
    int Diff2, Diff_, EntryLoc, EntryLocA, EntryLocTmp, LeftB, PN4, PNA, StartLoc2, StartLoc7;
    int a0b, a6b, aACb, aArgb, aArr2b, aAvailableb, aAvoidedb, aB1b, aB6b, aBDDb;
    int aBaactorPoseb, aBase6b, aBaseObjb, aBendb, aBib, aBipb, aBitb, aBlend5b, CNValb, CN_b;
    int extra0;
    int extra1;
    a0 = (int)a;
    a6 = a0 + 1;
    aAC = a6 + 1;
    aArg = aAC + 1;
    aArr2 = aArg + 1;
    aAvailable = aArr2 + 1;
    aAvoided = aAvailable + 1;
    aB1 = aAvoided + 1;
    aB6 = aB1 + 1;
    aBDD = aB6 + 1;
    aBaactorPose = aBDD + 1;
    aBase6 = aBaactorPose + 1;
    aBaseObj = aBase6 + 1;
    aBend = aBaseObj + 1;
    aBi = aBend + 1;
    aBip = aBi + 1;
    aBit = aBip + 1;
    aBlend5 = aBit + 1;
    CNVal = aBlend5 + 1;
    CN_ = CNVal + 1;
    Diff2 = CN_ + 1;
    Diff_ = Diff2 + 1;
    EntryLoc = Diff_ + 1;
    EntryLocA = EntryLoc + 1;
    EntryLocTmp = EntryLocA + 1;
    LeftB = EntryLocTmp + 1;
    PN4 = LeftB + 1;
    PNA = PN4 + 1;
    StartLoc2 = PNA + 1;
    StartLoc7 = StartLoc2 + 1;
    a0b = StartLoc7 + 1;
    a6b = a0b + 1;
    aACb = a6b + 1;
    aArgb = aACb + 1;
    aArr2b = aArgb + 1;
    aAvailableb = aArr2b + 1;
    aAvoidedb = aAvailableb + 1;
    aB1b = aAvoidedb + 1;
    aB6b = aB1b + 1;
    aBDDb = aB6b + 1;
    aBaactorPoseb = aBDDb + 1;
    aBase6b = aBaactorPoseb + 1;
    aBaseObjb = aBase6b + 1;
    aBendb = aBaseObjb + 1;
    aBib = aBendb + 1;
    aBipb = aBib + 1;
    aBitb = aBipb + 1;
    aBlend5b = aBitb + 1;
    CNValb = aBlend5b + 1;
    CN_b = CNValb + 1;
    extra0 = CN_b + (int)b + (int)c + (int)d;
    extra1 = extra0;
    (void)e;
}

// @fnv 0x00b138c0
void FUN_00b138c0(CheckedRange* p)
{
    RangeTag tag = {};
    unsigned int hi = p->end;
    unsigned int firstB = 0;
    if (!p || p->begin > hi || hi > p->end)
        std::abort();
    firstB = p->owner;
    unsigned int loTmp = hi;
    unsigned int mc = p->begin;
    unsigned int second = 0;
    if (!p || p->begin > mc || mc > p->end)
        std::abort();
    second = p->owner;
    unsigned int mc5 = mc;
    FUN_00b16950(second, mc5, firstB, loTmp, tag);
}
}

// namespace fnv_00b138c0

namespace fnv_00b157e0 {
struct Entry24
{
    unsigned int id, type, value, flags, length, link;
};
struct RangeTag
{
};
struct MoveTag
{
};
struct PointerTag
{
};
struct UnchangedTag
{
};
template <class T> inline T CheckedBase(T& _It, UnchangedTag)
{
    return _It;
}
template <class T> inline T CheckedBase(T& _It)
{
    UnchangedTag _Base_tag;
    return CheckedBase(_It, _Base_tag);
}
struct ErrorString
{
    void* proxy;
    union Storage
    {
        char buffer[16];
        char* pointer;
    } text;
    unsigned int size, capacity;
    ErrorString(const char*);
    ~ErrorString();
};
struct LengthError
{
    virtual ~LengthError();
    const char* message;
    int ownsMessage;
    ErrorString text;
    LengthError(const ErrorString&);
};
extern const char DAT_010173c4[];
inline void __cdecl FUN_00b0fb80()
{
    throw LengthError(ErrorString(DAT_010173c4));
}
struct BadAllocation
{
    virtual ~BadAllocation();
    const char* message;
    int ownsMessage;
    BadAllocation(const char*);
};
void* __cdecl FUN_00401000(unsigned int);
inline Entry24* __cdecl FUN_00b23aa0(unsigned int _Count, unsigned int)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)(-1) / _Count < sizeof(Entry24))
        throw BadAllocation(0);
    return static_cast<Entry24*>(FUN_00401000(_Count * sizeof(Entry24)));
}
Entry24* __cdecl FUN_00b17790(Entry24*, Entry24*, Entry24*, void*);
void __cdecl CopyStructArray(Entry24*, unsigned int, const Entry24&, void*, PointerTag, RangeTag);

template <class T> inline MoveTag MoveCategory(const T&)
{
    MoveTag _Cat;
    return _Cat;
}
template <class T, class U> inline PointerTag PointerCategory(T&, U&)
{
    PointerTag _Cat;
    return _Cat;
}
Entry24* FUN_00b17c20(Entry24*, Entry24*, Entry24*, void*, PointerTag, RangeTag);
inline Entry24* FUN_00b17790(Entry24* _First, Entry24* _Last, Entry24* _Dest, void* _Al)
{
    return FUN_00b17c20(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PointerCategory(_First, _Dest),
                        RangeTag());
}
struct EntryAllocator
{
    inline unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(Entry24);
        return 0 < _Count ? _Count : 1;
    }
    inline Entry24* allocate(unsigned int _Count, const void* = 0)
    {
        return ((::fnv_00b157e0::Entry24 *)(::FUN_00b23aa0(_Count)));
    }
    inline void deallocate(Entry24* _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    inline void destroy(Entry24* _Ptr)
    {
        _Ptr->~Entry24();
    }
};
inline Entry24* UninitMove(Entry24* _First, Entry24* _Last, Entry24* _Dest, EntryAllocator& _Al, MoveTag, RangeTag)
{
    return FUN_00b17790(_First, _Last, _Dest, &_Al);
}
template <class T> inline Entry24* unchecked_move(T _First, T _Last, Entry24* _Dest, EntryAllocator& _Al)
{
    return UninitMove(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, MoveCategory(_Dest), RangeTag());
}
Entry24* __cdecl move_short(Entry24*, Entry24*, Entry24*, void*);
template <class T>
inline Entry24* short_move_inner(T _First, T _Last, Entry24* _Dest, EntryAllocator& _Al, MoveTag, RangeTag)
{
    return move_short(_First, _Last, _Dest, &_Al);
}
template <class T> inline Entry24* short_move(T _First, T _Last, Entry24* _Dest, EntryAllocator& _Al)
{
    return short_move_inner(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, MoveCategory(_Dest), RangeTag());
}
Entry24* tail_copy(Entry24*, Entry24*, Entry24*, EntryAllocator&, PointerTag, RangeTag);
inline Entry24* tail_unchecked_copy(Entry24* _First, Entry24* _Last, Entry24* _Dest, EntryAllocator& _Al)
{
    return tail_copy(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PointerCategory(_First, _Dest), RangeTag());
}
inline Entry24* tail_uninit_move(Entry24* _First, Entry24* _Last, Entry24* _Dest, EntryAllocator& _Al, MoveTag,
                                 RangeTag)
{
    return tail_unchecked_copy(_First, _Last, _Dest, _Al);
}
inline Entry24* FUN_00b16e40(Entry24* _First, Entry24* _Last, Entry24* _Dest, EntryAllocator& _Al)
{
    return tail_uninit_move(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, MoveCategory(_Dest), RangeTag());
}
struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
template <class T> inline RandomTag random_category(const T&, const T&)
{
    RandomTag _Cat;
    return _Cat;
}
template <class T> inline T copy_backward_loop(T _First, T _Last, T _Dest, ForwardTag, PointerTag, RangeTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
template <class T> inline T copy_backward_opt(T _First, T _Last, T _Dest, RandomTag, PointerTag, RangeTag)
{
    T _Result = _Dest - (_Last - _First);
    copy_backward_loop(_First, _Last, CheckedBase(_Dest), ForwardTag(), PointerTag(), RangeTag());
    return _Result;
}
template <class T> inline T move_backward(T _First, T _Last, T _Dest, RandomTag _Cat, MoveTag, RangeTag)
{
    return copy_backward_opt(_First, _Last, _Dest, _Cat, PointerCategory(_First, _Dest), RangeTag());
}
template <class T, class U> inline U FUN_00b16a10(T _First, T _Last, U _Dest)
{
    return move_backward(CheckedBase(_First), CheckedBase(_Last), _Dest, random_category(_First, _Dest),
                         MoveCategory(_Dest), RangeTag());
}
inline void UninitFill(Entry24* _First, unsigned int _Count, const Entry24& _Val, EntryAllocator& _Al)
{
    CopyStructArray(_First, _Count, _Val, &_Al, PointerCategory(_First, _First), RangeTag());
}
inline void DestroyRangeImpl(Entry24* _First, Entry24* _Last, EntryAllocator& _Al, PointerTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
inline void DestroyRange(Entry24* _First, Entry24* _Last, EntryAllocator& _Al)
{
    DestroyRangeImpl(_First, _Last, _Al, PointerCategory(_First, _Last));
}
inline void FillImpl(Entry24* _First, Entry24* _Last, const Entry24& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void Fill(Entry24* _First, Entry24* _Last, const Entry24& _Val)
{
    FillImpl(CheckedBase(_First), CheckedBase(_Last), _Val);
}
template <class _Ty> struct EntryVector24
{
    unsigned int m00, m04;
    EntryAllocator _Alval;
    Entry24* _Myfirst;
    Entry24* _Mylast;
    Entry24* _Myend;
    inline unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    inline unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    inline unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    inline Entry24* _Umove(Entry24* _First, Entry24* _Last, Entry24* _Ptr)
    {
        return unchecked_move(_First, _Last, _Ptr, _Alval);
    }
    inline Entry24* _UmoveShort(Entry24* _First, Entry24* _Last, Entry24* _Ptr)
    {
        return short_move(_First, _Last, _Ptr, _Alval);
    }
    inline Entry24* _Utail(Entry24* _First, Entry24* _Last, Entry24* _Ptr)
    {
        return FUN_00b16e40(_First, _Last, _Ptr, _Alval);
    }
    inline Entry24* _Ufill(Entry24* _Ptr, unsigned int _Count, const Entry24& _Val)
    {
        UninitFill(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    inline void _Destroy(Entry24* _First, Entry24* _Last)
    {
        DestroyRange(_First, _Last, _Alval);
    }
    void FUN_00b157e0(void* unused, Entry24* _Where, unsigned int _Count, const Entry24& _Val);
};
// @fnv 0x00b157e0
template <class _Ty>
void EntryVector24<_Ty>::FUN_00b157e0(void* unused, Entry24* _Where, unsigned int _Count, const Entry24& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ::xlenb0f::BxVecBase::FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        Entry24* _Newvec = ((::fnv_00b157e0::Entry24 *)(::FUN_00b23aa0(_Capacity)));
        Entry24* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(_Myfirst, _Where, _Newvec);
            _Ufill(_Ptr, _Count, _Val);
            _Ptr += _Count;
            _Umove(_Where, _Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            _Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where) < _Count)
    {
        Entry24 _Tmp = _Val;
        _UmoveShort(_Where, _Mylast, _Where + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        Fill(_Where, _Mylast - _Count, _Tmp);
    }
    else
    {
        Entry24 _Tmp = _Val;
        Entry24* _Oldend = _Mylast;
        _Mylast = _Utail(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00b16a10(_Where, _Oldend - _Count, _Oldend);
        Fill(_Where, _Where + _Count, _Tmp);
    }
}

template void EntryVector24<Entry24>::FUN_00b157e0(void*, Entry24*, unsigned int, const Entry24&);
}

// namespace fnv_00b157e0

struct UnchangedBaseB160
{
};

template <class I> inline I CheckedBaseCoreB160(I& _It, UnchangedBaseB160)
{
    return _It;
}

template <class I> inline I CheckedBaseB160(I& _It)
{
    UnchangedBaseB160 _Base_tag;
    return CheckedBaseCoreB160(_It, _Base_tag);
}

struct ScalarTagB160
{
};

struct CheckedTagB160
{
};

template <class A, class B> inline ScalarTagB160 PtrCategoryB160(const A&, const B&)
{
    ScalarTagB160 _Cat;
    return _Cat;
}

struct AllocB160
{
    inline unsigned int max_size() const
    {
        unsigned int _Count = 0x3fffffff;
        return 0 < _Count ? _Count : 1;
    }
    void deallocate(unsigned int* _Ptr, unsigned int _Count);
};

struct LateAllocB160 : AllocB160
{
};

inline unsigned int* __cdecl FUN_00b177e0(unsigned int* _First, unsigned int* _Last, unsigned int* _Dest,
                                          LateAllocB160&)
{
    if (_Last < _First)
        throw 0;
    unsigned int* _Source = _First;
    unsigned int* _Target = _Dest;
    unsigned int _Count = (unsigned int)(_Last - _First);
    unsigned int _Blocks = _Count / 4;
    unsigned int* _Stop = _Source + _Blocks * 4;
    unsigned int _Tail = _Count % 4;
    unsigned int* _Result = _Dest + _Count;
    for (; _Source != _Stop; _Source += 4, _Target += 4)
    {
        _Target[0] = _Source[0];
        _Target[1] = _Source[1];
        _Target[2] = _Source[2];
        _Target[3] = _Source[3];
    }
    for (; _Tail > 0; --_Tail)
        *_Target++ = *_Source++;
    return _Result;
}

inline void __cdecl CopyBackwardB160(unsigned int*, unsigned int*, unsigned int*);

template <class I, class O, class A>
inline O CopyCoreB160(I _First, I _Last, O _Dest, A& _Al, ScalarTagB160, CheckedTagB160)
{
    return ((unsigned int *)(::fnv_00b0f410::tail_target((int *)(_First), (int *)(_Last), (int *)(_Dest), (int *)&(_Al))));
}

template <class I, class O>
inline O CopyCoreB160(I _First, I _Last, O _Dest, LateAllocB160& _Al, ScalarTagB160, CheckedTagB160)
{
    // Retained scalar homes from the original's declined inline copy expansion.
    I copySource, copyStop;
    O copyTarget, copyResult;
    unsigned int copyCount, copyBlocks, copyTail, copyRemainder;
    return ((unsigned int *)(::fnv_00b0f410::tail_target((int *)(_First), (int *)(_Last), (int *)(_Dest), (int *)&(_Al))));
}

template <class I, class O, class A> inline O UninitializedCopyB160(I _First, I _Last, O _Dest, A& _Al)
{
    return CopyCoreB160(CheckedBaseB160(_First), CheckedBaseB160(_Last), _Dest, _Al, PtrCategoryB160(_First, _Dest),
                        CheckedTagB160());
}

template <class I, class D, class T, class A>
inline void FillCoreB160(I _First, D _Count, const T& _Val, A&, ScalarTagB160, CheckedTagB160)
{
    ::fnv_00b36b10::FUN_00b36b10(_First, _Count, _Val);
}

template <class I, class D, class T, class A>
inline void UninitializedFillB160(I _First, D _Count, const T& _Val, A& _Al)
{
    FillCoreB160(_First, _Count, _Val, _Al, PtrCategoryB160(_First, _First), CheckedTagB160());
}

template <class I, class A> inline void DestroyCoreB160(I, I, A&, ScalarTagB160)
{}

template <class I, class A> inline void DestroyRangeB160(I _First, I _Last, A& _Al)
{
    DestroyCoreB160(_First, _Last, _Al, PtrCategoryB160(_First, _Last));
}

template <class I, class T> inline void FillRangeB160(I _First, I _Last, const T& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}

template <class I, class T> inline void FillB160(I _First, I _Last, const T& _Val)
{
    FillRangeB160(CheckedBaseB160(_First), CheckedBaseB160(_Last), _Val);
}

struct StringB160
{
    unsigned int allocator;
    char text[16];
    unsigned int length, capacity;
    StringB160(const char*);
    ~StringB160();
};

struct LengthErrorB160
{
    void* vtable;
    const char* message;
    int ownsMessage;
    StringB160 text;
    LengthErrorB160(const StringB160&);
    LengthErrorB160(const LengthErrorB160&);
    ~LengthErrorB160();
};

inline void __cdecl FUN_00b0fb80()
{
    throw LengthErrorB160(StringB160("vector<T> too long"));
}

struct ExceptionB160
{
    const char* message;
    int ownsMessage;
    ExceptionB160(const char* const&) throw();
    ExceptionB160(const ExceptionB160&) throw();
    virtual ~ExceptionB160() throw();
};

const char* const NullMessageB160 = 0;

struct BadAllocB160 : ExceptionB160
{
    inline BadAllocB160() throw() : ExceptionB160(NullMessageB160)
    {}
    inline virtual ~BadAllocB160() throw()
    {}
};

inline unsigned int* __cdecl FUN_00b16b00(unsigned int _Count, unsigned int)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)-1 / _Count < sizeof(unsigned int))
        throw BadAllocB160();
    return (unsigned int*)::FUN_00401000(_Count * sizeof(unsigned int));
}

inline void AllocB160::deallocate(unsigned int* _Ptr, unsigned int _Count)
{
    FUN_00401030(_Ptr);
}

struct IteratorB160
{
    void* owner;
    unsigned int* pointer;
};

struct ArrayB160
{
    unsigned int referenceCount;
    unsigned int flags;
    LateAllocB160 _Alval;
    unsigned int* _Myfirst;
    unsigned int* _Mylast;
    unsigned int* _Myend;
    inline unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    inline unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    inline unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    template <class I> inline unsigned int* _Ucopy(I _First, I _Last, unsigned int* _Ptr)
    {
        return UninitializedCopyB160(_First, _Last, _Ptr, (AllocB160&)_Alval);
    }
    template <class I> inline unsigned int* _UcopyLate(I _First, I _Last, unsigned int* _Ptr)
    {
        return UninitializedCopyB160(_First, _Last, _Ptr, _Alval);
    }
    inline void _Destroy(unsigned int* _First, unsigned int* _Last)
    {
        DestroyRangeB160(_First, _Last, _Alval);
    }
    inline unsigned int* FUN_00b167e0(unsigned int* _Ptr, unsigned int _Count, const unsigned int& _Val)
    {
        unsigned int* _First = _Ptr;
        unsigned int* _Last = _Ptr + _Count;
        unsigned int _Value = _Val;
        unsigned int _Blocks = _Count / 4;
        unsigned int* _Stop = _First + _Blocks * 4;
        unsigned int _Tail = _Count % 4;
        for (; _First != _Stop; _First += 4)
        {
            _First[0] = _Value;
            _First[1] = _Value;
            _First[2] = _Value;
            _First[3] = _Value;
        }
        for (; _Tail > 0; --_Tail)
            *_First++ = _Value;
        return _Last;
    }
    void FUN_00b16070(IteratorB160 _Where, unsigned int _Count, const unsigned int& _Val);
};

// @fnv 0x00b16070
void ArrayB160::FUN_00b16070(IteratorB160 _Where, unsigned int _Count, const unsigned int& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ::xlenb0f::BxVecBase::FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        unsigned int* _Newvec = FUN_00b16b00(_Capacity, 0u);
        unsigned int* _Ptr = _Newvec;
        try
        {
            _Ptr = _Ucopy(_Myfirst, _Where.pointer, _Newvec);
            UninitializedFillB160(_Ptr, _Count, _Val, _Alval);
            _Ptr += _Count;
            _Ucopy(_Where.pointer, _Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            FUN_00401030(_Newvec);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where.pointer) < _Count)
    {
        unsigned int _Tmp = _Val;
        _Ucopy(_Where.pointer, _Mylast, _Where.pointer + _Count);
        try
        {
            reinterpret_cast<::fnv_00b0f410::VecB0 *>(this)->FUN_00b167e0((int *)(_Mylast), _Count - (_Mylast - _Where.pointer), (const int &)(_Tmp));
        }
        catch (...)
        {
            _Destroy(_Where.pointer + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        FillB160(_Where.pointer, _Mylast - _Count, _Tmp);
    }
    else
    {
        unsigned int _Tmp = _Val;
        unsigned int* _Oldend = _Mylast;
        _Mylast = _UcopyLate(_Oldend - _Count, _Oldend, _Mylast);
        CopyBackwardB160(_Where.pointer, _Oldend - _Count, _Oldend);
        FillB160(_Where.pointer, _Where.pointer + _Count, _Tmp);
    }
}

inline void __cdecl CopyBackwardB160(unsigned int* backFirst, unsigned int* backLast, unsigned int* backDest)
{
    const char* backFirstByte = (const char*)backFirst;
    const char* backLastByte = (const char*)backLast;
    unsigned int backCount = (unsigned int)(backLastByte - backFirstByte) / sizeof(unsigned int);
    unsigned int backBlocks = backCount / 4;
    unsigned int backTail = backCount % 4;
    unsigned int* backSource = backLast;
    unsigned int* backTarget = backDest;
    unsigned int* backStop = backLast - backBlocks * 4;
    unsigned int* backResult = backDest - backCount;
    unsigned int backValue0, backValue1, backValue2, backValue3;
    for (; backSource != backStop; backSource -= 4, backTarget -= 4)
    {
        backValue0 = backSource[-1];
        backValue1 = backSource[-2];
        backValue2 = backSource[-3];
        backValue3 = backSource[-4];
        backTarget[-1] = backValue0;
        backTarget[-2] = backValue1;
        backTarget[-3] = backValue2;
        backTarget[-4] = backValue3;
    }
    for (; backTail > 0 && backTarget != backResult; --backTail)
    {
        backValue0 = *--backSource;
        *--backTarget = backValue0;
    }
}

namespace fnv_00b169c0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct EUMB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00b169c0
EUMB* __cdecl FUN_00b169c0(EUMB* _First, EUMB* _Last, EUMB* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b169c0

namespace fnv_00b16dc0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (((::fnv_00b16dc0::ElemMOVE *)(::FUN_00b17b40((::CopyElem12 *)(::fnv_00b16dc0::ElemMOVE *)(_Checked_baseS(_First)), (::CopyElem12 *)(::fnv_00b16dc0::ElemMOVE *)(_Checked_baseS(_Last)), (::CopyElem12 *)(_Dest)))));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
struct ElemMOVE
{
    int unk00;
    int unk04;
};
// @fnv 0x00b16dc0
ElemMOVE* __cdecl FUN_00b16dc0(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b16dc0

namespace fnv_00b16ec0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct E6EC0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00b16ec0
E6EC0* __cdecl FUN_00b16ec0(E6EC0* _First, E6EC0* _Last, E6EC0* _Dest, random_access_iterator_tagS _First_dest_cat,
                            _Undefined_move_tagS, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
}

// namespace fnv_00b16ec0

inline float keyOf(SortEntry* entry)
{
    return entry->key;
}

struct SortPred
{
    bool operator()(SortEntry* left, SortEntry* right) const
    {
        return keyOf(left) < keyOf(right);
    }
};

struct SortPredicate
{
    __forceinline bool operator()(SortEntry* const& left, SortEntry* const& right) const
    {
        float firstKey = left->key;
        float secondKey = right->key;
        return firstKey > secondKey;
    }
};

struct PartitionBounds
{
    SortEntry** first;
    SortEntry** second;
    __forceinline PartitionBounds(SortEntry** const& left, SortEntry** const& right) : first(left), second(right)
    {}
};

__forceinline void SwapEntries(SortEntry** left, SortEntry** right)
{
    if (left != right)
    {
        SortEntry* temp = *left;
        *left = *right;
        *right = temp;
    }
}

// @fnv 0x00b16f70
PartitionBounds __cdecl FUN_00b16f70(SortEntry** _First, SortEntry** _Last, SortPredicate _Pred)
{
    SortPredicate compare = _Pred;
    SortEntry** _Mid = _First + (_Last - _First) / 2;
    ::FUN_00b17530(_First, _Mid, _Last - 1, (*(::SortPred *)&(const ::SortPredicate &)(_Pred)));
    SortEntry** _Pfirst = _Mid;
    SortEntry** _Plast = _Pfirst + 1;
    while (_First < _Pfirst && !compare(*(_Pfirst - 1), *_Pfirst) && !compare(*_Pfirst, *(_Pfirst - 1)))
        --_Pfirst;
    while (_Plast < _Last && !compare(*_Plast, *_Pfirst) && !compare(*_Pfirst, *_Plast))
        ++_Plast;
    SortEntry** _Gfirst = _Plast;
    SortEntry** _Glast = _Pfirst;
    for (;;)
    {
        for (; _Gfirst < _Last; ++_Gfirst)
            if (compare(*_Pfirst, *_Gfirst))
                ;
            else if (compare(*_Gfirst, *_Pfirst))
                break;
            else
                SwapEntries(_Plast++, _Gfirst);
        for (; _First < _Glast; --_Glast)
            if (compare(*(_Glast - 1), *_Pfirst))
                ;
            else if (compare(*_Pfirst, *(_Glast - 1)))
                break;
            else
                SwapEntries(--_Pfirst, _Glast - 1);
        if (_Glast == _First && _Gfirst == _Last)
            return PartitionBounds(_Pfirst, _Plast);
        if (_Glast == _First)
        {
            if (_Plast != _Gfirst)
                SwapEntries(_Pfirst, _Plast);
            ++_Plast;
            SwapEntries(_Pfirst++, _Gfirst++);
        }
        else if (_Gfirst == _Last)
        {
            if (--_Glast != --_Pfirst)
                SwapEntries(_Glast, _Pfirst);
            SwapEntries(_Pfirst, --_Plast);
        }
        else
            SwapEntries(_Gfirst++, --_Glast);
    }
}

namespace fnv_00b174c0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _Iter> inline typename _Iter_valueS<_Iter>::value_type* _Val_typeS(_Iter)
{
    return (0);
}
template <class _Iter> inline int* _Dist_typeS(_Iter)
{
    return (0);
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Push_heapS(_RanIt _First, _Diff _Hole, _Diff _Top, _Ty _Val, _Pr _Pred)
{
    for (_Diff _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Adjust_heapS(_RanIt _First, _Diff _Hole, _Diff _Bottom, _Ty _Val, _Pr _Pred)
{
    _Diff _Top = _Hole;
    _Diff _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    _Push_heapS(_First, _Hole, _Top, _Val, _Pred);
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Pop_heapS(_RanIt _First, _RanIt _Last, _RanIt _Dest, _Ty _Val, _Pr _Pred, _Diff*)
{
    *_Dest = *_First;
    _Adjust_heapS(_First, _Diff(0), _Diff(_Last - _First), _Val, _Pred);
}
template <class _RanIt, class _Ty, class _Pr> inline void _Pop_heap_0S(_RanIt _First, _RanIt _Last, _Pr _Pred, _Ty*)
{
    _Pop_heapS(_First, _Last - 1, _Last - 1, _Ty(*(_Last - 1)), _Pred, _Dist_typeS(_First));
}
template <class _RanIt, class _Pr> inline void pop_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
    if (1 < _Last - _First)
        _Pop_heap_0S(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Val_typeS(_First));
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Make_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred, _Diff*, _Ty*)
{
    _Diff _Bottom = _Last - _First;
    for (_Diff _Hole = _Bottom / 2; 0 < _Hole;)
    {
        --_Hole;
        ::fnv_00b17980::FUN_00b17980((::fnv_00b17980::NodeD10 **)(_First), _Hole, _Bottom, (::fnv_00b17980::NodeD10 *)(::fnv_00b174c0::NodeD10 *)(_Ty(*(_First + _Hole))), (*(::fnv_00b17980::CompareD10 *)&(const ::fnv_00b174c0::CompareD10 &)(_Pred)));
    }
}
template <class _RanIt, class _Pr> inline void make_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
    if (1 < _Last - _First)
        _Make_heapS(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Dist_typeS(_First), _Val_typeS(_First));
}
struct NodeD10
{
    float GetKey() const
    {
        return m_fKey;
    }
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
    float m_fKey;
};
struct CompareD10
{
    bool operator()(const NodeD10* pkA, const NodeD10* pkB) const
    {
        return pkA->GetKey() > pkB->GetKey();
    }
};

// @fnv 0x00b174c0
void __cdecl FUN_00b174c0(NodeD10** _First, NodeD10** _Last, CompareD10 _Pred)
{
    if (1 < _Last - _First)
        _Make_heapS(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Dist_typeS(_First), _Val_typeS(_First));
}
}

// namespace fnv_00b174c0


template <class T> inline void swapValues(T& left, T& right)
{
    if (&left != &right)
    {
        T tmp = left;
        left = right;
        right = tmp;
    }
}

template <class It1, class It2> inline void iterSwap(It1 left, It2 right)
{
    swapValues(*left, *right);
}

template <class It, class Pr> inline void med3(It a, It b, It c, Pr pred)
{
    if (pred(*b, *a))
        iterSwap(b, a);
    if (pred(*c, *b))
        iterSwap(c, b);
    if (pred(*b, *a))
        iterSwap(b, a);
}

// @fnv 0x00b17530
void FUN_00b17530(SortEntry** first, SortEntry** mid, SortEntry** last, SortPred pred)
{
    if (40 < last - first)
    {
        int step = ((int)(last - first) + 1) / 8;
        ::SortThreeEntries(first, first + step, first + 2 * step);
        ::SortThreeEntries(mid - step, mid, mid + step);
        ::SortThreeEntries(last - 2 * step, last - step, last);
        ::SortThreeEntries(first + step, mid, last - step);
    }
    else
    {
        ::SortThreeEntries(first, mid, last);
    }
}

namespace fnv_00b17630 {
struct SortItem
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
    float key;
    float GetKey() const
    {
        return key;
    }
};
struct UnchangedBaseTag
{
};
struct RandomTag
{
};
struct ScalarTag
{
};
struct RangeTag
{
};
template <class T> inline T checkedBase(T& it, UnchangedBaseTag)
{
    return it;
}
template <class T> inline T checkedBase(T& it)
{
    UnchangedBaseTag tag;
    return checkedBase(it, tag);
}
template <class T, class U> inline RandomTag iterRandom(const T&, const U&)
{
    RandomTag category;
    return category;
}
template <class T, class U> inline ScalarTag ptrCategory(T&, U&)
{
    ScalarTag category;
    return category;
}
int __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);
template <class T, class U, class Category>
inline U copyBackwardOpt(T first, T last, U dest, Category, ScalarTag, RangeTag)
{
    int offset = last - first;
    U result = dest - offset;
    if (offset > 0)
        FUN_00ec7ce3(&*result, offset * sizeof(*first), &*first, offset * sizeof(*first));
    return result;
}
inline SortItem** __cdecl FUN_00b17ac0(SortItem** first, SortItem** last, SortItem** dest)
{
    return copyBackwardOpt(checkedBase(first), checkedBase(last), dest, iterRandom(first, dest),
                           ptrCategory(first, dest), RangeTag());
}

inline bool keyBefore(SortItem* left, SortItem* right)
{
    return left->GetKey() > right->GetKey();
}
// @fnv 0x00b17630
void __cdecl FUN_00b17630(SortItem** first, SortItem** last)
{
    if (first != last)
    {
        SortItem** _Next = first;
        while (++_Next != last)
        {
            SortItem** _Next1 = _Next;
            SortItem* _Val = *_Next;
            if (keyBefore(_Val, *first))
            {
                FUN_00b17ac0(first, _Next, ++_Next1);
                *first = _Val;
            }
            else
            {
                SortItem** _First1 = _Next1;
                for (; keyBefore(_Val, *--_First1); _Next1 = _First1)
                {
                    *_Next1 = *_First1;
                }
                *_Next1 = _Val;
            }
        }
    }
}
}

// namespace fnv_00b17630

namespace fnv_00b17980 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _Iter> inline typename _Iter_valueS<_Iter>::value_type* _Val_typeS(_Iter)
{
    return (0);
}
template <class _Iter> inline int* _Dist_typeS(_Iter)
{
    return (0);
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Push_heapS(_RanIt _First, _Diff _Hole, _Diff _Top, _Ty _Val, _Pr _Pred)
{
    for (_Diff _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Adjust_heapS(_RanIt _First, _Diff _Hole, _Diff _Bottom, _Ty _Val, _Pr _Pred)
{
    _Diff _Top = _Hole;
    _Diff _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    _Push_heapS(_First, _Hole, _Top, _Val, _Pred);
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Pop_heapS(_RanIt _First, _RanIt _Last, _RanIt _Dest, _Ty _Val, _Pr _Pred, _Diff*)
{
    *_Dest = *_First;
    _Adjust_heapS(_First, _Diff(0), _Diff(_Last - _First), _Val, _Pred);
}
template <class _RanIt, class _Ty, class _Pr> inline void _Pop_heap_0S(_RanIt _First, _RanIt _Last, _Pr _Pred, _Ty*)
{
    _Pop_heapS(_First, _Last - 1, _Last - 1, _Ty(*(_Last - 1)), _Pred, _Dist_typeS(_First));
}
template <class _RanIt, class _Pr> inline void pop_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
    if (1 < _Last - _First)
        _Pop_heap_0S(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Val_typeS(_First));
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Make_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred, _Diff*, _Ty*)
{
    _Diff _Bottom = _Last - _First;
    for (_Diff _Hole = _Bottom / 2; 0 < _Hole;)
    {
        --_Hole;
        _Adjust_heapS(_First, _Hole, _Bottom, _Ty(*(_First + _Hole)), _Pred);
    }
}
template <class _RanIt, class _Pr> inline void make_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
    if (1 < _Last - _First)
        _Make_heapS(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Dist_typeS(_First), _Val_typeS(_First));
}
struct NodeD10
{
    float GetKey() const
    {
        return m_fKey;
    }
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
    float m_fKey;
};
struct CompareD10
{
    bool operator()(const NodeD10* pkA, const NodeD10* pkB) const
    {
        return pkA->GetKey() > pkB->GetKey();
    }
};

// @fnv 0x00b17980
void __cdecl FUN_00b17980(NodeD10** _First, int _Hole, int _Bottom, NodeD10* _Val, CompareD10 _Pred)
{
    int _Top = _Hole;
    int _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    _Push_heapS(_First, _Hole, _Top, _Val, _Pred);
}
}

// namespace fnv_00b17980

namespace fnv_00b17a60 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _Iter> inline typename _Iter_valueS<_Iter>::value_type* _Val_typeS(_Iter)
{
    return (0);
}
template <class _Iter> inline int* _Dist_typeS(_Iter)
{
    return (0);
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Push_heapS(_RanIt _First, _Diff _Hole, _Diff _Top, _Ty _Val, _Pr _Pred)
{
    for (_Diff _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Adjust_heapS(_RanIt _First, _Diff _Hole, _Diff _Bottom, _Ty _Val, _Pr _Pred)
{
    _Diff _Top = _Hole;
    _Diff _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    _Push_heapS(_First, _Hole, _Top, _Val, _Pred);
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Pop_heapS(_RanIt _First, _RanIt _Last, _RanIt _Dest, _Ty _Val, _Pr _Pred, _Diff*)
{
    *_Dest = *_First;
    ::fnv_00b17980::FUN_00b17980((::fnv_00b17980::NodeD10 **)(_First), _Diff(0), _Diff(_Last - _First), (::fnv_00b17980::NodeD10 *)(_Val), (*(::fnv_00b17980::CompareD10 *)&(const ::fnv_00b17a60::CompareD10 &)(_Pred)));
}
template <class _RanIt, class _Ty, class _Pr> inline void _Pop_heap_0S(_RanIt _First, _RanIt _Last, _Pr _Pred, _Ty*)
{
    _Pop_heapS(_First, _Last - 1, _Last - 1, _Ty(*(_Last - 1)), _Pred, _Dist_typeS(_First));
}
template <class _RanIt, class _Pr> inline void pop_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
    if (1 < _Last - _First)
        _Pop_heap_0S(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Val_typeS(_First));
}
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Make_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred, _Diff*, _Ty*)
{
    _Diff _Bottom = _Last - _First;
    for (_Diff _Hole = _Bottom / 2; 0 < _Hole;)
    {
        --_Hole;
        _Adjust_heapS(_First, _Hole, _Bottom, _Ty(*(_First + _Hole)), _Pred);
    }
}
template <class _RanIt, class _Pr> inline void make_heapS(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
    if (1 < _Last - _First)
        _Make_heapS(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Dist_typeS(_First), _Val_typeS(_First));
}
struct NodeD10
{
    float GetKey() const
    {
        return m_fKey;
    }
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
    float m_fKey;
};
struct CompareD10
{
    bool operator()(const NodeD10* pkA, const NodeD10* pkB) const
    {
        return pkA->GetKey() > pkB->GetKey();
    }
};

// @fnv 0x00b17a60
void __cdecl FUN_00b17a60(NodeD10** _First, NodeD10** _Last, CompareD10 _Pred)
{
    if (1 < _Last - _First)
        _Pop_heap_0S(_Checked_baseS(_First), _Checked_baseS(_Last), _Pred, _Val_typeS(_First));
}
}

// namespace fnv_00b17a60

namespace fnv_00b17c20 {
struct ElQ
{
    int m[6];
};
__forceinline void Del(ElQ* p, unsigned int f)
{
    p->~ElQ();
}
inline void Construct(ElQ* p, const ElQ& v)
{
    void* vp = p;
    ::new (vp) ElQ(v);
}
// @fnv 0x00b17c20
ElQ* FUN_00b17c20(ElQ* first, ElQ* last, ElQ* dest)
{
    ElQ* next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            Construct(dest, *first);
    }
    catch (...)
    {
        for (; next != dest; ++next)
            Del(next, 0);
        throw;
    }
    return dest;
}
}

// namespace fnv_00b17c20

struct NodeD10
{
    float GetKey() const
    {
        return m_fKey;
    }
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
    float m_fKey;
};

struct CompareD10
{
    bool operator()(const NodeD10* pkA, const NodeD10* pkB) const
    {
        return pkA->GetKey() > pkB->GetKey();
    }
};

// @fnv 0x00b17d10
void __cdecl FUN_00b17d10(NodeD10** _First, int _Hole, int _Top, NodeD10* _Val, CompareD10 _Pred)
{
    for (int _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}

namespace fnv_00b17db0 {

struct AuxB
{
    const void* container;
    explicit AuxB(const void* owner) : container(owner)
    {}
};

struct AllocB
{
    AllocB()
    {}
    AllocB(const AllocB&)
    {}
    void* allocate(unsigned int count)
    {
        return ((void *)(::FUN_0044d670(count)));
    }
    void deallocate(void* ptr, unsigned int)
    {
        operator delete(ptr);
    }
    unsigned int max_size() const
    {
        unsigned int count = (unsigned int)(-1) / sizeof(int);
        return (0 < count ? count : 1);
    }
};

struct ContBase
{
    AuxB* owned;
    ContBase()
    {}
    ~ContBase()
    {}
};

struct AuxAlloc : ContBase
{
    AllocB alaux;
    explicit AuxAlloc(AllocB al) : alaux(al)
    {
        owned = new (alaux.allocate(1)) AuxB(this);
    }
    ~AuxAlloc()
    {
        alaux.deallocate(owned, 1);
    }
};

struct VecVal : AuxAlloc
{
    AllocB alval;
    int* first;
    int* last;
    int* endp;
    __forceinline explicit VecVal(AllocB al = AllocB()) : AuxAlloc(al), alval(al)
    {}
    static void xlen();
    unsigned int max_size() const
    {
        return alval.max_size();
    }
    bool buy(unsigned int cap);
};

inline bool VecVal::buy(unsigned int cap)
{
    unsigned int s00, s01, s02, s03, s04, s05, s06, s07, s08, s09;
    unsigned int s10, s11, s12, s13, s14, s15, s16, s17, s18, s19;
    unsigned int s20, s21, s22, s23, s24, s25, s26, s27, s28, s29;
    s00 = cap;
    s01 = s00;
    s02 = s01;
    s03 = s02;
    s04 = s03;
    s05 = s04;
    s06 = s05;
    s07 = s06;
    s08 = s07;
    s09 = s08;
    s10 = s09;
    s11 = s10;
    s12 = s11;
    s13 = s12;
    s14 = s13;
    s15 = s14;
    s16 = s15;
    s17 = s16;
    s18 = s17;
    s19 = s18;
    s20 = s19;
    s21 = s20;
    s22 = s21;
    s23 = s22;
    s24 = s23;
    s25 = s24;
    s26 = s25;
    s27 = s26;
    s28 = s27;
    s29 = s28;
    s00 = s29;
    s01 = s00;
    s02 = s01;
    s03 = s02;
    s04 = s03;
    s05 = s04;
    s06 = s05;
    s07 = s06;
    s08 = s07;
    s09 = s08;
    s10 = s09;
    s11 = s10;
    s12 = s11;
    s13 = s12;
    s14 = s13;
    s15 = s14;
    s16 = s15;
    s17 = s16;
    s18 = s17;
    s19 = s18;
    first = 0;
    last = 0;
    endp = 0;
    if (cap == 0)
        return false;
    if (max_size() < cap)
        xlen();
    first = (int*)alval.allocate(cap);
    last = first;
    endp = first + s00;
    return s29 == cap;
}

struct FUN_00b17db0 : VecVal
{
    FUN_00b17db0();
};

// @fnv 0x00b17db0
FUN_00b17db0::FUN_00b17db0()
{
    reinterpret_cast<::FUN_00b17e90_cls *>(this)->ResizeArray(0);
}
}

// namespace fnv_00b17db0

namespace fnv_00b0f3c0 {
struct ScalarPointerTag
{
};
struct RangeCheckedTag
{
};
struct FillAllocator
{
};

template <class _T1, class _T2> inline ScalarPointerTag PointerCategory(const _T1&, const _T2&)
{
    ScalarPointerTag _Cat;
    return _Cat;
}

struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomAccessTag : BidirectionalTag
{
};

template <class _OutIt> inline RandomAccessTag IteratorCategory(const _OutIt&)
{
    RandomAccessTag _Cat;
    return _Cat;
}
template <class _OutIt, class _Diff, class _Ty>
inline void FillLoop(_OutIt _First, _Diff _Count, const _Ty& _Val, RangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
struct UnchangedBaseTag
{
};

template <class _Iter> inline _Iter CheckedBase(_Iter& _It, UnchangedBaseTag)
{
    return _It;
}

template <class _Iter> inline _Iter CheckedBase(_Iter& _It)
{
    UnchangedBaseTag _Base_tag;
    return CheckedBase(_It, _Base_tag);
}

template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void FillByCategory(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, RangeCheckedTag)
{
    // Computing the end validates the range for checked random-access iterators.
    _OutIt _Last = _First + _Count;
    (void)_Last;
    FillLoop(CheckedBase(_First), _Count, _Val, RangeCheckedTag());
}
inline void __cdecl FUN_00b10cf0(char* _First, unsigned int _Count, const char& _Val)
{
    FillByCategory(_First, _Count, _Val, IteratorCategory(_First), RangeCheckedTag());
}

template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void UninitializedFillDispatch(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, ScalarPointerTag,
                                      RangeCheckedTag)
{
    FUN_00b10cf0(_First, _Count, _Val);
}

template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void UninitializedFill(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    UninitializedFillDispatch(_First, _Count, _Val, _Al, PointerCategory(_First, _First), RangeCheckedTag());
}

struct ByteFillHost
{
    FillAllocator allocator;
    char* FUN_00b0f3c0(char* _Ptr, unsigned int _Count, const char& _Val);
};

// @fnv 0x00b0f3c0
char* ByteFillHost::FUN_00b0f3c0(char* _Ptr, unsigned int _Count, const char& _Val)
{
    UninitializedFill(_Ptr, _Count, _Val, allocator);
    return _Ptr + _Count;
}
}

// namespace fnv_00b0f3c0

struct ContainerBaseAuxX10670
{
};

class AuxContX10670
{
  public:
    const ContainerBaseAuxX10670* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX10670* _Mycontainer;
};

class IteratorBaseAuxX10670
{
  public:
    const ContainerBaseAuxX10670* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX10670* _Myaux;
};

struct ElemX10670
{
    char unk00;
};

struct VectorX10670 : public ContainerBaseAuxX10670
{
    AuxContX10670* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX10670* _Myfirst;
    ElemX10670* _Mylast;
    ElemX10670* _Myend;
};

class FUN_00b10670_It : public IteratorBaseAuxX10670
{
  public:
    FUN_00b10670_It& FUN_00b10670(int _Off);
    ElemX10670* _Myptr;
};

// @fnv 0x00b10670
FUN_00b10670_It& FUN_00b10670_It::FUN_00b10670(int _Off)
{
    if (!(this->_Has_container()))
        std::abort();
    do
    {
    } while (0);
    if (!(_Myptr + _Off <= ((VectorX10670*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorX10670*)this->_Getmycont())->_Myfirst))
        std::abort();
    do
    {
    } while (0);
    _Myptr += _Off;
    return *this;
}

namespace fnv_00b10730 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Different_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Different_checked_iterator_base_type_tagS)
{
    return _It._Checked_iterator_base();
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        fnv::crt::memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    typedef const _Ty* _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return _Myptr;
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Ty> struct _Checked_iterator_base_helperS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Different_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef const _Ty* _Checked_iterator_base_type;
};
template <class _Ty, class _T2> struct _Ptr_cat_helperS<_Vector_const_iteratorS<_Ty>, _T2>
{
    typedef typename _Ptr_cat_helperS<_Ty*, _T2>::_Ptr_cat _Ptr_cat;
};
template <class _Ty> struct _Iter_valueS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Vector_const_iteratorS<_Ty> >
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
// @fnv 0x00b10730
unsigned char* __cdecl FUN_00b10730(unsigned char* _First, unsigned char* _Last, unsigned char* _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b10730

namespace fnv_00b107a0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        fnv::crt::memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
// @fnv 0x00b107a0
unsigned char* __cdecl FUN_00b107a0(unsigned char* _First, unsigned char* _Last, unsigned char* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b107a0

namespace fnv_00b10890 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct EUMB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00b10890
EUMB* __cdecl FUN_00b10890(EUMB* _First, EUMB* _Last, EUMB* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b10890

namespace fnv_00b10a60 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        fnv::crt::memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
// @fnv 0x00b10a60
unsigned char* __cdecl FUN_00b10a60(unsigned char* _First, unsigned char* _Last, unsigned char* _Dest,
                                    allocatorS<unsigned char>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b10a60

namespace fnv_00b10b00 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
struct ElemMOVE
{
    int unk00;
    int unk04;
};
// @fnv 0x00b10b00
ElemMOVE* __cdecl FUN_00b10b00(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b10b00

namespace fnv_00b10b80 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct E0B80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
// @fnv 0x00b10b80
E0B80* __cdecl FUN_00b10b80(E0B80* _First, E0B80* _Last, E0B80* _Dest, random_access_iterator_tagS _First_dest_cat,
                            _Undefined_move_tagS, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
}

// namespace fnv_00b10b80

namespace fnv_00b10d60 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        fnv::crt::memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
// @fnv 0x00b10d60
unsigned char* __cdecl FUN_00b10d60(unsigned char* _First, unsigned char* _Last, unsigned char* _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b10d60


struct S_00b134d0_Mat : FUN_00b12af0_shell
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;

    S_00b134d0_Mat Multiply(const S_00b134d0_Mat& rhs) const
    {
        S_00b134d0_Mat kResult;
        kResult.m00 = m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20;
        kResult.m01 = m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21;
        kResult.m02 = m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22;
        kResult.m10 = m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20;
        kResult.m11 = m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21;
        kResult.m12 = m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22;
        kResult.m20 = m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20;
        kResult.m21 = m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21;
        kResult.m22 = m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22;
        return kResult;
    }

    void FUN_00b134d0(float angle);
};

// @fnv 0x00b134d0
void S_00b134d0_Mat::FUN_00b134d0(float angle)
{
    S_00b134d0_Mat kRotationBasis;
    ::FUN_00b12af0((::FUN_00b12af0_shell *)&(kRotationBasis));

    float fCos = +((float)::std::cos((double)(float)(angle / DAT_010a4d90)));
    float fSin = +((float)::std::sin((double)(float)(angle / DAT_010a4d90)));

    kRotationBasis.m00 = fCos;
    kRotationBasis.m01 = 0.0f;
    kRotationBasis.m02 = -fSin;
    kRotationBasis.m10 = 0.0f;
    kRotationBasis.m11 = 1.0f;
    kRotationBasis.m12 = 0.0f;
    kRotationBasis.m20 = fSin;
    kRotationBasis.m21 = 0.0f;
    kRotationBasis.m22 = fCos;

    *this = kRotationBasis.Multiply(*this);
}

namespace fnv_00b167e0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    ::fnv_00b36b10::FUN_00b36b10((unsigned int *)(_First), _Count, (const unsigned int &)(_Val));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
class FUN_00b167e0_Vector : public vectorS<int>
{
  public:
    pointer FUN_00b167e0(pointer _Ptr, size_type _Count, const int& _Val);
};

// @fnv 0x00b167e0
FUN_00b167e0_Vector::pointer FUN_00b167e0_Vector::FUN_00b167e0(pointer _Ptr, size_type _Count, const int& _Val)
{
    unchecked_uninitialized_fill_nS(_Ptr, _Count, _Val, this->_Alval);
    return (_Ptr + _Count);
}
}

// namespace fnv_00b167e0

namespace fnv_00b16a10 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct EUMB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00b16a10
EUMB* __cdecl FUN_00b16a10(EUMB* _First, EUMB* _Last, EUMB* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b16a10

namespace fnv_00b16a60 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        fnv::crt::memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
// @fnv 0x00b16a60
int* __cdecl FUN_00b16a60(int* _First, int* _Last, int* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b16a60

namespace fnv_00b16e40 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
struct ElemMOVE;
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (((::fnv_00b16e40::ElemMOVE *)(::fnv_00b17c20::FUN_00b17c20((::fnv_00b17c20::ElQ *)(::fnv_00b16e40::ElemMOVE *)(_Checked_baseS(_First)), (::fnv_00b17c20::ElQ *)(::fnv_00b16e40::ElemMOVE *)(_Checked_baseS(_Last)), (::fnv_00b17c20::ElQ *)(_Dest)))));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
struct ElemMOVE
{
    int unk00;
    int unk04;
};
// @fnv 0x00b16e40
ElemMOVE* __cdecl FUN_00b16e40(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b16e40

namespace fnv_00b177e0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        fnv::crt::memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
// @fnv 0x00b177e0
int* __cdecl FUN_00b177e0(int* _First, int* _Last, int* _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b177e0

namespace fnv_00b17ac0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        fnv::crt::memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
// @fnv 0x00b17ac0
int* __cdecl FUN_00b17ac0(int* _First, int* _Last, int* _Dest)
{
    return (_Copy_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
}

// namespace fnv_00b17ac0

class FUN_00b00bc0_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual bool v1c(void* value);
    bool m_04;
    inline bool IsEnabled() const
    {
        return m_04;
    }
    static inline void* Get(void** value)
    {
        return *value;
    }
    bool FUN_00b00bc0(void** value);
};

// @fnv 0x00b00bc0
bool FUN_00b00bc0_cls::FUN_00b00bc0(void** value)
{
    return IsEnabled() && Get(value) ? v1c(Get(value)) : false;
}

namespace fnv_00b0e730 {
void allocationError();
void lengthError();
namespace std {
class exception
{
  public:
    exception();
    exception(const char* const&);
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;

  private:
    const char* message;
    int ownsMessage;
};
class bad_alloc : public exception
{
  public:
    bad_alloc(const char* message) throw() : exception(message)
    {}
    virtual ~bad_alloc() throw()
    {}
};
template <class T> inline T* allocateElements(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(T))
        throw bad_alloc(0);
    return (T*)operator new(count * sizeof(T));
}
template <class T> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    template <class U> allocator(const allocator<U>&) throw()
    {}
    T* allocate(unsigned int count)
    {
        return allocateElements(count, (T*)0);
    }
    void deallocate(T* p, unsigned int)
    {
        operator delete(p);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
}
unsigned int __cdecl stringLength(const char*);
int __cdecl stringCopy(void*, unsigned int, const void*, unsigned int);
namespace std {
template <class E> struct char_traits
{
    typedef E char_type;
    static unsigned int length(const E* p)
    {
        return stringLength(p);
    }
    static void assign(E& a, const E& b)
    {
        a = b;
    }
    static E* _Copy_s(E* dst, unsigned int size, const E* src, unsigned int count)
    {
        stringCopy(dst, size, src, count);
        return dst;
    }
};
struct SecureTraitsTag
{
};
template <class Tr> inline SecureTraitsTag traitsCategory()
{
    SecureTraitsTag secure;
    return secure;
}
namespace TraitsHelper {
template <class Tr>
inline typename Tr::char_type* copy_s(typename Tr::char_type* dst, unsigned int size, const typename Tr::char_type* src,
                                      unsigned int count, SecureTraitsTag)
{
    return Tr::_Copy_s(dst, size, src, count);
}
template <class Tr>
inline typename Tr::char_type* copy_s(typename Tr::char_type* dst, unsigned int size, const typename Tr::char_type* src,
                                      unsigned int count)
{
    return copy_s<Tr>(dst, size, src, count, traitsCategory<Tr>());
}
}
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
template <class E, class A> struct StringStorage : StringBase
{
    A alloc;
    StringStorage(A a = A()) : alloc(a)
    {}
};
template <class E, class Tr, class A> class basic_string : public StringStorage<E, A>
{
  public:
    union Buffer
    {
        E data[16 / sizeof(E)];
        E* ptr;
    } bx;
    unsigned int mySize;
    unsigned int myRes;
    basic_string(const E* p) : StringStorage<E, A>()
    {
        _Tidy();
        assign(p);
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    basic_string& assign(const E* p)
    {
        return assign(p, Tr::length(p));
    }
    basic_string& assign(const E* p, unsigned int count)
    {
        if (_Inside(p))
            return assign(*this, p - _Myptr(), count);
        if (_Grow(count))
        {
            TraitsHelper::copy_s<Tr>(_Myptr(), myRes, p, count);
            _Eos(count);
        }
        return *this;
    }
    unsigned int size() const
    {
        return mySize;
    }
    basic_string& erase(unsigned int off = 0, unsigned int count = (unsigned int)-1);
    basic_string& assign(const basic_string& right, unsigned int off, unsigned int count)
    {
        if (right.size() < off)
            StringBase::_Xran();
        unsigned int num = right.size() - off;
        if (count < num)
            num = count;
        if (this == &right)
            erase(off + num), erase(0, off);
        else if (_Grow(num))
        {
            TraitsHelper::copy_s<Tr>(_Myptr(), myRes, right._Myptr() + off, num);
            _Eos(num);
        }
        return *this;
    }
    unsigned int max_size() const
    {
        unsigned int num = this->alloc.max_size();
        return num <= 1 ? 1 : num - 1;
    }

  protected:
    E* _Myptr()
    {
        return 16 / sizeof(E) <= myRes ? bx.ptr : bx.data;
    }
    const E* _Myptr() const
    {
        return 16 / sizeof(E) <= myRes ? bx.ptr : bx.data;
    }
    void _Eos(unsigned int size)
    {
        Tr::assign(_Myptr()[mySize = size], E());
    }
    bool _Inside(const E* p)
    {
        if (p == 0 || p < _Myptr() || _Myptr() + mySize <= p)
            return false;
        else
            return true;
    }
    void _Copy(unsigned int size, unsigned int oldlen)
    {
        unsigned int res = size | 15;
        if (max_size() < res)
            res = size;
        else if (res / 3 < myRes / 2 && myRes <= max_size() - myRes / 2)
            res = myRes + myRes / 2;
        E* p = 0;
        try
        {
            p = this->alloc.allocate(res + 1);
        }
        catch (...)
        {
            res = size;
            try
            {
                p = this->alloc.allocate(res + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < oldlen)
            TraitsHelper::copy_s<Tr>(p, res + 1, _Myptr(), oldlen);
        _Tidy(true);
        bx.ptr = p;
        myRes = res;
        _Eos(oldlen);
    }
    bool _Grow(unsigned int size, bool trim = false)
    {
        if (max_size() < size)
            StringBase::_Xlen();
        if (myRes < size)
            _Copy(size, mySize);
        else if (trim && size < 16 / sizeof(E))
            _Tidy(true, size < mySize ? size : mySize);
        else if (size == 0)
            _Eos(0);
        return 0 < size;
    }
    void _Tidy(bool built = false, unsigned int size = 0)
    {
        if (!built)
            ;
        else if (16 / sizeof(E) <= myRes)
        {
            E* p = bx.ptr;
            if (0 < size)
                TraitsHelper::copy_s<Tr>(bx.data, 16 / sizeof(E), p, size);
            this->alloc.deallocate(p, myRes + 1);
        }
        myRes = 16 / sizeof(E) - 1;
        _Eos(size);
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
extern char DAT_010173c4[];
namespace std {
class logic_error : public exception
{
    string text;

  public:
    explicit logic_error(const string& message);
    virtual ~logic_error() throw()
    {}
};
class length_error : public logic_error
{
  public:
    explicit length_error(const string& message) : logic_error(message)
    {}
    virtual ~length_error() throw()
    {}
};
}
struct StorageBase;
struct StorageProxy
{
    const StorageBase* container;
    explicit StorageProxy(const StorageBase* p) : container(p)
    {}
};
struct StorageBase
{
    StorageProxy* proxy;
    StorageBase()
    {}
    ~StorageBase()
    {}
};
template <class A> struct ProxyStorage : StorageBase
{
    std::allocator<StorageProxy> proxyAllocator;
    explicit ProxyStorage(A a) : proxyAllocator(a)
    {
        proxy = new (proxyAllocator.allocate(1)) StorageProxy(this);
    }
    ~ProxyStorage()
    {
        proxy->~StorageProxy();
        proxyAllocator.deallocate(proxy, 1);
    }
};
template <class T> struct VectorStorage : ProxyStorage<std::allocator<T> >
{
    std::allocator<T> allocator;
    VectorStorage(std::allocator<T> a = std::allocator<T>()) : ProxyStorage<std::allocator<T> >(a), allocator(a)
    {}
};
struct EmptyTag
{
};
template <class T> inline void destroyRange(T* first, T* last, EmptyTag)
{
    for (; first != last; ++first)
        first->~T();
}
template <class T> inline void destroyElements(T* first, T* last)
{
    EmptyTag tag;
    destroyRange(first, last, tag);
}
template <class T> struct VectorLike : VectorStorage<T>
{
    T* first;
    T* last;
    T* end;
    VectorLike() : VectorStorage<T>()
    {
        reinterpret_cast<::DceVal *>(this)->FUN_00b0e730(0);
    }
    ~VectorLike()
    {
        Tidy();
    }
    void Tidy()
    {
        if (first != 0)
        {
            T* rangeFirst = first;
            T* rangeLast = last;
            T* destroyFirst = rangeFirst;
            T* destroyLast = rangeLast;
            destroyElements(destroyFirst, destroyLast);
            this->allocator.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
// @fnv 0x00b0e730
    bool FUN_00b0e730(unsigned int capacity)
    {
        first = 0, last = 0, end = 0;
        if (capacity == 0)
            return false;
        else if (max_size() < capacity)
            ::xlenb0f::BxVecBase::FUN_00b0fb80();
        else
        {
            first = this->allocator.allocate(capacity);
            last = first;
            end = first + capacity;
        }
        return true;
    }
    unsigned int max_size() const
    {
        return this->allocator.max_size();
    }
    static void _Xlen()
    {
        throw std::length_error(std::string(DAT_010173c4));
    }
};

template struct VectorLike<int>;
}

// namespace fnv_00b0e730

namespace fnv_00b16950 {
void* __cdecl FUN_00b16b60(void* first, void* last, unsigned n, unsigned char cat);
inline void DeadBig()
{
    int a[73];
}
__forceinline bool Has(void* p)
{
    return p != 0;
}
__forceinline bool Same(void* p, void* a)
{
    return p == a;
}
// @fnv 0x00b16950
void* __cdecl FUN_00b16950(void* a, void* b, void* c, void* d, unsigned char cat)
{
    void* h1;
    void* h2;
    if (!(Has(c) && Same(c, a)))
        std::abort();
    unsigned c0 = (unsigned)((int*)d - (int*)b);
    void* pL5 = d;
    void* pF = b;
    DeadBig();
    return FUN_00b16b60(pF, pL5, c0, cat);
}
}

// namespace fnv_00b16950

struct ElQ_ab9bc0
{
    int m[6];
};

struct AlQ_ab9bc0
{
};

struct CatQ_ab9bc0
{
};

struct TagQ_ab9bc0
{
};

struct ElQ_ab9bc0;

inline CatQ_ab9bc0 PtrCat_ab9bc0(ElQ_ab9bc0*&, ElQ_ab9bc0*&)
{
    CatQ_ab9bc0 c;
    return c;
}

void __cdecl FUN_00ac20d0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al, CatQ_ab9bc0,
                          TagQ_ab9bc0);

inline void UFillN_ab9bc0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_ab9bc0(_First, _First), TagQ_ab9bc0());
}

struct VecQ_ab9bc0;

struct CItQ_ab9bc0
{
    void* _Myaux;
    ElQ_ab9bc0* _Myptr;
    CItQ_ab9bc0()
    {}
    CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_ab9bc0& r) const
    {
        return _Myaux == r._Myaux;
    }
    int operator-(const CItQ_ab9bc0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            std::abort();
        return _Myptr - _Right._Myptr;
    }
};

struct ItQ_ab9bc0 : CItQ_ab9bc0
{
    ItQ_ab9bc0()
    {}
    ItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : CItQ_ab9bc0(_Ptr, _Pvector)
    {}
    ItQ_ab9bc0& operator+=(int _Off)
    {
        reinterpret_cast<::FUN_00b16890_It *>(this)->FUN_00b16890(_Off);
        return *this;
    }
    ItQ_ab9bc0 operator+(int _Off) const
    {
        ItQ_ab9bc0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};

struct VecQ_ab9bc0
{
    void* _Myownedaux;
    int m04;
    AlQ_ab9bc0 _Alval;
    char p09[3];
    ElQ_ab9bc0* _Myfirst;
    ElQ_ab9bc0* _Mylast;
    ElQ_ab9bc0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_ab9bc0 begin()
    {
        return ItQ_ab9bc0(_Myfirst, this);
    }
    void FUN_00b157e0(CItQ_ab9bc0 _Where, unsigned int _Count, const ElQ_ab9bc0& _Val);
    ItQ_ab9bc0 end()
    {
        return ItQ_ab9bc0(_Mylast, this);
    }
    ElQ_ab9bc0* _Ufill(ElQ_ab9bc0* _Ptr, unsigned int _Count, const ElQ_ab9bc0& _Val)
    {
        UFillN_ab9bc0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_ab9bc0 FUN_00b154d0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val);
};

inline CItQ_ab9bc0::CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}

// @fnv 0x00b154d0
ItQ_ab9bc0 VecQ_ab9bc0::FUN_00b154d0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b157e0(_Where, 1, _Val);
    return begin() + _Off;
}

typedef int ElQ_aceeb1;

struct AlQ_aceeb1
{
};

struct CatQ_aceeb1
{
};

struct TagQ_aceeb1
{
};

inline CatQ_aceeb1 PtrCat_aceeb1(ElQ_aceeb1*&, ElQ_aceeb1*&)
{
    CatQ_aceeb1 c;
    return c;
}

void __cdecl FUN_00ac20d0(ElQ_aceeb1* _First, unsigned int _Count, const ElQ_aceeb1& _Val, AlQ_aceeb1& _Al, CatQ_aceeb1,
                          TagQ_aceeb1);

inline void UFillN_aceeb1(ElQ_aceeb1* _First, unsigned int _Count, const ElQ_aceeb1& _Val, AlQ_aceeb1& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_aceeb1(_First, _First), TagQ_aceeb1());
}

struct VecQ_aceeb1;

inline void Dead2_r()
{
    int a[2];
}

struct CItQ_aceeb1
{
    void* _Myaux;
    ElQ_aceeb1* _Myptr;
    CItQ_aceeb1()
    {}
    CItQ_aceeb1(ElQ_aceeb1* _Ptr, const VecQ_aceeb1* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_aceeb1& r) const
    {
        return _Myaux == r._Myaux;
    }
    int operator-(const CItQ_aceeb1& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            std::abort();
        return _Myptr - _Right._Myptr;
    }
};

struct ItQ_aceeb1 : CItQ_aceeb1
{
    ItQ_aceeb1()
    {}
    ItQ_aceeb1(ElQ_aceeb1* _Ptr, const VecQ_aceeb1* _Pvector) : CItQ_aceeb1(_Ptr, _Pvector)
    {}
    ItQ_aceeb1& operator+=(int _Off)
    {
        reinterpret_cast<::FUN_00b2e330_It *>(this)->FUN_00b2e330(_Off);
        return *this;
    }
    ItQ_aceeb1 operator+(int _Off) const
    {
        ItQ_aceeb1 _Tmp = *this;
        Dead2_r();
        return (_Tmp += _Off);
    }
};

struct VecQ_aceeb1
{
    void* _Myownedaux;
    int m04;
    AlQ_aceeb1 _Alval;
    char p09[3];
    ElQ_aceeb1* _Myfirst;
    ElQ_aceeb1* _Mylast;
    ElQ_aceeb1* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_aceeb1 begin()
    {
        return ItQ_aceeb1(_Myfirst, this);
    }
    ItQ_aceeb1 end()
    {
        return ItQ_aceeb1(_Mylast, this);
    }
    ElQ_aceeb1* _Ufill(ElQ_aceeb1* _Ptr, unsigned int _Count, const ElQ_aceeb1& _Val)
    {
        UFillN_aceeb1(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_aceeb1 FUN_00b156b0(CItQ_aceeb1 _Where, const ElQ_aceeb1& _Val);
};

inline CItQ_aceeb1::CItQ_aceeb1(ElQ_aceeb1* _Ptr, const VecQ_aceeb1* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}

// @fnv 0x00b156b0
ItQ_aceeb1 VecQ_aceeb1::FUN_00b156b0(CItQ_aceeb1 _Where, const ElQ_aceeb1& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    reinterpret_cast<::ArrayB160 *>(this)->FUN_00b16070((*(::IteratorB160 *)&(const ::CItQ_aceeb1 &)(_Where)), 1, (const unsigned int &)(_Val));
    return begin() + _Off;
}

struct FillIteratorCategory : RandomTag
{
};

inline FillIteratorCategory IteratorCategory(bool* const& first)
{
    FillIteratorCategory category;
    return category;
}

inline void FillN(bool* first, unsigned int count, const bool& value, CheckedTag)
{
    for (; count > 0; --count, ++first)
        *first = value;
}

inline void CheckedFillN(bool* first, unsigned int count, const bool& value, FillIteratorCategory, CheckedTag)
{
    bool* last = first + count;
    (void)last;
    FillN(CheckedBase(first), count, value, CheckedTag());
}

// @fnv 0x00b10cf0
void __cdecl FUN_00b10cf0(bool* first, unsigned int count, const bool& value)
{
    CheckedFillN(first, count, value, IteratorCategory(first), CheckedTag());
}

inline void DeadQ9_b12d50()
{
    int a[9];
}

struct M3_00b12af0
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    M3_00b12af0();
    M3_00b12af0 Multiply(const M3_00b12af0& rhs) const;
};

struct MatrixOwner
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    void FUN_00b12d50(float angle, float x, float y, float z);
};

// @fnv 0x00b12d50
void MatrixOwner::FUN_00b12d50(float angle, float x, float y, float z)
{
    M3_00b12af0 rot;
    float s = (double)(float)::std::sin((double)(float)(angle / DAT_010a4d90));
    float CD = (double)(float)::std::cos((double)(float)(angle / DAT_010a4d90));
    float TQ = 1.0f - CD;
    float u = x;
    float v = y;
    float RW = z;
    rot.m00 = TQ * u * u + CD;
    rot.m01 = TQ * u * v + s * RW;
    rot.m02 = TQ * u * RW - s * v;
    rot.m10 = TQ * u * v - s * RW;
    rot.m11 = TQ * v * v + CD;
    rot.m12 = TQ * v * RW + s * u;
    rot.m20 = TQ * u * RW + s * v;
    rot.m21 = TQ * v * RW - s * u;
    rot.m22 = TQ * RW * RW + CD;
    *(M3_00b12af0*)this = M3_00b12af0(rot.Multiply(*(M3_00b12af0*)this));
    DeadQ9_b12d50();
}

inline float sortKey(SortEntry* entry)
{
    return entry->key;
}

struct SortPred_b16b60
{
    bool operator()(SortEntry* a, SortEntry* b) const
    {
        return sortKey(a) < sortKey(b);
    }
};

template <class A, class B> struct pair
{
    A first;
    B second;
    pair() : first(A()), second(B())
    {}
    pair(const A& a, const B& b) : first(a), second(b)
    {}
};

template <class T> inline T* _Val_type(T*)
{
    return 0;
}

template <class T> inline int* _Dist_type(T*)
{
    return 0;
}

template <class It> struct ItValue;

template <class T> struct ItValue<T*>
{
    typedef T type;
};

template <class It> inline void iter_swap(It a, It b)
{
    if (a != b)
    {
        typename ItValue<It>::type tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

struct RandomIteratorTag
{
};

struct ScalarPointerTag
{
};

struct CheckedRangeTag
{
};

template <class A, class B> inline RandomIteratorTag iteratorCategory(const A&, const B&)
{
    RandomIteratorTag category;
    return category;
}

template <class A, class B> inline ScalarPointerTag pointerCategory(A&, B&)
{
    ScalarPointerTag category;
    return category;
}

void* secureMemmove(void*, unsigned int, const void*, unsigned int);

template <class It, class Cat>
inline It copyBackward(It first, It last, It dest, Cat, ScalarPointerTag, CheckedRangeTag)
{
    int count = last - first;
    It result = dest - count;
    if (count > 0)
        secureMemmove(&*result, count * sizeof(*first), &*first, count * sizeof(*first));
    return result;
}

template <class It> inline It unchecked_copy_backward(It first, It last, It dest)
{
    return copyBackward(CheckedBase(first), CheckedBase(last), dest, iteratorCategory(first, dest),
                        pointerCategory(first, dest), CheckedRangeTag());
}

// TEMPLATE FUNCTION push_heap WITH PRED
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Push_heap(_RanIt _First, _Diff _Hole, _Diff _Top, _Ty _Val, _Pr _Pred)
{  // percolate _Hole to _Top or where _Val belongs, using operator<
    for (_Diff _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {  // move _Hole up to parent
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }

    *(_First + _Hole) = _Val;  // drop _Val into final hole
}

template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Adjust_heap(_RanIt _First, _Diff _Hole, _Diff _Bottom, _Ty _Val, _Pr _Pred)
{  // percolate _Hole to _Bottom, then push _Val, using _Pred
    _Diff _Top = _Hole;
    _Diff _Idx = 2 * _Hole + 2;

    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {  // move _Hole down to larger child
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }

    if (_Idx == _Bottom)
    {  // only child at bottom, move _Hole down to it
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    _Push_heap(_First, _Hole, _Top, _Val, _Pred);
}

template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Pop_heap(_RanIt _First, _RanIt _Last, _RanIt _Dest, _Ty _Val, _Pr _Pred, _Diff*)
{  // pop *_First to *_Dest and reheap, using _Pred
    *_Dest = *_First;
    _Adjust_heap(_First, _Diff(0), _Diff(_Last - _First), _Val, _Pred);
}

template <class _RanIt, class _Ty, class _Pr> inline void _Pop_heap_0(_RanIt _First, _RanIt _Last, _Pr _Pred, _Ty*)
{  // pop *_First to *(_Last - 1) and reheap, using _Pred
    _Pop_heap(_First, _Last - 1, _Last - 1, _Ty(*(_Last - 1)), _Pred, _Dist_type(_First));
}

template <class _RanIt, class _Pr> inline void pop_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // pop *_First to *(_Last - 1) and reheap, using _Pred

    if (1 < _Last - _First)
        _Pop_heap_0(CheckedBase(_First), CheckedBase(_Last), _Pred, _Val_type(_First));
}

template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Make_heap(_RanIt _First, _RanIt _Last, _Pr _Pred, _Diff*, _Ty*)
{  // make nontrivial [_First, _Last) into a heap, using _Pred
    _Diff _Bottom = _Last - _First;
    for (_Diff _Hole = _Bottom / 2; 0 < _Hole;)
    {  // reheap top half, bottom to top
        --_Hole;
        _Adjust_heap(_First, _Hole, _Bottom, _Ty(*(_First + _Hole)), _Pred);
    }
}

template <class _RanIt, class _Pr> inline void make_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // make [_First, _Last) into a heap, using _Pred

    if (1 < _Last - _First)
        _Make_heap(CheckedBase(_First), CheckedBase(_Last), _Pred, _Dist_type(_First), _Val_type(_First));
}

template <class _RanIt, class _Pr> inline void _Sort_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // order heap by repeatedly popping, using _Pred
    for (; 1 < _Last - _First; --_Last)
        ::fnv_00b17a60::FUN_00b17a60((::fnv_00b17a60::NodeD10 **)(_First), (::fnv_00b17a60::NodeD10 **)(_Last), (*(::fnv_00b17a60::CompareD10 *)&(const ::SortPred_b16b60 &)(_Pred)));
}

template <class _RanIt, class _Pr> inline void sort_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // order heap by repeatedly popping, using _Pred

    _Sort_heap(CheckedBase(_First), CheckedBase(_Last), _Pred);
}

template <class _BidIt, class _Pr, class _Ty> inline void _Insertion_sort1(_BidIt _First, _BidIt _Last, _Pr _Pred, _Ty*)
{  // insertion sort [_First, _Last), using _Pred
    if (_First != _Last)
        for (_BidIt _Next = _First; ++_Next != _Last;)
        {  // order next element
            _BidIt _Next1 = _Next;
            _Ty _Val = *_Next;

            if (_Pred(_Val, *_First))
            {  // found new earliest element, move to front
                unchecked_copy_backward(_First, _Next, ++_Next1);
                *_First = _Val;
            }
            else
            {  // look for insertion point after first
                for (_BidIt _First1 = _Next1; _Pred(_Val, *--_First1); _Next1 = _First1)
                    *_Next1 = *_First1;  // move hole down
                *_Next1 = _Val;          // insert element in hole
            }
        }
}

template <class _BidIt, class _Pr> inline void _Insertion_sort(_BidIt _First, _BidIt _Last, _Pr _Pred)
{  // insertion sort [_First, _Last), using _Pred
    ::fnv_00b17630::FUN_00b17630((::fnv_00b17630::SortItem **)(_First), (::fnv_00b17630::SortItem **)(_Last));
}

template <class _RanIt, class _Pr> inline void _Med3(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Pr _Pred)
{  // sort median of three elements to middle
    if (_Pred(*_Mid, *_First))
        iter_swap(_Mid, _First);
    if (_Pred(*_Last, *_Mid))
        iter_swap(_Last, _Mid);
    if (_Pred(*_Mid, *_First))
        iter_swap(_Mid, _First);
}

template <class _RanIt, class _Pr> inline void _Median(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Pr _Pred)
{  // sort median element to middle
    if (40 < _Last - _First)
    {  // median of nine
        int _Step = (_Last - _First + 1) / 8;
        _Med3(_First, _First + _Step, _First + 2 * _Step, _Pred);
        _Med3(_Mid - _Step, _Mid, _Mid + _Step, _Pred);
        _Med3(_Last - 2 * _Step, _Last - _Step, _Last, _Pred);
        _Med3(_First + _Step, _Mid, _Last - _Step, _Pred);
    }
    else
        _Med3(_First, _Mid, _Last, _Pred);
}

template <class _RanIt, class _Pr>
inline pair<_RanIt, _RanIt> _Unguarded_partition(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // partition [_First, _Last), using _Pred
    _RanIt _Pfirst = _First + (_Last - _First) / 2;
    _Median(_First, _Pfirst, _Last - 1, _Pred);
    _RanIt _Plast = _Pfirst + 1;

    while (_First < _Pfirst && !_Pred(*(_Pfirst - 1), *_Pfirst) && !_Pred(*_Pfirst, *(_Pfirst - 1)))
        --_Pfirst;
    while (_Plast < _Last && !_Pred(*_Plast, *_Pfirst) && !_Pred(*_Pfirst, *_Plast))
        ++_Plast;

    _RanIt _Gfirst = _Plast;
    _RanIt _Glast = _Pfirst;

    for (;;)
    {  // partition
        for (; _Gfirst < _Last; ++_Gfirst)
            if (_Pred(*_Pfirst, *_Gfirst))
                ;
            else if (_Pred(*_Gfirst, *_Pfirst))
                break;
            else
                iter_swap(_Plast++, _Gfirst);
        for (; _First < _Glast; --_Glast)
            if (_Pred(*(_Glast - 1), *_Pfirst))
                ;
            else if (_Pred(*_Pfirst, *(_Glast - 1)))
                break;
            else
                iter_swap(--_Pfirst, _Glast - 1);
        if (_Glast == _First && _Gfirst == _Last)
            return (pair<_RanIt, _RanIt>(_Pfirst, _Plast));

        if (_Glast == _First)
        {  // no room at bottom, rotate pivot upward
            if (_Plast != _Gfirst)
                iter_swap(_Pfirst, _Plast);
            ++_Plast;
            iter_swap(_Pfirst++, _Gfirst++);
        }
        else if (_Gfirst == _Last)
        {  // no room at top, rotate pivot downward
            if (--_Glast != --_Pfirst)
                iter_swap(_Glast, _Pfirst);
            iter_swap(_Pfirst, --_Plast);
        }
        else
            iter_swap(_Gfirst++, --_Glast);
    }
}

// @fnv 0x00b16b60
void __cdecl FUN_00b16b60(SortEntry** first, SortEntry** last, int ideal, SortPred_b16b60 pred)
{
    int count;
    for (; 32 < (count = last - first) && 0 < ideal;)
    {
        pair<SortEntry**, SortEntry**> mid = _Unguarded_partition(first, last, pred);
        ideal /= 2, ideal += ideal / 2;
        if (mid.first - first < last - mid.second)
        {
            FUN_00b16b60(first, mid.first, ideal, pred);
            first = mid.second;
        }
        else
        {
            FUN_00b16b60(mid.second, last, ideal, pred);
            last = mid.first;
        }
    }
    if (32 < count)
    {
        ::fnv_00b174c0::FUN_00b174c0((::fnv_00b174c0::NodeD10 **)(first), (::fnv_00b174c0::NodeD10 **)(last), (*(::fnv_00b174c0::CompareD10 *)&(const ::SortPred_b16b60 &)(pred)));
        sort_heap(first, last, pred);
    }
    else if (1 < count)
        _Insertion_sort(first, last, pred);
}

struct Elem_b17f50;

struct AllocQ
{
    typedef Elem_b17f50** pointer;
    void destroy(pointer _Ptr)
    {}
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
};

struct Vector_b17f50
{
    int unk00;
    int unk04;
    AllocQ _Alval;
    Elem_b17f50** _Myfirst;
    Elem_b17f50** _Mylast;
    Elem_b17f50** _Myend;

    void _Destroy(Elem_b17f50** _First, Elem_b17f50** _Last)
    {
        _Destroy_rangeS(_First, _Last, _Alval);
    }
    void FUN_00b17f50();
};

// @fnv 0x00b17f50
void Vector_b17f50::FUN_00b17f50()
{
    if (_Myfirst != 0)
    {
        _Destroy(_Myfirst, _Mylast);
        _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
    }
    _Myfirst = 0, _Mylast = 0, _Myend = 0;
}

struct StorageProxy
{
    const StorageBase* container;
    explicit StorageProxy(const StorageBase* p) : container(p)
    {}
};

template <class A> struct ProxyStorage : StorageBase
{
    vc9_std::allocator<StorageProxy> proxyAllocator;
    explicit ProxyStorage(A a) : proxyAllocator(a)
    {
        proxy = new (proxyAllocator.allocate(1)) StorageProxy(this);
    }
};

template <class T> struct VectorAllocStorage : ProxyStorage<vc9_std::allocator<T> >
{
    vc9_std::allocator<T> allocator;
    VectorAllocStorage(vc9_std::allocator<T> a = vc9_std::allocator<T>()) : ProxyStorage<vc9_std::allocator<T> >(a), allocator(a)
    {}
};

template <class T> struct VectorLike : VectorAllocStorage<T>
{
    T* first;
    T* last;
    T* end;
    VectorLike() : VectorAllocStorage<T>()
    {
        Buy(0);
    }
    ~VectorLike()
    {
        Tidy();
    }
    void Tidy()
    {
        if (first != 0)
        {
            T* rangeFirst = first;
            T* rangeLast = last;
            T* destroyFirst = rangeFirst;
            T* destroyLast = rangeLast;
            destroyElements(destroyFirst, destroyLast);
            this->allocator.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
    bool Buy(unsigned int capacity)
    {
        first = 0, last = 0, end = 0;
        if (capacity == 0)
            return false;
        else if (max_size() < capacity)
            _Xlen();
        else
        {
            first = this->allocator.allocate(capacity);
            last = first;
            end = first + capacity;
        }
        return true;
    }
    unsigned int max_size() const
    {
        return this->allocator.max_size();
    }
    static void _Xlen()
    {
        throw vc9_std::length_error(vc9_std::string(DAT_010173c4));
    }
};

struct PointEntry
{
    float x, y, z;
};

typedef VectorLike<TreeEntry> SplineMember08;

typedef VectorLike<OtherEntry> SplineMember20;

typedef VectorLike<PointEntry> SplineMember50;

struct SplineCurve
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

    SplineCurve(const vc9_std::string& text);
};

class FUN_00b17fd0
{
  public:
    int unk00;
    int unk04;
    SplineMember08 unk08;
    SplineMember20 unk20;
    int unk38;
    int unk3C;
    SplineCurve* curve40;
    int unk44;
    int unk48;
    bool unk4C;
    SplineMember50 unk50;
    int unk68;
    float unk6C;
    float unk70;
    float unk74;
    float unk78;
    int unk7C;
    int unk80;
    FUN_00b17fd0();
};

// @fnv 0x00b17fd0
FUN_00b17fd0::FUN_00b17fd0()
    : unk00(0), unk04(0), unk38(1), unk3C(2), unk44(4), unk48(1), unk4C(false), unk68(4), unk6C(1.0f), unk70(0.0f),
      unk74(0.0f), unk78(0.05f), unk7C(2), unk80(1)
{
    curve40 = new SplineCurve(vc9_std::string(
        "BezierSpline 0.0 1.0 0.0 { 3 0 0.00138887 0.337009 0.941501 0.132767 0.493215 0.998903 1 0.00102074 0.23702 1 -6.24607e-008 0.307222 -0.951638 0.126974 }"));
}

#include "generated/data/staging/blk_00b00000_od.inc"
#include "generated/data/staging/blk_00b00000_od_ob1_variant.inc"
