#include <cstdint>
#include <cstddef>
// bsaudio/bsgamesound.cpp: BSGameSound, SoundView, AudioPathFixer (24 functions)

#include <cstddef>
#include <windows.h>
#include <objbase.h>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00ad7150_shell.h"
#include "fnv/decl/FUN_00aea210_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MgrX.h"
#include "fnv/decl/S_00ae8370_List.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00ee8000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "bsgamesound_decls.h"

// @fnv 0x00ae9cf0
bool BSGameSound::HasSoundFlagTwo()
{
    return (m_uiSoundFlags & 2) != 0;
}

// Computes a hash from the characters of pName after the first, returning 0 when pName is null.
// @fnv 0x00ae9d80
unsigned int BSGameSound::ComputeSoundNameHash(const char* pName)
{
    unsigned int hash = 0;
    if (!pName)
        return hash;
    {
        const char* p = pName;
        while (*(++p))
            hash = *p + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

// @fnv 0x00ae9d50
bool BSGameSound::LoadFromFilename(bool resolve)
{
    if (pFilename)
    {
        return HasMaster(pFilename, resolve);
    }
    else
    {
        return false;
    }
}
// @fnv 0x00ae9d10
bool BSGameSound::CanStartPlayback()
{
    return (m_uiSoundFlags & 1) && (m_uiSoundFlags & 0x08000000);
}

// @fnv 0x00ae9de0
bool BSGameSound::Prepare()
{
    if (m_uiSoundParameter11 & 2)
    {
        unsigned int duration = m_iSoundType;
        unsigned int zlimit = duration;
        unsigned int time = MersenneTwister::GetRandomGenerator()->GetRandomUInt(zlimit);
        Seek(time);
    }
    uiSoundFlags = true ? (uiSoundFlags | 0x800) : (uiSoundFlags & ~0x800);
    return true;
}

// @fnv 0x00ae97a0
void BSGameSound::Copy(BSGameSound* source, bool)
{
    m_uiSoundParameter12 = source->m_uiSoundParameter12;
    m_uiSoundParameter3 = source->m_uiSoundParameter3;
    HasMaster(source->pFilename, false);
    m_uiSoundResourceID = BSAudioManager::GetRandomGenerator().GetNextID();
    uiSoundFlags = source->uiSoundFlags;
    m_uiSoundParameter11 = source->m_uiSoundParameter11;
    m_iSoundType = source->m_iSoundType;
    m_uiSoundParameterA = source->m_uiSoundParameterA;
    m_uiReverbAttenuation = source->m_uiReverbAttenuation;
    m_uiSoundParameterB = source->m_uiSoundParameterB;
    m_uiSoundParameter6 = source->m_uiSoundParameter6;
    m_fRolloff = source->m_fRolloff;
    m_fMinimumDistance = source->m_fMinimumDistance;
    m_fMaximumDistance = source->m_fMaximumDistance;
    m_uiSoundCategory = source->m_uiSoundCategory;
    m_uiSoundParameter4 = source->m_uiSoundParameter4;
    m_uiSoundParameter10 = source->m_uiSoundParameter10;
    afValueAfterThirdFloat = source->afValueAfterThirdFloat;
    m_uiSoundParameter13 = source->m_uiSoundParameter13;
    m_uiSoundParameter9 = source->m_uiSoundParameter9;
    m_uiTrailingValue2 = source->m_uiTrailingValue2;
    m_pfnBooleanCallback = source->m_pfnBooleanCallback;
    m_pfnIntegerCallback = source->m_pfnIntegerCallback;
    m_pAudioSource = source->m_pAudioSource;
    m_pAudioData = source->m_pAudioData;
}

// @fnv 0x00ae9460
bool BSGameSound::HasMaster(const char* filename, bool resolve)
{
    bool bResult = true;
    if (!filename)
        return false;
    if (pFilename != filename)
        fnv::crt::strcpy_s(pFilename, 260, filename);
    BSAudio::GetRandomGenerator().vfn_18(pFilename);
    void(__cdecl * pfnCallback)(char*) = BSAudio::GetRandomGenerator().GetCallback();
    unsigned int iLength = strlen(pFilename);
    bool bDirectory = pFilename[iLength - 1] == '\\' || pFilename[iLength - 1] == '/';
    if (bDirectory && !m_uiSoundParameter3)
        m_uiSoundParameter3 = ComputeSoundNameHash(pFilename);
    if (resolve && bDirectory && pfnCallback)
    {
        pfnCallback(pFilename);
        BSAudio::GetRandomGenerator().vfn_18(pFilename);
    }
    else if (bDirectory && !resolve)
        bResult = false;
    if (!bDirectory || resolve)
        m_uiSoundParameter12 = ComputeSoundNameHash(pFilename);
    else
        m_uiSoundParameter12 = 0;
    return bResult;
}


// Initializes the sound's fields to zero/default values, sets bit 0x100 of uiSoundFlags, and clears bit 0x8000.
// @fnv 0x00ae95e0
void FUN_00ae95e0(char* pObject)
{
    BSGameSound* p = (BSGameSound*)pObject;
    p->m_uiSoundResourceID = 0;
    p->m_uiSoundFlags = 0;
    p->m_uiSoundParameter11 = 0;
    p->uiSoundFlags = 0;
    p->uiSoundFlags |= 0x100;
    p->m_iSoundType = 0;
    p->m_uiSoundParameterA = 0;
    p->m_uiReverbAttenuation = 0;
    p->m_uiSoundParameterB = 0;
    p->m_uiSoundParameter6 = 0;
    p->m_uiSoundParameter5 = 0;
    p->m_fRolloff = 1.0f;
    p->m_fMinimumDistance = 0.0f;
    p->m_fMaximumDistance = 0.0f;
    p->m_uiSoundCategory = 0;
    p->m_uiSoundParameter4 = 0;
    p->afValueAfterThirdFloat = g_011c7374_arg1;
    p->afThirdFloatArgument = 50.0f;
    p->m_uiSoundParameter13 = 0;
    p->m_uiSoundParameter7 = 0;
    p->m_uiSoundParameter2 = 0;
    p->m_uiPlaybackId = 0;
    p->m_uiSoundParameter12 = 0;
    p->m_uiSoundParameter3 = 0;
    p->m_uiSoundParameter1 = 3.4028234663852886e+38f;
    p->m_uiSoundParameter8 = 0;
    p->m_uiSoundParameter10 = 0;
    p->m_uiSoundParameter9 = 0;
    p->m_uiTrailingValue2 = 0;
    p->m_pfnBooleanCallback = 0;
    p->m_pfnIntegerCallback = 0;
    p->m_pAudioSource = 0;
    p->m_pAudioData = 0;
    p->uiSoundFlags = false ? (p->uiSoundFlags | 0x8000) : (p->uiSoundFlags & ~0x8000);
}

// If m_pfnIntegerCallback is set, calls it with m_pAudioData and the sound type, then clears both fields.
// @fnv 0x00ae9af0
void ClearCallback(char* pObject)
{
    BSGameSound* p = (BSGameSound*)pObject;
    if (p->m_pfnIntegerCallback != 0)
    {
        int id = p->m_iSoundType;
        p->m_pfnIntegerCallback(p->m_pAudioData, id);
        p->m_pAudioData = 0;
        p->m_pfnIntegerCallback = 0;
    }
}

struct FUN_00ae9c50_s
{
    int a, b, c, d;
    unsigned flags;
    int e;
    bool SetFlagState(bool v);
};
// Sets or clears bits in flags depending on v, and when v is false also sets bit 0x10 and sets e to 1; returns v.
// @fnv 0x00ae9c50
bool FUN_00ae9c50_s::SetFlagState(bool v)
{
    if (v)
    {
        flags |= 1;
        flags |= 0x100;
        flags &= 0xffffefff;
    }
    else
    {
        flags &= 0xfffffeff;
        flags |= 1;
        flags &= 0xffffefff;
        flags |= 0x10;
        e = 1;
    }
    return v;
}

struct OL4Alloc
{
    void* p;
    ~OL4Alloc()
    {}
};
struct NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___
{
    OL4Alloc alloc;
    void* a;
    void* b;
    ~NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___()
    {
        reinterpret_cast<::S_00ae8370_List *>(this)->FUN_00ae8370();
    }
};
struct OL4List : NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___
{
    ~OL4List()
    {}
};
struct FUN_00ae93f0
{
    virtual ~FUN_00ae93f0();
    char pad[0x188];
    OL4List list;
};
// @fnv 0x00ae93f0
FUN_00ae93f0::~FUN_00ae93f0()
{
    int unused[5];
}


struct SoundRange_00ae9b50
{
    char pad[0x28];
    float fStart;
    float m_fEndValue;
    unsigned int uiFlags;
    bool FUN_00ae9b50(unsigned int mask, float t);
};

// @fnv 0x00ae9b50
bool SoundRange_00ae9b50::FUN_00ae9b50(unsigned int mask, float afTime)
{
    if ((uiFlags & mask) == 0 && uiFlags != 0 && mask != 0)
        return false;
    float fSpan = m_fEndValue - fStart;
    fSpan = (fSpan < ::_DAT_01012060) ? fSpan * -1.0 : fSpan;
    if (fSpan >= 0.09375)
    {
        if ((fStart < m_fEndValue && (fStart > afTime || m_fEndValue < afTime)) ||
            (fStart > m_fEndValue && fStart > afTime && m_fEndValue < afTime))
            return false;
    }
    return true;
}

namespace fnv_00ae9ec0 {
struct FUN_00ae93f0
{
    virtual ~FUN_00ae93f0();
};
struct MemoryManager
{
};
struct FUN_00ae9ec0 : FUN_00ae93f0
{
    void* DeleteThis(unsigned int flags);
};
// Destroys the base object and, when bit 0 of flags is set, deallocates this via g_memoryManager, returning this.
// @fnv 0x00ae9ec0
void* FUN_00ae9ec0::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_00ae93f0 *>((this))->::FUN_00ae93f0::~FUN_00ae93f0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae9ec0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae9ec0

struct FUN_00ae9f70 : BSGameSound
{
    void SetFlag(bool abSet);
};
// @fnv 0x00ae9f70
void FUN_00ae9f70::SetFlag(bool abSet)
{
    this->uiSoundFlags =
        abSet ? (this->uiSoundFlags | 0x20000) : (this->uiSoundFlags & 0xfffdffff);
}

struct FUN_00ae9fd0 : BSGameSound
{
    bool IsSameSound(BSGameSound* apSound);
};
// Returns true when this sound's value at offset 0x188 is less than the other sound's value at offset 0x188.
// @fnv 0x00ae9fd0
bool FUN_00ae9fd0::IsSameSound(BSGameSound* apSound)
{
    return this->iPriority < apSound->iPriority;
}

struct FUN_00aea000 : BSGameSound
{
    bool IsSameSound(unsigned int aiToCompare);
};
// @fnv 0x00aea000
bool FUN_00aea000::IsSameSound(unsigned int aiToCompare)
{
    return this->iPriority < aiToCompare;
}

struct Interface
{
};

struct FUN_00aea590_shell
{
    bool FUN_00aea590(int param, std::intptr_t unused);
};

// Returns true when param is non-negative; otherwise logs "Audio system could not be initialized." and returns false.
// @fnv 0x00aea590
bool FUN_00aea590_shell::FUN_00aea590(int aiResult, std::intptr_t unused)
{
    if (aiResult >= 0)
        return true;
    ::FUN_0040fbe0();
    return false;
}

struct P03MM
{
};
struct FUN_00aeac20
{
    FUN_00aeac20(unsigned int a);
    static void* operator new(std::size_t)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0x230);
    }
};
struct FUN_00aea5c0
{
    FUN_00aeac20* Create(unsigned int a);
};
// Allocates a new FUN_00aeac20 object via the memory manager, constructing it with the given value, and returns it.
// @fnv 0x00aea5c0
FUN_00aeac20* FUN_00aea5c0::Create(unsigned int auiValue)
{
    return new FUN_00aeac20(auiValue);
}

namespace fnv_00aea700 {
struct MemoryManager
{
};
struct FUN_00aea700;
struct FUN_00aea700
{
    void* DeleteThis(unsigned int flags);
};
// Calls FUN_00aea210 on this, frees this via g_memoryManager._DeallocateAlias when flags has bit 0 set, and returns this.
// @fnv 0x00aea700
void* FUN_00aea700::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_00aea210_Class *>((this))->FUN_00aea210();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00aea700::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00aea700

struct Point3
{
    float x, y, z;
    Point3(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
};
// The position of a platform game sound; the pad stands for members not named here.
struct GameSoundPositionView
{
    char pad00[0x218];
    Point3 m_kPosition;
};
struct FUN_00aefd20 : BSGameSound
{
    Point3 GetPos();
};
// Returns the sound's position when either of the two checks passes, otherwise the origin (0,0,0).
// @fnv 0x00aefd20
Point3 FUN_00aefd20::GetPos()
{
    if (HasSoundFlagTwo() || CanStartPlayback())
        return ((GameSoundPositionView*)this)->m_kPosition;
    return Point3(0.0f, 0.0f, 0.0f);
}

struct SoundView
{
    virtual void v00();
    virtual bool v04();
    virtual void v08();
    virtual bool v0c();
    virtual void v10();
    virtual void v14(bool);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30(bool);
    virtual void v34();
    virtual void v38();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    float unk13c;
    char pad140[0x10];
    float unk150;
    bool Flag100()
    {
        return (unk8 & 0x100) != 0;
    }
    bool State20000()
    {
        return (unk10 & 0x20000) != 0;
    }
    bool Flag2000000()
    {
        return (unk8 & 0x2000000) != 0;
    }
    bool IsSpatial()
    {
        return (unk8 & 0x10) || (unk8 & 0x4000000) || (unk8 & 0x2000000);
    }
    bool FUN_00ae9960(float);
};
// Checks spatial and state flags to toggle v14/v30 and call v38 based on comparing unk150 against unk13c, then returns true.
// @fnv 0x00ae9960
bool SoundView::FUN_00ae9960(float unused)
{
    float distance2, maximum2, distance, maximum;
    if ((reinterpret_cast<::BSGameSound *>(this)->HasSoundFlagTwo() || reinterpret_cast<::BSGameSound *>(this)->CanStartPlayback()) && !Flag100() && !State20000() && v04() && IsSpatial() && !Flag2000000() &&
        (distance2 = unk150, maximum2 = unk13c, maximum2 < distance2))
    {
        v38();
        v14(true);
    }
    else if (State20000() && !v0c() && (distance = unk150, maximum = unk13c, distance < maximum))
    {
        v14(false);
        v30(true);
    }
    return true;
}

// BSWin32Audio - the PC audio manager.  This function is vtable slot 1 of it.

// The sound the manager is currently playing.  Slot 0 takes a flag and
// returns a status word.
struct BSAudioVoice
{
    virtual int FUN_00f0(int abEnable);
};

// A sink the manager hands a piece of work to.  Its slots are
// callbacks that receive the sink back as their only argument.
struct BSAudioSink
{
    virtual void FUN_00f0();
    virtual void FUN_00f4();
    virtual void FUN_00f8();
};

struct BSWin32Audio
{
    int unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned short unk06;
    int unk08;
    int unk0c;
    BSAudioVoice* unk10;
    char pad14[0x24];
    BSAudioSink* unk38;
    BSAudioSink* unk3c;
    void Shutdown();
};

extern void(__cdecl* g_pAudioShutdownCallback)();

// @fnv 0x00aea4d0
void BSWin32Audio::Shutdown()
{
    this->unk05 = 0;
    reinterpret_cast<::FUN_00ad7150_shell *>((this))->FUN_00ad7150();
    g_pAudioShutdownCallback();
    if (this->unk10)
    {
        BSAudioVoice* pVoice = this->unk10;
        BSAudioVoice* pVoiceChecked = pVoice;
        (pVoiceChecked != 0) ? pVoiceChecked->FUN_00f0(1) : 0;
        this->unk10 = 0;
    }
    if (this->unk3c)
    {
        this->unk3c->FUN_00f8();
        this->unk3c = 0;
    }
    if (this->unk38)
    {
        this->unk38->FUN_00f8();
        this->unk38 = 0;
    }
}

extern "C" char DAT_010a3b10, DAT_010a3ae0, DAT_010a3a78, DAT_010a3a38, DAT_010a39f8, DAT_01100fa4;
struct Heap
{
};
struct Manager
{
};
struct Vec
{
    float x, y, z;
    Vec()
    {
        x = 3.402823466e+38F;
        y = 3.402823466e+38F;
        z = 3.402823466e+38F;
    }
};
struct Sound
{
    virtual void s0();
    virtual void s1();
    virtual void s2(Vec*);
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12(float);
};
struct FUN_00aea730_Class : Sound
{
    char data[96];
    FUN_00aea730_Class(int);
};
struct Desc
{
    int size, flags;
    char rest[28];
};
struct Com
{
    virtual int q(void*, int*);
    virtual int r1();
    virtual int r2();
    virtual int create(Desc*, Com**, int);
    virtual int caps(void*);
    virtual int r5();
    virtual int coop(int, int);
};
struct Text
{
    char b[4];
    const char* Get2()
    {
        const char* z = this ? b + 4 : ((*reinterpret_cast<char *>(&::DAT_01202800)) = 0, &(*reinterpret_cast<char *>(&::DAT_01202800)));
        return z;
    }
    const char* Get()
    {
        return Get2();
    }
};
struct C
{
    char pad0[4];
    unsigned char flag4, flag5;
    char pad6[10];
    Sound* sound;
    char pad14[36];
    Com* com;
    Com* buffer;
    char capsdata[96];
    int window;
    void FUN_00ad7020(int);
    void SetWindow(int);
};
// @fnv 0x00aea230
void C::SetWindow(int aiWindow)
{
    Desc desc;
    int iResult;
    int iInterface;
    window = aiWindow;
    if (flag5)
        return;
    if (*(const unsigned char*)((Text*)&(*reinterpret_cast<char *>(&::g_011f6d9c)))->Get())
    {
        CoInitialize(0);
        iResult = ((int)(::FUN_00ee81e0((const void *)(0), (void **)(void *)(&com), (void *)(0))));
        if (!reinterpret_cast<::FUN_00aea590_shell *>(this)->FUN_00aea590(iResult, (std::intptr_t)(&DAT_010a3b10)))
            return;
        iResult = com->coop(window, 2);
        reinterpret_cast<::FUN_00aea590_shell *>(this)->FUN_00aea590(iResult, (std::intptr_t)(&DAT_010a3ae0));
        *(int*)capsdata = 96;
        iResult = com->caps(capsdata);
        reinterpret_cast<::FUN_00aea590_shell *>(this)->FUN_00aea590(iResult, (std::intptr_t)(&DAT_010a3a78));
        std::memset(&desc, 0, 36);
        desc.size = 36;
        desc.flags = 145;
        iResult = com->create(&desc, &buffer, 0);
        if (!reinterpret_cast<::FUN_00aea590_shell *>(this)->FUN_00aea590(iResult, (std::intptr_t)(&DAT_010a3a38)))
            return;
        iResult = buffer->q(&DAT_01100fa4, &iInterface);
        if (!reinterpret_cast<::FUN_00aea590_shell *>(this)->FUN_00aea590(iResult, (std::intptr_t)(&DAT_010a39f8)))
            return;
        sound = new FUN_00aea730_Class(iInterface);
    }
    if (sound)
    {
        Vec kZero{};
        sound->s2(&kZero);
        sound->s12(1.0f);
    }
    flag5 = 1;
    flag4 = 1;
    reinterpret_cast<::MgrX *>((((::Manager *)(::FUN_00ad9060()))))->FUN_00ad9640();
    FUN_00ad7020(0);
}


struct AudioPathFixer
{
    void FUN_00aea640(char* apName);
};
// If apName starts with "fx" or "song", copies it to a buffer, then rewrites apName to "data\sound\" followed by the original name.
// @fnv 0x00aea640
void AudioPathFixer::FUN_00aea640(char* apName)
{
    char acBuffer[260];
    if (apName && ((apName[0] == 102 && apName[1] == 120) ||
                   (apName[0] == 115 && apName[1] == 111 && apName[2] == 110 && apName[3] == 103)))
    {
        fnv::crt::strcpy_s(acBuffer, 260, apName);
        fnv::crt::strcpy_s(apName, 260, "data\\sound\\");
        fnv::crt::strcat_s(apName, 260, acBuffer);
    }
}

#include "generated/data/bsaudio/bsgamesound.inc"
