
// src/bsaudio/bsaudiomanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiomanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include <cstdlib>
#include "fnv/decl/AE8150_List.h"
#include "fnv/decl/AE91F0Map.h"
#include "fnv/decl/BSAudioMgr.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_00ad93f0.h"
#include "fnv/decl/FUN_00ae78a0_cls.h"
#include "fnv/decl/FUN_00ae78e0_Class.h"
#include "fnv/decl/FUN_00ae8010_cls.h"
#include "fnv/decl/FUN_00aea100_cls.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/OwnerQ3.h"
#include "fnv/decl/QRequest.h"
#include "fnv/decl/S_00a0c9f0.h"
#include "fnv/decl/S_00adc830_Map.h"
#include "fnv/decl/S_00ae8370_List.h"
#include "fnv/decl/SndStack70.h"
#include "fnv/decl/Stack75f0.h"
#include "fnv/decl/fnv_00aa6590__FUN_00aa6590_cls.h"
#include "fnv/decl/fnv_00ad7fa0__AudioUpdateStand.h"
#include "fnv/decl/fnv_00ada330__OwnerQ.h"
#include "fnv/decl/fnv_00adad80__Manager501.h"
#include "fnv/decl/fnv_00adcaa0__FUN_00adcaa0_cls.h"
#include "fnv/decl/fnv_00adddd0__AudioUpdate.h"
#include "fnv/decl/fnv_00adf080__BSAudioManager_adf080.h"
#include "fnv/decl/fnv_00ae76b0__Pool_ae76b0.h"
#include "fnv/decl/fnv_00c3cea0__FUN_00c3cea0.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_010a3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"

// @fnv 0x0072fa80
int __cdecl FUN_0072fa80(int param_1)
{
    return std::abs(param_1);
}

struct BSAudioManager
{
    static BSAudioManager& __cdecl GetRandomGenerator(void);
};

struct FUN_00ad8d60_shell
{
    int m_uiSoundResourceID;
    int pad;
    int eState;
    bool FUN_00ad8d60(int param2);
};

// @fnv 0x00ad8d60
bool FUN_00ad8d60_shell::FUN_00ad8d60(int aiParam)
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    eState = 1;
    reinterpret_cast<::BSAudioMgr *>(&(BSAudioManager::GetRandomGenerator()))->FUN_00adc670(m_uiSoundResourceID, aiParam);
    return true;
}

struct FUN_00ada300_shell
{
    void FUN_00ada300(float fval, int param);
};

// Stores param at offset 0xa4 and fval at offset 0xa8 of this object.
// @fnv 0x00ada300
void FUN_00ada300_shell::FUN_00ada300(float fval, int param)
{
    ((int*)((char*)this + 0xa4))[0] = param;
    ((float*)((char*)this + 0xa8))[0] = fval;
}

namespace fnv_00adad60 {
struct BottomlessStack
{
};
struct BSAudioManager
{
    BottomlessStack m_aiEntries;  // +0x24
    void FUN_00adad60();
};

// @fnv 0x00adad60
void BSAudioManager::FUN_00adad60()
{
    reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>((((BottomlessStack*)((char*)this + 0x24))))->FUN_00ae76b0();
}
}  // namespace fnv_00adad60

namespace fnv_00adaf80 {
struct SoundMessageRecord;

struct BottomlessStack
{
    SoundMessageRecord* Pop();
};

struct BSAudioManager
{
    SoundMessageRecord* FUN_00adaf80();
};

// @fnv 0x00adaf80
SoundMessageRecord* BSAudioManager::FUN_00adaf80()
{
    return ((::fnv_00adaf80::SoundMessageRecord *)(reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>((reinterpret_cast<BottomlessStack*>(reinterpret_cast<char*>(this) + 0x34)))->FUN_00ae76b0()));
}
}  // namespace fnv_00adaf80

struct FUN_00adb960_shell
{
    bool FUN_00adb960(int arg1, int arg2);
};

// @fnv 0x00adb960
bool FUN_00adb960_shell::FUN_00adb960(int arg1, int arg2)
{
    return false;
}

struct FUN_00adbf40_shell
{
    bool FUN_00adbf40(float f1, float f2, float f3, float f4);
};

// @fnv 0x00adbf40
bool FUN_00adbf40_shell::FUN_00adbf40(float f1, float f2, float f3, float f4)
{
    return false;
}

struct FUN_00c3d0e0_stub
{
};

struct FUN_00ae7480_shell : FUN_00c3d0e0_stub
{
    bool FUN_00ae7480(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x00ae7480
bool FUN_00ae7480_shell::FUN_00ae7480(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>((this))->FUN_00c3d0e0(apDescription, aiBufferSize, "audio load task");
}

struct FUN_00adcaa0_shell
{
};

struct FUN_00ad84b0_shell
{
    void FUN_00ad84b0(int param_2, int param_3);
};

// Forwards the two arguments to BSAudioManager's FUN_00adcaa0.
// @fnv 0x00ad84b0
void FUN_00ad84b0_shell::FUN_00ad84b0(int param_2, int param_3)
{
    reinterpret_cast<::fnv_00adcaa0::FUN_00adcaa0_cls *>((((FUN_00adcaa0_shell*)&BSAudioManager::GetRandomGenerator())))->FUN_00adcaa0(param_2, param_3);
}

struct FUN_00adcc10_shell
{
    void FUN_00adcc10(int, int);
};
struct FUN_00ad8540_shell
{
    void FUN_00ad8540(int param1, bool param2);
};
// Forwards param1 and param2 to the BSAudioManager method FUN_00adcc10.
// @fnv 0x00ad8540
void FUN_00ad8540_shell::FUN_00ad8540(int param1, bool param2)
{
    ((FUN_00adcc10_shell*)&BSAudioManager::GetRandomGenerator())->FUN_00adcc10(param1, param2);
}

struct S_00ae5f70
{
    int f0;
    char f4;
    int f8;
};
struct C_00ae5f70
{
    S_00ae5f70* Init(S_00ae5f70* p, int a2, int a3, int a4, int a5, int a6, int a7);
};
// Initializes the object: sets f0 to -1, f4 and f8 to 0, and returns the object pointer.
// @fnv 0x00ae5f70
S_00ae5f70* C_00ae5f70::Init(S_00ae5f70* pObject, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int i = 0;
    pObject->f0 = -1;
    pObject->f4 = 0;
    pObject->f8 = 0;
    i |= 1;
    return pObject;
}

// Compares the unsigned ints pointed to by a and b, returning -1 if the first is smaller, 1 if larger, else 0.
// @fnv 0x00ae5fb0
int __cdecl FUN_00ae5fb0(unsigned int* puiLeft, unsigned int* puiRight)
{
    unsigned int v1 = *puiLeft;
    unsigned int v2 = *puiRight;
    return v1 < v2 ? -1 : v1 > v2;
}

extern int DAT_011f6ecc;
struct FUN_00ae6c60_shell
{
    int FUN_00ae6c60();
};
// @fnv 0x00ae6c60
int FUN_00ae6c60_shell::FUN_00ae6c60()
{
    int* p = &(*reinterpret_cast<int *>(&::g_011f6ec8)) ? &DAT_011f6ecc : (DAT_01202800 = 0, &DAT_01202800);
    return *p;
}

namespace fnv_00ae6ca0 {
struct BSAudioManager_shell : BSAudioManager
{
    void AddSound(int arg2);
    void FUN_00ae6ca0(bool enable);
};
// Stores enable into a global flag and, when disabling, calls AddSound(0).
// @fnv 0x00ae6ca0
void BSAudioManager_shell::FUN_00ae6ca0(bool enable)
{
    char* target = &(*reinterpret_cast<int *>(&::g_011f6ebc)) ? (char*)&(*reinterpret_cast<int *>(&::fnv_00ae6cf0::DAT_011f6ec0)) : ((void)((*reinterpret_cast<char *>(&::DAT_01202800)) = 0), (char*)&(*reinterpret_cast<char *>(&::DAT_01202800)));
    *target = enable;
    if (!enable)
        AddSound(0);
}
}  // namespace fnv_00ae6ca0

namespace fnv_00ae6cf0 {
struct FUN_00ae6cf0_shell
{
    bool FUN_00ae6cf0();
};
// @fnv 0x00ae6cf0
bool FUN_00ae6cf0_shell::FUN_00ae6cf0()
{
    bool* mode = &(*reinterpret_cast<int *>(&::g_011f6ebc)) ? &DAT_011f6ec0 : ((*reinterpret_cast<bool *>(&::DAT_01202800)) = 0, &(*reinterpret_cast<bool *>(&::DAT_01202800)));
    return *mode;
}
}  // namespace fnv_00ae6cf0

extern int DAT_010a3718;

struct _Base_00441d20
{
    _Base_00441d20();
    ~_Base_00441d20();
};

struct FUN_00ae7020_shell : _Base_00441d20
{
    void FUN_00ae7020();
};

// Sets the vtable pointer to DAT_010a3718, touches the field at offset 0x30, then calls the base destructor.
// @fnv 0x00ae7020
void FUN_00ae7020_shell::FUN_00ae7020()
{
    *reinterpret_cast<void**>(this) = &DAT_010a3718;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x30) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x30);
    reinterpret_cast<::fnv_00c3cea0::FUN_00c3cea0 *>(this)->fnv_00c3cea0::FUN_00c3cea0::~FUN_00c3cea0();
}

struct SoundMessageRecord;
struct BottomlessStack
{
    void Push(SoundMessageRecord*);
    SoundMessageRecord* Pop();
    void SetBottomless(bool);
    void* __vecDelDtor(unsigned int);
    unsigned int iCount;
    bool m_bBottomless;
    char _pad_5[3];
    SoundMessageRecord* pTop;
    unsigned int m_uiStackLimit;
};
struct FUN_00ae7510_shell : public BottomlessStack
{
    void FUN_00ae7510();
};

struct FUN_00ae7510 : public BottomlessStack
{
    FUN_00ae7510();
};
// Initializes the stack: clears the count, top pointer, bottomless flag and the extra field.
// @fnv 0x00ae7510
FUN_00ae7510::FUN_00ae7510()
{
    iCount = 0;
    pTop = 0;
    m_bBottomless = false;
    m_uiStackLimit = 0;
}

struct MemoryManager
{
};
struct FUN_00ad93f0_shell
{
};
struct FUN_00ae77a0_shell : FUN_00ae7480_shell
{
    void* FUN_00ae77a0(unsigned int flags);
};
// Calls FUN_00ad93f0 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ae77a0
void* FUN_00ae77a0_shell::FUN_00ae77a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00ad93f0 *>((((FUN_00ad93f0_shell*)this)))->FUN_00ad93f0::~FUN_00ad93f0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::MemoryManager * *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00ae7870 {
struct P03MM
{
    void DeallocateAlias(void*);
};

struct FUN_00ae7870_shell
{
    void* FUN_00ae7870(unsigned int flags);
};

// @fnv 0x00ae7870
void* FUN_00ae7870_shell::FUN_00ae7870(unsigned int flags)
{
    reinterpret_cast<::FUN_00ae78a0_cls *>(this)->FUN_00ae78a0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((P03MM*)&(*reinterpret_cast<::fnv_00ae7870::P03MM * *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae7870

namespace fnv_00ae7b10 {
struct MemoryManager
{
};
void __cdecl DeallocateAlias(void*);
struct FUN_00ae7020_shell
{
};
struct AudioLoadTask : FUN_00ae7020_shell
{
    void* FUN_00ae7b10(unsigned int flags);
};
// Calls FUN_00ae7020, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ae7b10
void* AudioLoadTask::FUN_00ae7b10(unsigned int flags)
{
    reinterpret_cast<::FUN_00ae7020_shell *>(this)->FUN_00ae7020();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae7b10::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae7b10

struct GO
{
    GO& operator=(void*);
};
template <typename T> struct NiTPointerAllocator
{
    void Deallocate(void*);
};
struct Host00ae8ef0
{
    char _p[12];
    NiTPointerAllocator<unsigned int> alloc;
    void FUN_00ae8ef0(void* p);
};
// Clears the pointer at offset 8 of p, then deallocates p through the allocator.
// @fnv 0x00ae8ef0
void Host00ae8ef0::FUN_00ae8ef0(void* p)
{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    ((GO*)((char*)p + 8))->operator=(0);
    reinterpret_cast<::FUN_0045cee0_shell *>(&(alloc))->FUN_0045cee0(p);
}

namespace fnv_00ae8f20 {
struct MemoryManager
{
};
struct S00a0d390
{
    int _0;
    int _4;
    void* _8;
    void* FUN_00ae8f20(int);
};
// @fnv 0x00ae8f20
void* S00a0d390::FUN_00ae8f20(int aiFlags)
{
    int _u1;
    int _u2;
    *(void**)this = (void*)&::DAT_010a3370;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(_8);
    if (aiFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae8f20::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    (void)_u1;
    (void)_u2;
    return this;
}
}  // namespace fnv_00ae8f20

namespace fnv_00ae9010 {
struct MemoryManager
{
};
struct S00a0d390
{
};
struct FUN_00ae9010Owner
{
    void* f0;
    int f4;
    void* f8;
    void* DestroyOwner(int);
};
// @fnv 0x00ae9010
void* FUN_00ae9010Owner::DestroyOwner(int aiFlags)
{
    int x;
    int y;
    *(void**)this = (void*)&::DAT_010a3390;
    reinterpret_cast<::AE91F0Map *>((((S00a0d390*)this)))->ClearAll();
    ::FUN_00aa10f0(f8);
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae9010::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae9010

namespace fnv_00ae9100 {
struct S00a0d390
{
    void* _00;
    int _04;
    void* _08;
    void* FUN_00ae9100(unsigned int);
};
struct MemoryManager
{
};
// Sets the vtable, calls ClearAll, frees _08 via _NiFreeAlias, and deallocates this when flag bit 0 is set.
// @fnv 0x00ae9100
void* S00a0d390::FUN_00ae9100(unsigned int auiFlags)
{
    int d1;
    int d2;
    *(void**)this = (void*)&::DAT_010a33b0;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(_08);
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae9100::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae9100

struct AudioLoadTask
{
    int _pad[12];
    void* SoundAssetTmp;
    void FUN_00ae7360();
};
struct Helper
{
};
struct BSAudioDefinition
{
    BSAudioDefinition();
public:
    ::BSAudioDefinition &operator=(const ::BSAudioDefinition &);
};
struct FUN_00ae89f0
{
    unsigned int m_uiSoundID;
    float m_fSoundVolume;
    int _08;
    unsigned int m_uiValueAt0C;
    unsigned int m_uiPlaybackFlags;
    bool m_bValueAt14;
    char _pad[3];
    BSAudioDefinition _18;
    FUN_00ae89f0();
};
// @fnv 0x00ae89f0
FUN_00ae89f0::FUN_00ae89f0()
{
    m_uiSoundID = 0;
    m_fSoundVolume = 0.0f;
    m_uiValueAt0C = 0;
    m_uiPlaybackFlags = 0;
    m_bValueAt14 = 0;
}

struct Setting_00ad9da0
{
    void* vtbl;
    float fValue;
    const char* pKey;
};
struct AudioVolumes_00ad9da0
{
    float fVal[6];
    float fMult[6];
};
struct FUN_00ad9da0_t
{
    void InitAudioVolumes();
};

// Copies the six setting values into the fVal array at this+0x140 and sets all six fMult entries to 1.0.
// @fnv 0x00ad9da0
void FUN_00ad9da0_t::InitAudioVolumes()
{
    float* r0 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e14)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e14)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[0] = *r0;
    {
        float* r1 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e20)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e20)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
        ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[1] = *r1;
        {
            float* r2 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e2c)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e2c)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
            ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[2] = *r2;
            {
                float* r3 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e38)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e38)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[3] = *r3;
                {
                    float* r4 =
                        &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e44)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e44)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[4] = *r4;
                    {
                        float* r5 =
                            &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e50)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e50)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                        ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[5] = *r5;
                    }
                }
            }
        }
    }
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[0] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[1] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[2] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[3] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[4] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[5] = 1.0f;
}

struct FUN_00ae6d30_shell
{
    bool HasMatchingEntry(unsigned int mask);
};
// @fnv 0x00ae6d30
bool FUN_00ae6d30_shell::HasMatchingEntry(unsigned int mask)
{
    unsigned int i = 0;
    for (; i < *(unsigned int*)((char*)this + 0x17c); ++i)
    {
        if (*(unsigned short*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8 + 4) == 1 &&
            (mask & *(unsigned int*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8)) ==
                *(unsigned int*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8))
            return true;
        else if (*(unsigned short*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8 + 4) == 2 &&
                 (mask & *(unsigned int*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8)))
            return true;
    }
    return false;
}

struct FUN_00ae6e60_shell
{
    bool FUN_00ae6e60(int param_2, unsigned char param_3);
};
// @fnv 0x00ae6e60
bool FUN_00ae6e60_shell::FUN_00ae6e60(int param_2, unsigned char abMatchStateOne)
{
    int i = 0;
    for (; i < *(unsigned int*)((char*)this + 0x17c); ++i)
    {
        if (param_2 == *(int*)((char*)*(int*)((char*)this + 0x178) + i * 8) &&
            ((!abMatchStateOne && *(unsigned short*)((char*)*(int*)((char*)this + 0x178) + i * 8 + 4) == 2) ||
             (abMatchStateOne && *(unsigned short*)((char*)*(int*)((char*)this + 0x178) + i * 8 + 4) == 1)))
        {
            *(unsigned short*)((char*)*(int*)((char*)this + 0x178) + i * 8 + 4) = 0;
            *(int*)((char*)*(int*)((char*)this + 0x178) + i * 8) = 0;
            return true;
        }
    }
    return false;
}

struct SoundEmitter;
struct AudioLoadTask;
struct BSAudioManager;
struct BSAudioManagerThread;
struct BSGameSound;
struct SoundMessageRecord;
struct NiAVObject;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

struct Snd_
{
};

struct BSAudio : Snd_
{
    unsigned char _pad[6];
    bool bIsMultiThreaded;
};

extern char $SG6265[];

struct FUN_00ada330_shell
{
};

struct FUN_00addc00_shell
{
};

struct FUN_00ada1d0_shell
{
    unsigned char _pad[0x134];
    bool m_bUISoundsEnabled;
    void InitUISounds(bool);
};

struct BADC7D0Item
{
    unsigned int m_uiKey;
};

class BADC7D0Map
{
  public:
};

class BADC7D0Cache
{
  public:
    bool ContainsKey(unsigned int uiKey);

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
    BADC7D0Map m_kUnsortedGeometryList;
};

// Looks up uiKey in the map and returns true if an item is found whose key equals uiKey.
// @fnv 0x00adc7d0
bool BADC7D0Cache::ContainsKey(unsigned int uiKey)
{
    bool bFound4 = false;
    BADC7D0Item* pkItem9 = 0;
    reinterpret_cast<::S_00adc830_Map *>(&(m_kUnsortedGeometryList))->GetAt(uiKey, (::S_00adc830_Entry *&)(pkItem9));
    if (pkItem9)
    {
        void* pvX;
        void* pvUnusedB;
        unsigned int uiItemKey = pkItem9->m_uiKey;
        if (uiItemKey == uiKey)
            bFound4 = true;
    }
    if (!bFound4)
        bFound4 = bFound4;
    return bFound4;
}

struct CritSecA
{
    int unk[6];
};

struct ObjEntry
{
    char unk0[0x144];
    int m_144;
    int m_148;
};

struct ObjNode
{
    ObjNode* m_pNext;
    int unk4;
    ObjEntry* m_pEntryObject;
};

struct ObjRegistry
{
    char unk0[0x94];
    ObjNode* m_pHead;
    char unk98[0xdc - 0x98];
    CritSecA m_kCS;

    bool FUN_00add480(int m_uiSoundID, bool bCheckAlt);
};

// @fnv 0x00add480
bool ObjRegistry::FUN_00add480(int m_uiSoundID, bool bCheckAlt)
{
    if (m_uiSoundID == 0)
        return false;
    EnterCriticalSection(&m_kCS);
    bool bFound = false;
    ObjNode* pNode = m_pHead;
    while (pNode)
    {
        ObjEntry* pEntry = pNode->m_pEntryObject;
        if (pEntry)
        {
            if ((bool)(int)(m_uiSoundID == pEntry->m_144) ||
                (bCheckAlt && (int)(unsigned char)(m_uiSoundID == pEntry->m_148 && pEntry->m_148 ? 1 : 0)))
            {
                bFound = true;
                break;
            }
        }
        pNode = pNode ? pNode->m_pNext : 0;
    }
    LeaveCriticalSection(&m_kCS);
    return bFound;
}


extern int DAT_011f6ecc;

struct AudioCacheOwner
{
    void SetAudioCacheSize(int size);
};

// Sets the audio cache size when it is below 0x1000, otherwise logs an error; a size of 0 also calls FUN_00ae6ca0(0).
// @fnv 0x00ae6bf0
void AudioCacheOwner::SetAudioCacheSize(int size)
{
    if (size == 0)
    {
        reinterpret_cast<::fnv_00ae6ca0::BSAudioManager_shell *>(this)->FUN_00ae6ca0(0);
    }
    if ((unsigned int)size < 0x1000)
    {
        int* piCacheSize = (&(*reinterpret_cast<int *>(&::g_011f6ec8)) != 0) ? &DAT_011f6ecc : (DAT_01202800 = 0, &DAT_01202800);
        *piCacheSize = size;
    }
    else
    {
        ::FUN_005b5e40();
    }
}

struct AE6DE0Slot
{
    void* m_pResource;
    unsigned short m_usState;
    unsigned short unk06;
};

class AE6DE0Table
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
    AE6DE0Slot* m_pkSlots;
    unsigned int m_uiSlotCount;

    bool AddSlot(void* pvData, bool bPrimary);
};

// Finds the first slot with state 0, sets its state to 1 or 2 depending on bPrimary, stores pvData in it, and returns true; returns false if no free slot exists.
// @fnv 0x00ae6de0
bool AE6DE0Table::AddSlot(void* pData, bool bPrimary)
{
    for (unsigned int i = 0; i < m_uiSlotCount; i++)
    {
        if (m_pkSlots[i].m_usState == 0)
        {
            m_pkSlots[i].m_usState = bPrimary ? 1 : 2;
            m_pkSlots[i].m_pResource = pData;
            return true;
        }
    }
    return false;
}


class BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;

    BaseObj_b5112(int aValue);
    ~BaseObj_b5112();
};

class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    int m_30;

    FUN_00ae6f50(int aValue);
};

// @fnv 0x00ae6f50
FUN_00ae6f50::FUN_00ae6f50(int aValue) : BaseObj_b5112(0)
{
    m_30 = aValue;
    char buf[0x104];
    ::CopyRelativeDataPath((const char *)(m_30 + 0x36), buf, 0x104);
    reinterpret_cast<::FUN_00c3cee0_shell *>(this)->FUN_00c3cee0(buf);
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>(this)->LookupFileEntryByArchive(3);
}

struct Sound7390
{
    virtual void* ScalarDeletingDestructor(unsigned int);
    int unk04;
    unsigned int uiFlags08;
    int unk0C;
    unsigned int uiFlags10;
};
struct AudioLoadTask7390
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Sound7390* SoundAssetTmp;
    void ReleaseSound(int, int);
};
struct AudioHelper7390
{
};
struct Ptr_6e5cc0
{
    void* p;
    Ptr_6e5cc0& operator=(const Ptr_6e5cc0& rhs);
};

struct Msg_ae7990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Ptr_6e5cc0 ptr10;
    union
    {
        float f14[3];
        unsigned short s14[5];
    };
    Msg_ae7990& CopyFrom(const Msg_ae7990& rhs);
};

// @fnv 0x00ae7990
Msg_ae7990& Msg_ae7990::CopyFrom(const Msg_ae7990& aOther)
{
    int j;
    int e;
    unsigned int uiShortIndex;
    unsigned int p;
    unk00 = aOther.unk00;
    unk04 = aOther.unk04;
    unk08 = aOther.unk08;
    unk0c = aOther.unk0c;
    ptr10 = aOther.ptr10;
    for (p = 0; p < 3; ++p)
    {
        f14[p] = aOther.f14[p];
    }
    for (uiShortIndex = 0; uiShortIndex < 5; ++uiShortIndex)
    {
        s14[uiShortIndex] = aOther.s14[uiShortIndex];
    }
    return *this;
}

struct AE8470Item;

struct AE8470List
{
    AE8470Item* m_pkItem;
    AE8470List* m_pkNext;

    void SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*));
};

// Bubble-sorts the linked list by swapping item pointers using pfnCompare, counting non-null items to bound the passes.
// @fnv 0x00ae8470
void AE8470List::SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*))
{
    AE8470List* pkCur8 = this;
    AE8470List* pkPrev4 = 0;
    if (pkCur8)
    {
        int iPasses;
        AE8470Item* pkCurItem;
        AE8470Item* pkPrevItemTmp;
        {
            int iCount = 0;
            AE8470List* pkIter3 = pkCur8;
            while (pkIter3)
            {
                if (pkIter3->m_pkItem)
                    iCount++;
                pkIter3 = pkIter3->m_pkNext;
            }
            iPasses = iCount;
        }
        bool bSwapped = true;
        while (iPasses && bSwapped)
        {
            bSwapped = false;
            while (pkCur8)
            {
                if (pkPrev4)
                {
                    pkCurItem = pkCur8->m_pkItem;
                    pkPrevItemTmp = pkPrev4->m_pkItem;
                    if (pfnCompare(pkPrevItemTmp, pkCurItem) > 0)
                    {
                        if (!pkPrevItemTmp)
                        {
                        }
                        else
                        {
                            pkCur8->m_pkItem = pkPrevItemTmp;
                        }
                        if (!pkCurItem)
                        {
                        }
                        else
                        {
                            pkPrev4->m_pkItem = pkCurItem;
                        }
                        bSwapped = true;
                    }
                }
                pkPrev4 = pkCur8;
                pkCur8 = pkCur8->m_pkNext;
            }
            iPasses--;
        }
    }
}

struct FUN_00ae8550_shell
{
    void FUN_00ae8550(int* values, int(__cdecl* compare)(int, int), int count);
};

// Sorts the values array in place using a Shell sort with a Knuth gap sequence and the given comparison function.
// @fnv 0x00ae8550
void FUN_00ae8550_shell::FUN_00ae8550(int* values, int(__cdecl* compare)(int, int), int count)
{
    int offset;
    {
        int last;
        int gap;
        {
            int index;
            {
                int value;
                {
                    int position;

                    gap = 0;
                    offset = 0;
                    last = count - 1;
                    gap = 1;

                    for (; gap <= (last - offset) / 9; gap = gap * 3 + 1)
                    {
                    }

                    for (; gap > 0; gap /= 3)
                    {
                        for (index = offset + gap; index <= last; ++index)
                        {
                            position = index;
                            value = values[index];

                            while (position >= offset + gap && compare(value, values[position - gap]) < 0)
                            {
                                values[position] = values[position - gap];
                                position -= gap;
                            }

                            values[position] = value;
                        }
                    }
                }
            }
        }
    }
}

struct Setting_01017720_011f96a0
{
    void* m_pVtbl;
    int m_iValue;
};

struct BSThread
{
    enum StackSize
    {
        kDefaultStack = 0x8000
    };

    void Initialize(StackSize eStackSize, const char* apName, bool abSuspended);
    void SetName(const char* apName);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int m_iThreadId;
public:
    void SetSchedulingPriority(unsigned int);
};


class AudioThreadHost_00ad9f30
{
  public:
    void FUN_00ad9f30(void);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134;
    unsigned int m_uiThreadID;
    BSThread* m_pAudioThread;
};

// @fnv 0x00ad9f30
void AudioThreadHost_00ad9f30::FUN_00ad9f30(void)
{
    if (m_pAudioThread)
    {
        int iHandle = m_pAudioThread->m_iThreadId;
        if (iHandle == 0)
        {
            m_pAudioThread->Initialize(BSThread::kDefaultStack, "LibAudioUpdate", false);

            int iHandleAfterInit = m_pAudioThread->m_iThreadId;
            m_uiThreadID = iHandleAfterInit;

            int* pSettingValue = &::g_011f6ee0 ? &::g_011f6ee0.m_iValue : &(DAT_01202800 = 0);
            int iSetPriority = *pSettingValue;
            m_pAudioThread->SetSchedulingPriority(iSetPriority);

            m_pAudioThread->SetName("LibAudioUpdate");
            int iThreadIdentifier = m_pAudioThread->m_iThreadId;
            int iPrioritySave;  // the original source declares this and never uses it; the slot is part of its frame
            ::SetDebuggerThreadName(iThreadIdentifier, "LibAudioUpdate");
        }
        reinterpret_cast<::FUN_00ae78e0_Class *>((m_pAudioThread))->ReleaseSemaphoreAndIncrement();
    }
}

namespace fnv_00add630 {
typedef bool(__cdecl* ADD630ResolveFunc)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                         unsigned int* puiExtra);

class ADD630Audio
{
  public:
    int unk00;
    bool m_bEnableState;
    char unk05;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ADD630ResolveFunc m_pfnResolve;
};


class ADD630Manager
{
  public:
    void FUN_00add630(const char* pcName, unsigned int uiFlags);
};

// @fnv 0x00add630
void ADD630Manager::FUN_00add630(const char* pcName, unsigned int uiFlags)
{
    unsigned int uiResolvedFlags3 = uiFlags;
    ADD630Audio* pkAudio5 = (*reinterpret_cast<::fnv_00add630::ADD630Audio * *>(&::DAT_011f6d98));
    ADD630ResolveFunc pfnResolve4 = pkAudio5->m_pfnResolve;
    unsigned int _uiExtra = 0;
    ADD630Audio* pkAudio2 = (*reinterpret_cast<::fnv_00add630::ADD630Audio * *>(&::DAT_011f6d98));
    bool bEnabled6 = pkAudio2->m_bEnableState;
    char acPath4[260];
    if (!bEnabled6 || !pfnResolve4 || !pfnResolve4(pcName, acPath4, &uiResolvedFlags3, &_uiExtra))
        return;
    uiFlags |= uiResolvedFlags3;
    reinterpret_cast<::OwnerQ3 *>(this)->FUN_00add6f0(acPath4, uiFlags, _uiExtra);
}
}  // namespace fnv_00add630

struct Sub
{
};

struct S
{
    int f0;
    float f4;
    float f8;
    int fc;
    int f10;
    unsigned char f14;
    char pad15[3];
    Sub sub;
    S* AssignFrom(const S* src);
};

// Copies the scalar fields from src into this and forwards src's sub object to sub.FUN_00ae88c0, returning this.
// @fnv 0x00ae7920
S* S::AssignFrom(const S* apSource)
{
    int u1, u2, u3, u4;
    f0 = apSource->f0;
    f4 = apSource->f4;
    f8 = apSource->f8;
    fc = apSource->fc;
    f10 = apSource->f10;
    f14 = apSource->f14;
    reinterpret_cast<::BSAudioDefinition *>(&(sub))->operator=((*(const ::BSAudioDefinition *)(&apSource->sub)));
    return this;
}


struct AudioMgr_adac30
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
    float m_f140;
    float m_f144;
    float m_f148;
    float m_f14C;
    float m_f150;
    float m_f154;
    float m_f158;
    float m_f15C;
    float m_f160;
    float m_f164;
    float m_f168;
    float m_f16C;

    float FUN_00adac30(float a1, unsigned int a2);
};

// Scales a1 by m_f140*m_f158 and a setting value, then applies a further gain pair chosen by the flags in a2 and returns the result.
// @fnv 0x00adac30
float AudioMgr_adac30::FUN_00adac30(float afBase, unsigned int auiFlags)
{
    float f6 = afBase;
    float* pSettingValue = &::g_011f6e74 ? (float*)&::g_011f6e74.m_iValue : &(*(float*)& DAT_01202800 = 0.0f);
    f6 = m_f140 * m_f158 * *pSettingValue * f6;
    if (auiFlags & 0x800000)
    {
        return f6 * m_f150 * m_f168;
    }
    if (auiFlags & 8)
    {
        f6 = m_f144 * m_f15C * f6;
    }
    else if (auiFlags & 4)
    {
        f6 = m_f148 * m_f160 * f6;
    }
    else if (auiFlags & 0x800)
    {
        f6 = m_f150 * m_f168 * f6;
    }
    else if (auiFlags & 0x100000)
    {
        f6 = m_f154 * m_f16C * f6;
    }
    else
    {
        f6 = m_f14C * m_f164 * f6;
    }
    return f6;
}

struct Sound
{
    virtual ~Sound();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual Sound* Create(int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(Sound*, int);
    int p4;
    unsigned int flags;
    char padding[0x138];
    unsigned int id;
    int p148;
    unsigned int size;
};
struct Node
{
    Node* next;
    int p4;
    Sound* sound;
};
struct LinkedSoundQueue
{
    Node* head;
    int p4;
    unsigned int count;
};
struct Owner
{
    char pad[0x94];
    LinkedSoundQueue list;
    unsigned int total;
    char more[0x38];
    CritSecA cs;
    void AddSound(Sound*);
};
struct DeleteView
{
    virtual void* Destroy(unsigned int);
};
// Locks the critical section, rejects duplicate or oversized sounds, clones the input into the list, then evicts entries while total exceeds the limit.
// @fnv 0x00adcd80
void Owner::AddSound(Sound* apSound)
{
    Sound* v35 = 0;
    Sound* v16;
    Sound* v2;
    Sound* v13;
    Sound* v9;
    EnterCriticalSection(&cs);
    int count;
    {
        unsigned int n = list.count;
        count = n;
    }
    {
        unsigned char* p = &(*reinterpret_cast<char *>(&::g_011f6ebc)) ? (unsigned char*)&(*reinterpret_cast<char *>(&::g_011f6ebc)) + 4
                                         : (*(unsigned char*)& DAT_01202800 = 0, (unsigned char*)&DAT_01202800);
        if (!*p && count > 0)
        {
            struct U8
            {
                int a, b;
            };
            U8 unused;
            while (!(unsigned char)(int)(list.count == 0))
            {
                v35 = ((::Sound *)(reinterpret_cast<::SndStack70 *>(&(list))->FUN_00ae7f90()));
                if (v35)
                {
                    v2 = v35;
                    v16 = v2;
                    v16 ? ((DeleteView*)v16)->Destroy(1) : 0;
                }
            }
            LeaveCriticalSection(&cs);
            return;
        }
        else
        {
            unsigned char* p = &(*reinterpret_cast<char *>(&::g_011f6ebc)) ? (unsigned char*)&(*reinterpret_cast<char *>(&::g_011f6ebc)) + 4
                                             : (*(unsigned char*)& DAT_01202800 = 0, (unsigned char*)&DAT_01202800);
            {
                unsigned int n;
                {
                    unsigned int* pi;
                    {
                        unsigned int f;
                        if (!*p || !apSound ||
                            (n = apSound->size,
                             pi = &(*reinterpret_cast<char *>(&::g_011f6ed4)) ? (unsigned int*)(&(*reinterpret_cast<char *>(&::g_011f6ed4)) + 4)
                                                : (*(unsigned int*)& DAT_01202800 = 0, (unsigned int*)&DAT_01202800),
                             n > (*pi << 10)) ||
                            (f = apSound->flags, f & 0x10000))
                        {
                            LeaveCriticalSection(&cs);
                            return;
                        }
                    }
                }
            }
        }
    }
    Node* v3 = list.head;
    while (v3)
    {
        v35 = v3->sound;
        if ((unsigned char)(int)(apSound->id == v35->id))
        {
            LeaveCriticalSection(&cs);
            return;
        }
        v3 = v3 ? v3->next : 0;
    }
    Sound* v15 = (*(Sound* volatile*)&DAT_011f6d98)->Create(0);
    {
        unsigned int f = apSound->flags;
        {
            Sound* p = v15;
            p->flags = f;
        }
    }
    v15->Copy(apSound, 0);
    {
        unsigned int f = apSound->flags;
        {
            Sound* p = v15;
            p->flags = f | 0x8000;
        }
    }
    reinterpret_cast<::S_00a0c9f0 *>(&(list))->FUN_00a0c9f0((int *)&(v15));
    {
        struct U4
        {
            int a;
        };
        U4 unused;
    }
    {
        unsigned int f = apSound->flags;
        if (!(f & 0x20000000))
        {
            unsigned int n = v15->size;
            total += n;
        }
    }
    v35 = 0;
    int v1 = 0;
    {
        unsigned int* p;
        {
            struct U12
            {
                int a, b, c;
            };
            U12 unused;
        }
        {
            unsigned int f;
            {
                unsigned int g;
                {
                    unsigned int n;
                    while ((p = &(*reinterpret_cast<char *>(&::g_011f6ec8)) ? (unsigned int*)(&(*reinterpret_cast<char *>(&::g_011f6ec8)) + 4)
                                              : (*(unsigned int*)& DAT_01202800 = 0, (unsigned int*)&DAT_01202800),
                            total > (*p << 10)) &&
                           !(unsigned char)(int)(list.count == 0))
                    {
                        v35 = ((::Sound *)(reinterpret_cast<::FUN_00ae8010_cls *>(&(list))->PopFront()));
                        if (v35 &&
                            (((f = v35->flags, !(f & 0x20000)) && (g = v35->flags, !(g & 0x20000000))) || v1 > 30))
                        {
                            n = v35->size;
                            total -= n;
                            v9 = v35;
                            v13 = v9;
                            v13 ? ((DeleteView*)v13)->Destroy(1) : 0;
                        }
                        else
                        {
                            if (v35)
                                reinterpret_cast<::S_00a0c9f0 *>(&(list))->FUN_00a0c9f0((int *)&(v35));
                        }
                        v1++;
                    }
                }
            }
        }
    }
    {
        struct U16
        {
            int a, b, c, d;
        };
        U16 unused;
    }
    LeaveCriticalSection(&cs);
}

namespace fnv_00addc70 {
struct LinkedSoundQueue
{
    int pHead;
    int pTail;
    int iCount;
};
struct FUN_00ae76b0_shell
{
};
struct AudioThreadData
{
    int unk00;
    int iWriteIndex;
    int iReadIndex;
    LinkedSoundQueue kLists0;
    LinkedSoundQueue kLists1;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_00ae76b0_shell kQueue;
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
    CritSecA kLock;
    void ProcessAudioQueue();
};
// @fnv 0x00addc70
void AudioThreadData::ProcessAudioQueue()
{
    int item9 = 0;
    LinkedSoundQueue* pListU = &kLists0 + iReadIndex;
    int aPHead;
    int kPTail;
    int pHead2;
    int pTail2;
    int unkA;
    int unk1;
    int unk5;
    int unk9;
    int unkE;
    int aUnk;
    int unk2;
    int unk6;
    if (pListU == 0)
        return;
    while (!(bool)(int)(pListU->iCount == 0) && (aPHead = pListU->pHead) != 0 && (kPTail = pListU->pTail) != 0)
    {
        item9 = ((int)(reinterpret_cast<::SndStack70 *>((pListU))->FUN_00ae7f90()));
        if (reinterpret_cast<::fnv_00adf080::BSAudioManager_adf080 *>(this)->FUN_00adf080((::fnv_00adf080::SoundMessageRecord *)(item9)))
            return;
        reinterpret_cast<::Stack75f0 *>(&(kQueue))->FUN_00ae75f0((::SoundMessageRecord *)(item9));
    }
    if (!(bool)(int)(pListU->iCount == 0) && ((pHead2 = pListU->pHead) == 0 || (pTail2 = pListU->pTail) == 0))
        reinterpret_cast<::S_00ae8370_List *>((pListU))->FUN_00ae8370();
    EnterCriticalSection(&kLock);
    iWriteIndex = (iWriteIndex + 1) % 2;
    iReadIndex = (iWriteIndex + 1) % 2;
    item9 = ((int)(reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>(&(kQueue))->FUN_00ae76b0()));
    while (item9)
    {
        reinterpret_cast<::fnv_00adad80::Manager501 *>(this)->FUN_00adad80((::fnv_00adad80::Message501 *)(item9));
        item9 = ((int)(reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>(&(kQueue))->FUN_00ae76b0()));
    }
    LeaveCriticalSection(&kLock);
}
}  // namespace fnv_00addc70

struct Handle_ae5680
{
    int f0;
    char f4;
    int f8;
};

typedef bool(__cdecl* Resolver_ae5680)(int, void*, unsigned int*, int*);

struct AudioMgr_011f6d98
{
    void* vtbl;
    bool bReady;
    char pad[0x1f];
    Resolver_ae5680 pfnResolve;
};

struct AudioClass_ae5680
{
    Handle_ae5680 FUN_00ae5a50(const void* pPath, unsigned int uiFlags, int iExtra);
    Handle_ae5680* ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags);
};

// @fnv 0x00ae5680
Handle_ae5680* AudioClass_ae5680::ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags)
{
    int iState = 0;
    unsigned int uiOutFlags = 0;
    AudioMgr_011f6d98* pMgrJ = reinterpret_cast<AudioMgr_011f6d98*>(DAT_011f6d98);
    bool bReady_ = pMgrJ->bReady;
    AudioMgr_011f6d98* pMgr4;
    Resolver_ae5680 pfn3;
    char path3[260];
    int aIExtra;
    if (!bReady_)
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    pMgr4 = reinterpret_cast<AudioMgr_011f6d98*>(DAT_011f6d98);
    pfn3 = pMgr4->pfnResolve;
    aIExtra = 0;
    if (pfn3 == 0 || !pfn3(aiSoundId, path3, &uiOutFlags, &aIExtra))
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    if (uiOutFlags & 0x08000000)
    {
        uiFlags |= 1;
        uiFlags |= 0x08000000;
    }
    if (uiOutFlags & 0x02000000)
    {
        uiFlags |= 0x02000000;
        uiFlags &= ~0x10;
    }
    else if (uiOutFlags & 0x04000000)
    {
        uiFlags |= 0x04000000;
        uiFlags &= ~0x10;
    }
    if (path3[0] == 0)
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    Handle_ae5680 h7 = FUN_00ae5a50(path3, uiFlags, aIExtra);
    pOut->f0 = h7.f0;
    pOut->f4 = h7.f4;
    pOut->f8 = h7.f8;
    iState |= 1;
    return pOut;
}

struct FUN_00ae8650_cls
{
    unsigned int m_00, m_04, m_08, m_0c;
    void* m_10;
    float m_14, m_18, m_1c;
    FUN_00ae8650_cls* FUN_00ae8650();
};
// Initializes all members to zero and increments the reference count of the object stored in m_10 if it is non-null.
// @fnv 0x00ae8650
FUN_00ae8650_cls* FUN_00ae8650_cls::FUN_00ae8650()
{
    void* pTarget;
    {
        void** slot = &m_10;
        *slot = 0;
        if (*slot != 0)
        {
            pTarget = *slot;
            InterlockedIncrement((long*)((char*)pTarget + 4));
        }
    }
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    return this;
}

void __cdecl FUN_00fdbfd0();
extern int DAT_011f6ef0;
struct FUN_00ad90e0_shell
{
    FUN_00ad90e0_shell();
    ~FUN_00ad90e0_shell();
};
// Returns a pointer to a static singleton instance of FUN_00ad90e0_shell.
// @fnv 0x00ad9060
FUN_00ad90e0_shell* __cdecl FUN_00ad9060()
{
    static FUN_00ad90e0_shell sInstance;
    return &sInstance;
}


struct AudioHelperA
{
};

struct AudioHelperB
{
};

struct AudioSystemUpdate
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    AudioHelperA m_14;
};

struct AudioManagerUpdate
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8;
    CritSecA critical0dc;
    CritSecA m_cs;
    void FUN_00addc00();
};
// @fnv 0x00ada1d0
void FUN_00ada1d0_shell::InitUISounds(bool abPlayGameWorldSounds)
{
    if (!m_bUISoundsEnabled)
    {
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)($SG6265), 0);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuFocus"), 0x20000);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuCancel"), 0x20001);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuTab"), 0x20000);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuOK"), 0x20001);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuPrevNext"), 1);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("WPNRifleAssaultFire3D"), 0x102);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("FXBulletImpactConc"), 0x102);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UILoadScreenMicroFiche01"), 0x101);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UILoadScreenInitial"), 0x101);
        m_bUISoundsEnabled = true;
    }

    reinterpret_cast<::fnv_00ada330::OwnerQ *>((reinterpret_cast<FUN_00ada330_shell*>(this)))->FUN_00ada330();

    BSAudio* pAudio = DAT_011f6d98;
    volatile bool bAudioMultiThreaded = pAudio->bIsMultiThreaded;
    if (!bAudioMultiThreaded)
    {
        reinterpret_cast<::AudioManagerUpdate *>(&(reinterpret_cast<FUN_00addc00_shell&>(BSAudioManager::GetRandomGenerator())))->FUN_00addc00();
    }
}

// Calls the audio system update helper, then acquires m_cs and invokes two AudioHelperB methods if the lock is obtained.
// @fnv 0x00addc00
void AudioManagerUpdate::FUN_00addc00()
{
    AudioSystemUpdate* p = reinterpret_cast<AudioSystemUpdate*>(DAT_011f6d98);
    reinterpret_cast<::FUN_00aea100_cls *>(&(p->m_14))->UpdateAccumulatedTime();
    bool locked = TryEnterCriticalSection(&m_cs) != 0;
    if (locked)
    {
        reinterpret_cast<::fnv_00addc70::AudioThreadData *>((reinterpret_cast<AudioHelperB*>(FUN_00ad9060())))->ProcessAudioQueue();
        reinterpret_cast<::fnv_00adddd0::AudioUpdate *>((reinterpret_cast<AudioHelperB*>(FUN_00ad9060())))->FUN_00adddd0();
        LeaveCriticalSection(&m_cs);
    }
}

struct S_00ae77d0_Sem
{
    long initial;
    void* h;
    long max;
};
struct S_00ae77d0_Base
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
    S_00ae77d0_Base();
    virtual void v0();
};
struct FUN_00ae77d0 : S_00ae77d0_Base
{
    S_00ae77d0_Sem sem0;
    S_00ae77d0_Sem sem1;
    char unk48;
    FUN_00ae77d0();
    virtual void v0();
};
// Initializes two binary semaphores with initial count 0 and max 1, and sets unk48 to 1.
// @fnv 0x00ae77d0
FUN_00ae77d0::FUN_00ae77d0()
{
    S_00ae77d0_Sem* a = &sem0;
    a->initial = 0;
    a->max = 1;
    a->h = CreateSemaphoreA(0, a->initial, a->max, 0);
    S_00ae77d0_Sem* b = &sem1;
    b->initial = 0;
    b->max = 1;
    b->h = CreateSemaphoreA(0, b->initial, b->max, 0);
    unk48 = 1;
}


struct SyncSemaphore
{

    volatile long count;

    void* handle;
};

struct AudioWorker
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

    SyncSemaphore waitSemaphore;

    unsigned int unk38;

    SyncSemaphore signalSemaphore;

    unsigned int unk44;

    bool processing;

    void FUN_00ae7a50();
};

// Sets processing, signals signalSemaphore, waits on waitSemaphore, then clears processing.
// @fnv 0x00ae7a50
void AudioWorker::FUN_00ae7a50()
{

    processing = true;

    SyncSemaphore* signal = &signalSemaphore;

    ReleaseSemaphore(signal->handle, 1, 0);

    InterlockedIncrement(&signal->count);

    SyncSemaphore* waiting = &waitSemaphore;

    WaitForSingleObject(waiting->handle, 0xFFFFFFFF);

    InterlockedDecrement(&waiting->count);

    processing = false;
}


struct BSSemaphore_adf080
{
    long count;
    void* semaphore;
};

struct BSAudioManagerThread
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    BSSemaphore_adf080 doneSemaphore30;
    unsigned int unk38;
    BSSemaphore_adf080 workSemaphore3c;
    unsigned int unk44;
    bool waiting48;

    void FUN_00ae7ac0();
};

// Sets waiting48, releases workSemaphore3c, increments its count, and calls FUN_00aa6590.
// @fnv 0x00ae7ac0
void BSAudioManagerThread::FUN_00ae7ac0()
{
    waiting48 = true;
    BSSemaphore_adf080* semaphore = &workSemaphore3c;
    ReleaseSemaphore(semaphore->semaphore, 1, 0);
    InterlockedIncrement(&semaphore->count);
    reinterpret_cast<::fnv_00aa6590::FUN_00aa6590_cls *>(this)->FUN_00aa6590(0, 0);
}

struct S00ae6f10_SubObj_00ae6f10
{
};
struct S00ae6f10_FUN_00ae6f10_cls
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
    CritSecA m_10c;
    S00ae6f10_SubObj_00ae6f10 m_124;
    void FUN_00ae6f10(int arg);
};
// Calls a helper on the BSAudioManager singleton with this task, then assigns the task's pointer field to itself.
// @fnv 0x00ae7360
void AudioLoadTask::FUN_00ae7360()
{
    reinterpret_cast<::S00ae6f10_FUN_00ae6f10_cls *>((((Helper*)&BSAudioManager::GetRandomGenerator())))->FUN_00ae6f10((int)(this));
    SoundAssetTmp = SoundAssetTmp;
}
// @fnv 0x00ae7390
void AudioLoadTask7390::ReleaseSound(int, int)
{
    reinterpret_cast<::S00ae6f10_FUN_00ae6f10_cls *>((((::AudioHelper7390 *)(::FUN_00ad9060()))))->FUN_00ae6f10({});
    unsigned int uiSoundFlags;
    Sound7390* pDeleteFirst;
    Sound7390* pSoundToDelete;
    if (SoundAssetTmp && ((uiSoundFlags = SoundAssetTmp->uiFlags08) & 0x8000))
    {
        pDeleteFirst = SoundAssetTmp;
        pSoundToDelete = pDeleteFirst;
        pSoundToDelete ? pSoundToDelete->ScalarDeletingDestructor(1) : 0;
    }
    else if (SoundAssetTmp)
    {
        Sound7390* nodeToClear = SoundAssetTmp;
        nodeToClear->uiFlags10 = false ? nodeToClear->uiFlags10 | 0x200u : nodeToClear->uiFlags10 & ~0x200u;
        Sound7390* nodeToSet = SoundAssetTmp;
        nodeToSet->uiFlags10 = true ? nodeToSet->uiFlags10 | 0x10u : nodeToSet->uiFlags10 & ~0x10u;
    }
}

struct S00ae6f10_FUN_00ae6f10_frame
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
};

// Locks m_10c, passes the address of arg to m_124.FUN_00ae8150, then unlocks m_10c.
// @fnv 0x00ae6f10
void S00ae6f10_FUN_00ae6f10_cls::FUN_00ae6f10(int aValue)
{
    S00ae6f10_FUN_00ae6f10_frame frame;
    EnterCriticalSection(&m_10c);
    reinterpret_cast<::AE8150_List *>(&(m_124))->FUN_00ae8150((*(void *const *)((void*)&aValue)));
    LeaveCriticalSection(&m_10c);
}


struct AudioThreadEntry : BSAudioManagerThread
{
    int FUN_00ae74b0();
};

// Waits on doneSemaphore30, then loops calling FUN_00addc00 on the update object when DAT_01202d98 is set, sleeping 1 ms each iteration.
// @fnv 0x00ae74b0
int AudioThreadEntry::FUN_00ae74b0()
{
    BSSemaphore_adf080* semaphore = &doneSemaphore30;
    WaitForSingleObject(semaphore->semaphore, 0xFFFFFFFF);
    InterlockedDecrement(&semaphore->count);
    waiting48 = false;
    while (1)
    {
        if ((*reinterpret_cast<int *>(&::DAT_01202d98)) != 0)
        {
            reinterpret_cast<AudioManagerUpdate*>(FUN_00ad9060())->FUN_00addc00();
        }
        Sleep(1);
    }
    return 0;
}

struct ScrapHeapBuffer;
struct BSMapBase
{
};
struct FUN_00adc8b0_shell
{
    float FUN_00adc8b0(unsigned long);
};
// @fnv 0x00adc8b0
float FUN_00adc8b0_shell::FUN_00adc8b0(unsigned long auiKey)
{
    float fVol;
    {
        ScrapHeapBuffer* pBuffer;
        {
            int iUnusedA;
            int iUnusedB;
            pBuffer = 0;
            fVol = 0.0f;
            EnterCriticalSection((CritSecA*)((char*)this + 0xC4));
            reinterpret_cast<::S_00adc830_Map *>((((BSMapBase*)((char*)this + 0x64))))->GetAt(auiKey, (::S_00adc830_Entry *&)(pBuffer));
            LeaveCriticalSection((CritSecA*)((char*)this + 0xC4));
            if (pBuffer != 0)
            {
                fVol = *(float*)((char*)pBuffer + 8);
            }
        }
    }
    return fVol;
}
