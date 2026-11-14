
// src/staging/blk_00ae0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include <new>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BSGameSound.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa63c0.h"
#include "fnv/decl/FUN_00ad6f40.h"
#include "fnv/decl/FUN_00ae9c50_s.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/O.h"
#include "fnv/decl/SndStack70.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a62000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00ae9000.h"
#include "fnv/symbols_00af0000.h"
#include "fnv/symbols_00af3000.h"
#include "fnv/symbols_00ee8000.h"
#include "fnv/symbols_01000000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_01093000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_010a3000.h"
#include "fnv/symbols_01100000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f7000.h"
#include "fnv/symbols_011f8000.h"
#include "fnv/symbols_01202000.h"
#include "../../include/layout_support.h"
#include "../../include/BSAudioListener.h"
#include "../../include/BSDiscBootSystemUtility.h"
#include <mmsystem.h>
#include <cwchar>
#include "fnv/decl/AudioMgr_adac30.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S_00afea20_Arr.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00afd000.h"
#include <math.h>
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_00af2000.h"

extern int DAT_010a42b4;

struct FUN_00af30a0_Class
{
    void* vtbl;
    char m_acCharacterBuffer[128];
    void* m_pObjectAt84;
    void* m_pObjectAt88;
    char bVisible;
    int m_iValueAt90;
    char m_cValueAt94;
    char m_cValueAt95;
    void* FUN_00af30a0();
};

// @fnv 0x00af30a0
void* FUN_00af30a0_Class::FUN_00af30a0()
{
    vtbl = &DAT_010a42b4;
    m_pObjectAt84 = 0;
    m_pObjectAt88 = 0;
    bVisible = 0;
    m_iValueAt90 = 0;
    m_cValueAt94 = 0;
    m_cValueAt95 = 0;
    std::memset((char*)&this->m_acCharacterBuffer, 0, 0x80);
    return this;
}

struct FUN_00ae8dc0_Class
{
    bool IsEqual(int a, int b);
};

// @fnv 0x00ae8dc0
bool FUN_00ae8dc0_Class::IsEqual(int a, int b)
{
    return a == b;
}


// Returns -1 if stream is null, otherwise calls _fseek with stream, offset and pad as the whence argument.
// @fnv 0x00aea180
long __cdecl FUN_00aea180(void* stream, long offset, int whence, int iWhenceArg)
{
    if (!stream)
        return -1;
    return std::fseek((std::FILE *)(stream), offset, iWhenceArg);
}

extern int DAT_010a39d8;
struct FUN_00ad7000_stub
{
    void FUN_00ad7000();
};
struct FUN_00aea210_Class
{
    void* vtbl;
    void FUN_00aea210();
};
// @fnv 0x00aea210
void FUN_00aea210_Class::FUN_00aea210()
{
    *reinterpret_cast<int**>(this) = &DAT_010a39d8;
    reinterpret_cast<FUN_00ad7000_stub*>(this)->FUN_00ad7000();
}

struct FUN_00aea890_Class
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    int* FUN_00aea890();
};

// @fnv 0x00aea890
int* FUN_00aea890_Class::FUN_00aea890()
{
    return &m_kPointA;
}

extern int DAT_010a3bb4;
struct FUN_00aeaab0_Class : ::BSAudioListener
{
    void FUN_00aeaab0();
};
// @fnv 0x00aeaab0
void FUN_00aeaab0_Class::FUN_00aeaab0()
{
    m_ppVirtualMethodTable = (void**)&DAT_010a3bb4;
    m_uiListenerFlags = 0;
}


// Returns -1 if stream is null, otherwise calls _fseek with stream, offset and pad as the whence argument.
// @fnv 0x00af1cf0
long __cdecl FUN_00af1cf0(void* stream, long offset, int whence, int iWhenceArg)
{
    if (!stream)
        return -1;
    return std::fseek((std::FILE *)(stream), offset, iWhenceArg);
}

extern int DAT_010a4288;

struct FUN_00af2f20_Class
{
    const void* vtable;
    void FUN_00af2f20();
};

// @fnv 0x00af2f20
void FUN_00af2f20_Class::FUN_00af2f20()
{
    vtable = &DAT_010a4288;
}

struct FUN_00af3120_Class
{
    void FUN_00af3120();
};

// @fnv 0x00af3120
void FUN_00af3120_Class::FUN_00af3120()
{
    *reinterpret_cast<void**>(this) = &DAT_010a42b4;
}

extern int DAT_010a42cc;
struct FUN_00af33f0_Class
{
    void* vtbl;
    int x;
    void* FUN_00af33f0();
};
// Sets the object's vtbl to DAT_010a42cc, clears x to 0, and returns this.
// @fnv 0x00af33f0
void* FUN_00af33f0_Class::FUN_00af33f0()
{
    vtbl = &DAT_010a42cc;
    x = 0;
    return this;
}

extern int DAT_010a42cc;
struct FUN_00af3420_Class
{
    void* vtbl;
    void FUN_00af3420();
};
// @fnv 0x00af3420
void FUN_00af3420_Class::FUN_00af3420()
{
    vtbl = &DAT_010a42cc;
}

extern int DAT_010a42dc;
struct FUN_00af35c0_Class
{
    void* vtbl;
    void FUN_00af35c0();
};
// @fnv 0x00af35c0
void FUN_00af35c0_Class::FUN_00af35c0()
{
    vtbl = &DAT_010a42dc;
}

extern int DAT_010a42ec;

struct FUN_00af38d0_Class
{
    void* vtbl;
    char bVisible;
    void* m_pObjectAt84;
    void* FUN_00af38d0();
};

// @fnv 0x00af38d0
void* FUN_00af38d0_Class::FUN_00af38d0()
{
    vtbl = &DAT_010a42ec;
    bVisible = 0;
    m_pObjectAt84 = 0;
    return this;
}

extern int DAT_010a42fc;

struct FUN_00af39c0_Class
{
    void* vtbl;
    void FUN_00af39c0();
};

// @fnv 0x00af39c0
void FUN_00af39c0_Class::FUN_00af39c0()
{
    vtbl = &DAT_010a42fc;
}

extern int DAT_010a4318;

struct FUN_00af3a80_Class
{
    void* p;
    void InitPointer();
};

// @fnv 0x00af3a80
void FUN_00af3a80_Class::InitPointer()
{
    p = &DAT_010a4318;
}

extern int DAT_010a4328;
struct FUN_00af3b20_Class
{
    void* vtbl;
    int i;
    void* FUN_00af3b20();
};
// Sets the object's vtbl to DAT_010a4328 and its i field to 0x10, then returns this.
// @fnv 0x00af3b20
void* FUN_00af3b20_Class::FUN_00af3b20()
{
    vtbl = &DAT_010a4328;
    i = 0x10;
    return this;
}

extern int DAT_010a4328;

struct FUN_00af3b50_Class
{
    void SetVTable();
};

// @fnv 0x00af3b50
void FUN_00af3b50_Class::SetVTable()
{
    *reinterpret_cast<void**>(this) = &DAT_010a4328;
}


struct FUN_00afd960_Class
{
    void* vtbl;
    int iField;
    void FUN_00afd960();
};

// @fnv 0x00afd960
void FUN_00afd960_Class::FUN_00afd960()
{
    void* pUnused[6];
    ::SwapByteQuadWords((::Vector4f *)(void *)((char*)&this->iField), 1);
}

class NiFile;
struct FileFinder
{
    static NiFile* __cdecl GetFile(const char*, int, unsigned int, unsigned int);
};

// @fnv 0x00afdf00
void __cdecl FUN_00afdf00(const char* apPath, int b, unsigned int c)
{
    FileFinder::GetFile(apPath, b, c, 0xffff);
}

extern int DAT_010a39d8;
struct FUN_00ad6f40_Class
{
    void FUN_00ad6f40();
};
struct FUN_00aea1b0_Class
{
    void* vtbl;
    char pad04[0x34];
    void* m_pDirectSound;
    void* m_pPrimaryBuffer;
    char m_acCaps[0x60];
    HWND m_hWindow;
    void* FUN_00ad6f40();
    FUN_00aea1b0_Class();
};
// Calls FUN_00ad6f40, sets vtbl to &DAT_010a39d8, zeroes offsets 0x38, 0x3c and 0xa0, and memsets 0x60 bytes at offset 0x40.
// @fnv 0x00aea1b0
FUN_00aea1b0_Class::FUN_00aea1b0_Class()
{
    new ((void *)this) ::FUN_00ad6f40();
    vtbl = (void*)&DAT_010a39d8;
    m_pDirectSound = 0;
    m_pPrimaryBuffer = 0;
    m_hWindow = 0;
    std::memset(m_acCaps, 0, sizeof(m_acCaps));
}

extern int DAT_010a3b7c;
struct FUN_00aea730_Class : ::BSAudioListener
{
    void* m_pListener3D;
    FUN_00aea730_Class* FUN_00aea730(int v);
};
// Sets the vtbl pointers, zeroes the field at 0x48 and the float at 0x3c, then stores v at 0x48 and returns this.
// @fnv 0x00aea730
FUN_00aea730_Class* FUN_00aea730_Class::FUN_00aea730(int aiValue)
{
    m_ppVirtualMethodTable = (void**)&DAT_010a3bb4;
    m_ppVirtualMethodTable = (void**)&DAT_010a3b7c;
    m_pListener3D = 0;
    m_fDopplerScale = 0.0f;
    m_pListener3D = (void*)(std::intptr_t)aiValue;
    return this;
}

struct MemoryManager
{
    void Deallocate(void*);
};
struct FUN_00aeaa80_Class
{
    void* FUN_00aeaa80(unsigned int flags);
    void FUN_00aea770();
};

struct FUN_00aefcf0_Class
{
    void* vtbl;
    void FUN_00aefcf0(float a, float b, float c);
};
// Forwards three float arguments to the virtual method at vtable index 20 of this object.
// @fnv 0x00aefcf0
void FUN_00aefcf0_Class::FUN_00aefcf0(float a, float b, float c)
{
    ((void(*)(void*, float, float, float))(*((void***)this))[20])(this, a, b, c);
}


struct FUN_00af1d20_Class
{
    char m_acData[0x2d0];
    int unk2d0;
    int unk2d4;
    int unk2d8;
    char unk2dc;
    void* FUN_00af1d20();
};
// Zeroes the object's first 0x2d0 bytes and clears the int fields at 0x2d0, 0x2d4, 0x2d8 and the byte at 0x2dc, then returns this.
// @fnv 0x00af1d20
void* FUN_00af1d20_Class::FUN_00af1d20()
{
    unk2d4 = 0;
    unk2d8 = 0;
    std::memset(this, 0, 0x2d0);
    unk2dc = 0;
    unk2d0 = 0;
    return this;
}

struct BSFile
{
    void Close();
    virtual ~BSFile();
};
// If f is non-null, calls Close on it, deletes it, and returns 0; otherwise returns -1.
// @fnv 0x00af2230
int __cdecl CloseAndDeleteFile(BSFile* apFile)
{
    if (!apFile)
        return -1;
    {
        BSFile* p = apFile;
        p->Close();
        delete p;
    }
    return 0;
}

struct DownloadableContentManager
{
    static void __cdecl GetRandomGenerator();
};
// @fnv 0x00af2750
char __cdecl FUN_00af2750()
{
    DownloadableContentManager::GetRandomGenerator();
    return 1;
}

struct FUN_00af2c50_Class
{
    bool FUN_00af2c50(int a, int b);
};

// @fnv 0x00af2c50
bool FUN_00af2c50_Class::FUN_00af2c50(int a, int b)
{
    return false;
}

extern int DAT_010a42dc;
struct FUN_00af3570_Class
{
    void* vtbl;
    int a[8];
    void* FUN_00af3570();
};
// Sets vtbl to &DAT_010a42dc and zeroes the eight-element array a, then returns this.
// @fnv 0x00af3570
void* FUN_00af3570_Class::FUN_00af3570()
{
    vtbl = &DAT_010a42dc;
    for (unsigned int i = 0; i < 8; ++i)
        a[i] = 0;
    return this;
}


struct FUN_00afd860_Class
{
    unsigned char m_acCharacterBuffer[4];
    int iValue;
    void FUN_00afd860(char* dst);
};

// @fnv 0x00afd860
void FUN_00afd860_Class::FUN_00afd860(char* dst)
{
    if (dst)
        ::FUN_00406d00(dst, 0x20, "%c%02X%c%c%08X", m_acCharacterBuffer[3], m_acCharacterBuffer[2], m_acCharacterBuffer[1],
                   m_acCharacterBuffer[0], iValue);
}

struct FUN_00afdbc0_Class
{
    void* vtbl;
    void* p;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    bool IsIndexInRange(int idx);
};
// @fnv 0x00afdbc0
bool FUN_00afdbc0_Class::IsIndexInRange(int idx)
{
    unsigned int a = idx;
    unsigned int b = m_kPointB;
    if (a >= b && a < m_kPointA * 16 + b)
        return true;
    return false;
}

struct FUN_00ae7b40_Class
{
    void* vtbl;
    int iCount;
    void* pItems;
    int iCapacity;
    FUN_00ae7b40_Class(int n);
};
// Sets the vtable, stores the element count, allocates count*4 bytes for pItems and zero-fills them.
// @fnv 0x00ae7b40
FUN_00ae7b40_Class::FUN_00ae7b40_Class(int aiCount)
{
    vtbl = (void*)&DAT_010a3370;
    iCount = aiCount;
    iCapacity = 0;
    int size7 = iCount * 4;
    pItems = ::FUN_00aa1070(size7);
    int size2 = iCount * 4;
    void* tmp = pItems;
    std::memset(tmp, 0, size2);
}

struct FUN_00ae7bc0_Class
{
    void* vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00ae7bc0_Class(int count);
};
// Sets the vtable, stores count, allocates count*4 bytes, zeroes the buffer and stores it in m_data.
// @fnv 0x00ae7bc0
FUN_00ae7bc0_Class::FUN_00ae7bc0_Class(int count)
{
    vtbl = &DAT_010a3390;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    unsigned int uiAllocSize = m_uiItemCount << 2;
    m_data = ::FUN_00aa1070(uiAllocSize);
    unsigned int size2 = m_uiItemCount << 2;
    void* p2 = m_data;
    std::memset(p2, 0, size2);
}

struct FUN_00ae7c40_Class
{
    const void* vtable;
    int size;
    void* buffer;
    int count;
    void* InitBuffer(int size);
};
// Sets the vtable, stores size, allocates size*4 bytes with NiMalloc, zeroes the buffer and returns this.
// @fnv 0x00ae7c40
void* FUN_00ae7c40_Class::InitBuffer(int size)
{
    vtable = &DAT_010a33b0;
    this->size = size;
    count = 0;
    int s3 = this->size << 2;
    buffer = ::FUN_00aa1070(s3);
    int s2 = this->size << 2;
    void* p2 = buffer;
    std::memset(p2, 0, s2);
    return this;
}


// Strips a drive prefix and a leading "data\" from source, then copies the remainder into destination with _strcpy_s.
// @fnv 0x00af4310
void CopyRelativeDataPath(const char* source, char* destination, size_t size)
{
    size_t length = std::strlen(source);
    if (length > 3 && source[1] == ':')
    {
        source += 3;
        length -= 3;
    }
    if (_strnicmp(source, "data\\", 5) == 0)
    {
        source += 5;
        length -= 5;
    }
    fnv::crt::strcpy_s(destination, size, source);
}

struct FUN_00afd8b0_Class
{
    unsigned int uiMagic;
    unsigned int uiSize;
    unsigned int uiType;
    unsigned int uiFlags;
    unsigned int uiElapsedMilliseconds;
    unsigned int uiLength;
    unsigned int uiHash;
    unsigned int uiCRC;
    unsigned short m_usPassCountLocal;
    void* FUN_00afd8b0();
};

// @fnv 0x00afd8b0
void* FUN_00afd8b0_Class::FUN_00afd8b0()
{
    void* pSub = (char*)&this->uiFlags;
    *(int*)pSub = 0;
    uiMagic = 0x415342;
    uiSize = 0x68;
    uiType = 0x24;
    *(int*)&this->uiElapsedMilliseconds = 0;
    *(int*)&this->uiLength = 0;
    *(int*)&this->uiHash = 0;
    *(int*)&this->uiCRC = 0;
    m_usPassCountLocal = 0;
    return this;
}

struct BSAudio
{
    char pad[0x38];
    void* pAudio;
};

struct FUN_00af1ba0_Class
{
    char pad[0x198];
    void* pAudio;
    bool EnsureAudio();
};
// @fnv 0x00af1ba0
bool FUN_00af1ba0_Class::EnsureAudio()
{
    if (pAudio)
        return true;
    BSAudio* audioA = DAT_011f6d98;
    void* p4 = audioA->pAudio;
    if (p4)
    {
        BSAudio* audio2 = DAT_011f6d98;
        void* p2 = audio2->pAudio;
        pAudio = p2;
        return true;
    }
    return false;
}

struct S00a0d390
{
    void* vtbl;
    int pad;
    void* p;

    void FUN_00ae8c30();
};


// Returns -1 if stream is null, otherwise seeks it with _fseek(stream, offset, pad) and returns the result.
// @fnv 0x00aeabf0
long FUN_00aeabf0(void* stream, long offset, int whence, int iOrigin)
{
    if (!stream)
        return -1;
    return std::fseek((std::FILE *)(stream), offset, iOrigin);
}

struct FUN_00aefd90_Class
{
    void FUN_00aefd90(int a, int b, int c);
};
// @fnv 0x00aefd90
void FUN_00aefd90_Class::FUN_00aefd90(int a, int b, int c)
{}

// Returns 0 when param_1 is null, otherwise returns the int at offset 0x38 if it is not -1, else the int at offset 0x150.
// @fnv 0x00af2290
struct OggTellSource
{
    char pad00[0x38];
    int position;
    char pad3c[0x150 - 0x3c];
    int fallbackPosition;
};

long __cdecl FUN_00af2290(void* apObject)
{
    if (apObject == 0)
        return 0;
    OggTellSource* pLocal = (OggTellSource*)apObject;
    return pLocal->position != -1 ? pLocal->position : pLocal->fallbackPosition;
}

struct FUN_00af2ed0_Class
{
    void* vtbl;
    char b1;
    int i1;
    char b2;
    char pad[0x1c];
    int i2;
    char pad2[0x14];
    int i3;
    FUN_00af2ed0_Class* FUN_00af2ed0();
};

// Sets the vtable pointer and zeroes the object's fields, then returns this.
// @fnv 0x00af2ed0
FUN_00af2ed0_Class* FUN_00af2ed0_Class::FUN_00af2ed0()
{
    char* p;
    vtbl = &DAT_010a4288;
    b1 = 0;
    i1 = 0;
    p = &b2;
    *p = 0;
    i2 = 0;
    i3 = 0;
    return this;
}

extern int DAT_010a42ec;
struct FUN_00af3900_Class
{
    void FUN_00af3900();
};
// @fnv 0x00af3900
void FUN_00af3900_Class::FUN_00af3900()
{
    *(void**)this = &DAT_010a42ec;
}

struct FUN_00af3980_Class
{
    void* vtbl;
    char bVisible;
    char m_cValueAt95;
    int iCount;
    char pad[0x84c - 0xc];
    int iField084c;
    FUN_00af3980_Class();
};
// @fnv 0x00af3980
FUN_00af3980_Class::FUN_00af3980_Class()
{
    vtbl = (void*)&DAT_010a42fc;
    bVisible = 0;
    m_cValueAt95 = 0;
    iCount = 0;
    iField084c = 0;
}

struct FUN_00af3a40_Class : ::BSDiscBootSystemUtility
{
    void* ResetState();
};
// Sets the vtable pointer and clears the fields at offsets 0x44, 0x48, 0x4c and bVisible, then returns this.
// @fnv 0x00af3a40
void* FUN_00af3a40_Class::ResetState()
{
    m_ppVirtualMethodTable = (void**)&DAT_010a4318;
    m_uiParentalLevel = 0;
    m_bNotificationActive = 0;
    m_pNotificationCallback = 0;
    m_acTitleID[0] = 0;
    return this;
}

struct BSFileDelete : public BSFile
{
    virtual ~BSFileDelete();
    void* FUN_00afff20(unsigned int flags);
};
BSFileDelete::~BSFileDelete()
{}
// Runs the BSFile destructor and, when flags has bit 0 set, frees this through g_memoryManager, then returns this.
// @fnv 0x00afff20
void* BSFileDelete::FUN_00afff20(unsigned int flags)
{
    this->BSFile::~BSFile();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}


extern int DAT_010a33d0;

struct FUN_00ae78a0_cls
{
    void* m_vtbl;
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
    void* m_h34;
    int unk38;
    int unk3C;
    void* m_h40;
    void FUN_00ae78a0();
};

// Resets the vtable pointer, closes the handles m_h40 and m_h34, then calls FUN_00aa63c0.
// @fnv 0x00ae78a0
void FUN_00ae78a0_cls::FUN_00ae78a0()
{
    m_vtbl = (void*)&DAT_010a33d0;
    CloseHandle(m_h40);
    CloseHandle(m_h34);
    reinterpret_cast<::FUN_00aa63c0 *>(this)->FUN_00aa63c0::~FUN_00aa63c0();
}

struct FUN_00ae8010_node
{
    FUN_00ae8010_node* m_00;
    FUN_00ae8010_node* m_04;
    void* m_08;
};

struct FUN_00ae8010_alloc
{
    unsigned int m_uiCount;
    void FreeNode(FUN_00ae8010_node* node);
};

struct FUN_00ae8010_cls
{
    FUN_00ae8010_node* m_00;
    FUN_00ae8010_node* m_04;
    FUN_00ae8010_alloc m_08;
    void* PopFront();
};

struct FUN_00ae8010_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

// Removes the head node from the linked list, clears its payload pointer, frees the node, decrements the count and returns the payload.
// @fnv 0x00ae8010
void* FUN_00ae8010_cls::PopFront()
{
    FUN_00ae8010_pad pad;
    FUN_00ae8010_node* pNode = m_04;
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

struct FUNPayload_b4549
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
};

class FUN_00ae8b40_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUNPayload_b4549 m_payload;
    FUNPayload_b4549* GetPayload(FUNPayload_b4549* out);
};

// Copies m_payload into out, sets flags to 1, and returns out.
// @fnv 0x00ae8b40
FUNPayload_b4549* FUN_00ae8b40_cls::GetPayload(FUNPayload_b4549* out)
{
    unsigned int flags = 0;
    *out = m_payload;
    flags |= 1;
    return out;
}

class FUN_00ae8b90_cls
{
  public:
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
    virtual void v0f(float value);

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_flags10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    float m_f24;

    void SetFlagAndApplyValue(bool flag);
};

// Sets or clears bit 0x400 in m_flags10 according to flag, then calls v0f with m_f24.
// @fnv 0x00ae8b90
void FUN_00ae8b90_cls::SetFlagAndApplyValue(bool flag)
{
    m_flags10 = flag ? (m_flags10 | 0x400) : (m_flags10 & 0xfffffbff);
    v0f(m_f24);
}

struct AE91F0MapItem
{
    AE91F0MapItem* m_pkNext;
    void* m_key;
    void* m_val;
};

// NiTMapBase::RemoveAll
class AE91F0Map
{
  public:
    virtual ~AE91F0Map();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void ClearValue(AE91F0MapItem* pkItem);
    virtual void vfunc05();
    virtual void DeleteItem(AE91F0MapItem* pkItem);

    unsigned int m_uiHashSize;
    AE91F0MapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    void ClearAll();
};
// @fnv 0x00ae8c30
void S00a0d390::FUN_00ae8c30()
{
    int p;
    int P;

    this->vtbl = (void*)&DAT_010a3370;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(this->p);
}

// Walks every hash bucket, unlinking each item, calling ClearValue and DeleteItem on it, then resets m_uiCount to zero.
// @fnv 0x00ae91f0
void AE91F0Map::ClearAll()
{
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        while (m_ppkHashTable[i])
        {
            AE91F0MapItem* pkSave = m_ppkHashTable[i];
            m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
            ClearValue(pkSave);
            DeleteItem(pkSave);
        }
    }
    m_uiCount = 0;
}

extern int(* FUN_00fdf1c4)(char*);

struct S_00ae9290_Object
{
// @fnv 0x00ae9290
    virtual void FUN_00ae9290_f0()
    {}
    virtual void FUN_00ae9290_f1()
    {}
};

struct S_00ae9290_Class
{
    void* p;

    void FUN_00ae9290();
};

void S_00ae9290_Class::FUN_00ae9290()
{
    if (this->p != 0)
    {
        char* p = (char*)this->p;

        if (FUN_00fdf1c4(p + 4) == 0)
            ((S_00ae9290_Object*)p)->FUN_00ae9290_f1();
    }
}


struct FUN_00aea0a0_Class
{
    void* vtbl;
    unsigned long m_tick;
    int m_zero;

    void* InitTimer();
};

// @fnv 0x00aea0a0
void* FUN_00aea0a0_Class::InitTimer()
{
    m_zero = 0;
    vtbl = (void*)0x927c0;
    m_tick = GetTickCount();
    return this;
}

extern "C" int(* DAT_00fdf060)(void);

struct FUN_00aea0d0_Class
{
    void* vtbl;
    unsigned int m_kPointB;
    unsigned int m_kPointA;
    void Init();
};

// @fnv 0x00aea0d0
void FUN_00aea0d0_Class::Init()
{
    m_kPointA = 0;
    vtbl = (void*)0x000927c0;
    m_kPointB = DAT_00fdf060();
}

struct FUN_00aea800_cls
{
    int unk00;
    void FUN_00aea800();
};

// @fnv 0x00aea800
void FUN_00aea800_cls::FUN_00aea800()
{}

extern "C" const double DAT_010a3be8;
struct FNVRenderInterface_00aea8b0
{
    virtual void Function00() = 0;
    virtual void Function04() = 0;
    virtual void Function08() = 0;
    virtual void Function0C() = 0;
    virtual void Function10() = 0;
    virtual void Function14() = 0;
    virtual void Function18() = 0;
    virtual void Function1C() = 0;
    virtual void Function20() = 0;
    virtual void Function24() = 0;
    virtual void Function28() = 0;
    virtual void Function2C() = 0;
    virtual void Function30() = 0;
    virtual void ApplyParameters(float a, float b, float c, float d, float e, float f, int enable) = 0;
    virtual void ApplyColor(float red, float green, float blue, int enable) = 0;
    virtual void Function3C() = 0;
    virtual void Function40() = 0;
    virtual void Commit() = 0;
};
struct FNVColorRenderer_00aea8b0
{
    unsigned int unknown00;
    float red;
    float blue;
    float green;
    unsigned int unknown10, unknown14, unknown18, unknown1C;
    unsigned int unknown20, unknown24, unknown28, unknown2C;
    unsigned int unknown30, unknown34, unknown38, unknown3C;
    unsigned int unknown40, unknown44;
    FNVRenderInterface_00aea8b0* renderer;
    float scale4c, scale50, scale54;
    float scale58, scale5c, scale60;
    void ApplyToRenderer();
};
// If a renderer is set, applies the scaled red/green/blue color and the scale parameters to it, then commits.
// @fnv 0x00aea8b0
void FNVColorRenderer_00aea8b0::ApplyToRenderer()
{
    if (renderer)
    {
        renderer->ApplyColor(static_cast<float>(red * DAT_010a3be8), static_cast<float>(green * DAT_010a3be8),
                             static_cast<float>(blue * DAT_010a3be8), 1);
        renderer->ApplyParameters(scale58, scale60, scale5c, scale4c, scale54, scale50, 1);
        renderer->Commit();
    }
}

struct S_00aea990_Triple
{
    int unk00;
    int unk04;
    int unk08;
};

struct S_00aea990_Class
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
    S_00aea990_Triple unk4c;
    S_00aea990_Triple unk58;

    void CopyTriplePair(int* p, int* q);
};

// Copies the triple pointed to by q into unk4c and the triple pointed to by p into unk58.
// @fnv 0x00aea990
void S_00aea990_Class::CopyTriplePair(int* pSource, int* qSource)
{
    unk4c = *reinterpret_cast<S_00aea990_Triple*>(qSource);
    unk58 = *reinterpret_cast<S_00aea990_Triple*>(pSource);
}

struct FUN_00aea9d0_Listener
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C(float value, int flag)
    {}
};

struct FUN_00aea9d0_Obj
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
    FUN_00aea9d0_Listener* unk48;

    void NotifyListenerValue(float value);
};

// If the listener pointer at offset 0x48 is non-null, calls its vf3C virtual with value and 1.
// @fnv 0x00aea9d0
void FUN_00aea9d0_Obj::NotifyListenerValue(float value)
{
    if (this->unk48 != 0)
    {
        this->unk48->vf3C(value, 1);
    }
}

struct S_00aeaa10_P3
{
    float x;
    float y;
    float z;
};
struct S_00aeaa10_Obj
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
    virtual void FUN_x40(float x, float y, float z, bool flag);
};
struct S_00aeaa10_Cls
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
    S_00aeaa10_P3 pos;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S_00aeaa10_Obj* obj;
    void FUN_00aeaa10(const S_00aeaa10_P3* p);
};
// Copies the given position into pos and, if obj is set, forwards its x, y, z to obj->FUN_x40 with true.
// @fnv 0x00aeaa10
void S_00aeaa10_Cls::FUN_00aeaa10(const S_00aeaa10_P3* pPos)
{
    pos = *pPos;
    if (obj)
    {
        obj->FUN_x40(pPos->x, pPos->y, pPos->z, true);
    }
}

struct MMStub
{
};
struct Stub1A4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* pBuf;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct FUN_00ae9360_Base
{
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
    FUN_00ae9360_Base();
    virtual ~FUN_00ae9360_Base();
};

struct FUN_00aeae10 : public FUN_00ae9360_Base
{
    int unk198;
    int unk19C;
    int unk1A0;
    Stub1A4 unk1A4;
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
    unsigned short unk20C;
    unsigned short unk20E;
    unsigned short unk210;
    unsigned short unk212;
    unsigned short unk214;
    unsigned short unk216;
    NiPoint3 unk218;
    char unk224;
    int unk228;
    int unk22C;
    FUN_00aeae10();
    virtual ~FUN_00aeae10();
};

// Initialises the object's fields to zero, sets unk218 to NiPoint3_ZERO, allocates 0x12 bytes into unk1A4.pBuf and sets the unk20C..unk214 values.
// @fnv 0x00aeae10
FUN_00aeae10::FUN_00aeae10()
{
    unk1DC = 0;
    unk19C = 0;
    unk1A0 = 0;
    unk1D8 = 0;
    unk1D0 = 0;
    unk1D4 = 0;
    unk198 = 0;
    unk204 = 0;
    unk208 = 0;
    unk224 = 0;
    unk218 = ::NiPoint3::ZERO;
    std::memset(&unk1A4, 0, sizeof(Stub1A4));
    void* p = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MMStub *>(&::g_memoryManager))))->FUN_00aa3e40(0x12);
    unk1A4.pBuf = p;
    unk1C8 = 0;
    unk20C = 0;
    unk20E = 600;
    unk210 = 1400;
    unk212 = 2600;
    unk214 = 5000;
    unk228 = 0;
    unk22C = 0;
}

struct SndGuid
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct SndEffectDesc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    SndGuid guidDSFXClass;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
};

struct SndWaveFormat
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};

struct SndBufferDesc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    SndWaveFormat* lpwfxFormat;
    SndGuid guid3DAlgorithm;
};

struct SndUnknown
{
    virtual long QueryInterface(const SndGuid* riid, void* ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};

struct SndParamObject : public SndUnknown
{
    virtual long SetAllParameters(const void* params);
};

struct SndBuffer : public SndUnknown
{
    virtual long GetCaps(void* caps);
    virtual long GetCurrentPosition(unsigned long* a, unsigned long* b);
    virtual long GetFormat(void* a, unsigned long b, unsigned long* c);
    virtual long GetVolume(long* v);
    virtual long GetPan(long* v);
    virtual long GetFrequency(unsigned long* v);
    virtual long GetStatus(unsigned long* v);
    virtual long Initialize(void* a, void* b);
    virtual long Lock(unsigned long offset, unsigned long bytes, void** p1, unsigned long* b1, void** p2,
                                unsigned long* b2, unsigned long flags);
    virtual long Play(unsigned long a, unsigned long b, unsigned long c);
    virtual long SetCurrentPosition(unsigned long a);
    virtual long SetFormat(void* a);
    virtual long SetVolume(long v);
    virtual long SetPan(long v);
    virtual long SetFrequency(unsigned long v);
    virtual long Stop();
    virtual long Unlock(void* p1, unsigned long b1, void* p2, unsigned long b2);
    virtual long Restore();
    virtual long SetFX(unsigned long count, SndEffectDesc* desc, unsigned long* results);
    virtual long AcquireResources(unsigned long a, unsigned long b, unsigned long* c);
    virtual long GetObjectInPath(const SndGuid* obj, unsigned long idx, const SndGuid* iid, void* out);
};

struct Snd3DBuffer : public SndUnknown
{
    virtual long GetAllParameters(void* a);
    virtual long GetConeAngles(unsigned long* a, unsigned long* b);
    virtual long GetConeOrientation(void* a);
    virtual long GetConeOutsideVolume(long* a);
    virtual long GetMaxDistance(float* a);
    virtual long GetMinDistance(float* a);
    virtual long GetMode(unsigned long* a);
    virtual long GetPosition(void* a);
    virtual long GetSourceVelocity(void* a);
    virtual long SetAllParameters(const void* a, unsigned long b);
    virtual long SetConeAngles(unsigned long a, unsigned long b, unsigned long c);
    virtual long SetConeOrientation(float a, float b, float c, unsigned long d);
    virtual long SetConeOutsideVolume(long a, unsigned long b);
    virtual long SetMaxDistance(float a, unsigned long b);
    virtual long SetMinDistance(float a, unsigned long b);
};

struct SndDevice : public SndUnknown
{
    virtual long CreateSoundBuffer(SndBufferDesc* desc, SndBuffer** out, void* outer);
};

struct SndStream
{
    int iState;
    unsigned int uiPos;
    unsigned int uiHeadSize;
    unsigned int uiBodySize;
    unsigned int uiTailSize;
    unsigned int uiTailPos;
    char* pHead;
    char* pBody;
    char* pTail;
};

struct SndHeap
{
    void Deallocate(void* p);
};

struct SndFloatHolder
{
    int unk00;
    float fValue;
};

extern float g_fSndConeValue;
extern float g_fSndReverb2;
extern const SndGuid g_GUID_SndFX;
extern const SndGuid g_IID_SndFXParams;


class FUN_00aec530_cls
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
    virtual void SetVolume(float f);
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void SetPosition(float x, float y, float z);

    void Release(int a);
    void FUN_00aec530();

    int unk04;
    unsigned int m_uiValue1;
    int unk0C;
    int unk10;
    int m_iValueAt14;
    int unk18;
    short unk1C;
    short m_sFrequency;
    int unk20;
    float m_fPlaybackVolume;
    int unk28;
    int unk2C;
    int unk30;
    short unk34;
    char m_cFileName[0x11A];
    float m_fUnk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int m_iLoopStart;
    int m_iLoopEnd;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    SndDevice* m_pDirectInputDevice;
    SndBuffer* m_pBuffer8;
    int unk1A0;
    SndBufferDesc m_kDesc;
    char* m_pData;
    SndBuffer* m_pBuffer;
    int unk1D0;
    Snd3DBuffer* m_p3DBuffer;
    int unk1D8;
    unsigned int m_uiSize;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    float m_afReverb[5];
    int unk204;
    SndParamObject* m_pReverb;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    SndStream* m_pBinaryStream;
};


class S_Subsys
{
  public:
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
    virtual int Query();
};

class FUN_00aed420_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
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
    S_Subsys* m_198;
    S_Subsys* m_19c;
    S_Subsys* m_1a0;
    bool FUN_00aed420();
};

// @fnv 0x00aed420
bool FUN_00aed420_cls::FUN_00aed420()
{
    int hr = (int)0x80004005;
    if (m_19c != 0 && m_198 != 0)
    {
        hr = m_19c->Query();
        if (m_1a0 != 0)
        {
            m_1a0->Query();
        }
    }
    if (hr >= 0)
    {
        m_10 |= 0x40;
        m_10 &= 0xffffffdf;
    }
    return hr >= 0;
}

struct IDSBufStub
{
    virtual long QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long GetCaps(void*);
    virtual long GetCurrentPosition(unsigned long*, unsigned long*);
    virtual long GetFormat(void*, unsigned long, unsigned long*);
    virtual long GetVolume(long*);
    virtual long GetPan(long*);
    virtual long GetFrequency(unsigned long*);
    virtual long GetStatus(unsigned long*);
    virtual long Initialize(void*, void*);
    virtual long Lock(unsigned long, unsigned long, void**, unsigned long*, void**, unsigned long*,
                                unsigned long);
    virtual long Play(unsigned long, unsigned long, unsigned long);
    virtual long SetCurrentPosition(unsigned long);
    virtual long SetFormat(const void*);
    virtual long SetVolume(long);
    virtual long SetPan(long);
    virtual long SetFrequency(unsigned long);
    virtual long Stop();
};

struct AudioSoundStub
{
    void* vtbl;
    int unk04;
    unsigned int uiFlags;
    int unk0c;
    unsigned int uiState;
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
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    void* pAudio198;
    IDSBufStub* pBuffer;
    IDSBufStub* pBuffer3D;
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
    int* pStatus;

    bool FUN_00aed4c0();
};

// @fnv 0x00aed4c0
bool AudioSoundStub::FUN_00aed4c0()
{
    long hr = 0x80004005;
    if (pBuffer && pAudio198)
    {
        if ((bool)(((uiFlags & 0x4000000) || (uiFlags & 0x2000000)) ? 1 : 0) && pStatus && *pStatus != 5 &&
            *pStatus != 6)
        {
            *pStatus = 4;
        }
        else if (!(bool)(((uiFlags & 0x4000000) || (uiFlags & 0x2000000)) ? 1 : 0) || !pStatus)
        {
            hr = pBuffer->Stop();
            pBuffer->SetCurrentPosition(0);
            if (pBuffer3D)
            {
                pBuffer3D->Stop();
                pBuffer3D->SetCurrentPosition(0);
            }
            if (hr >= 0)
                uiState &= ~0x20;
        }
        if (uiState & 0x40)
            uiState &= ~0x40;
    }
    return hr >= 0;
}

struct S_00af01e0_Snd
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1c();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2c();
    virtual int v30();
    virtual int v34();
    virtual int v38();
    virtual int v3c();
    virtual int v40();
    virtual int v44(unsigned int b);
};
struct S_00af01e0_Cls
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    short unk158;
    unsigned short unk15a;
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
    S_00af01e0_Snd* unk19c;
    int FUN_00af01e0(float f);
};
// Scales unk15a by f, clamps the result to 100..200000, and if unk19c and unk198 are set calls unk19c->v44 with it; returns whether the result was non-negative.
// @fnv 0x00af01e0
int S_00af01e0_Cls::FUN_00af01e0(float afScale)
{
    int hr = 0x80004005;
    unsigned int v = (unsigned int)(unk15a * afScale);
    if (v < 100)
        v = 100;
    else if (v > 200000)
        v = 200000;
    if (unk19c && unk198)
        hr = unk19c->v44(v);
    return hr >= 0;
}



struct AF0320WaveFormat
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};

struct AF0320SoundBuffer
{
    virtual long QueryInterface(const void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long GetCaps(void* pCaps);
    virtual long GetCurrentPosition(unsigned int* pPlay, unsigned int* pWrite);
    virtual long GetFormat(AF0320WaveFormat* pFormat, unsigned int uiSize, unsigned int* puiWritten);
    virtual long GetVolume(long* plVolume);
    virtual long GetPan(long* plPan);
    virtual long GetFrequency(unsigned int* puiFrequency);
    virtual long GetStatus(unsigned int* puiStatus);
    virtual long Initialize(void* pDS, void* pDesc);
    virtual long Lock(unsigned int a, unsigned int b, void** c, unsigned int* d, void** e, unsigned int* f,
                                unsigned int g);
    virtual long Play(unsigned int a, unsigned int b, unsigned int c);
    virtual long SetCurrentPosition(unsigned int uiPosition);
};

class AF0320Sound
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int m_iDurationMs;
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
    AF0320SoundBuffer* m_pCacheEntry;

    void SeekToPosition(unsigned int uiPositionMs);
};

// Validates the requested position against the sound duration, reads the buffer format, and sets the buffer's current position in bytes.
// @fnv 0x00af0320
void AF0320Sound::SeekToPosition(unsigned int uiPositionMs)
{
    if (!m_pCacheEntry || uiPositionMs >= (unsigned int)m_iDurationMs)
    {
        ::FUN_005b5e40();
        return;
    }
    AF0320WaveFormat kFormat;
    std::memset(&kFormat, 0, 18);
    m_pCacheEntry->GetFormat(&kFormat, 18, 0);
    int iRate = (int)(kFormat.nAvgBytesPerSec / 1000.0);
    m_pCacheEntry->SetCurrentPosition(uiPositionMs * iRate);
}

struct FUN_00af13f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_flags10;
    void SetFlag20000(unsigned char enable);
};
// @fnv 0x00af13f0
void FUN_00af13f0_cls::SetFlag20000(unsigned char enable)
{
    m_flags10 = enable != 0 ? (m_flags10 | 0x20000) : (m_flags10 & 0xfffdffff);
}

extern int DAT_011f7128;

struct FUN_00af1af0_cls
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
    void* m_1a0;
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
    void* m_1d8;
    void FUN_00af1af0();
};

struct NiStdObject
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual int v02() = 0;
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
};

// @fnv 0x00af1af0
void FUN_00af1af0_cls::FUN_00af1af0()
{
    if (m_1a0 != 0)
    {
        DAT_011f7128--;
        ((NiStdObject*)m_1a0)->v18();
        while (((NiStdObject*)m_1a0)->v02() != 0)
        {
        }
        m_1a0 = 0;
    }
    if (m_1d8 != 0)
    {
        while (((NiStdObject*)m_1d8)->v02() != 0)
        {
        }
        m_1d8 = 0;
    }
}

struct S_00af1c00_Obj
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
    virtual int v2c(unsigned int, unsigned int, void**, void**, int, int, int);
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual int v4c(void*, void*, int, int);
};
struct S_00af1c00_cls
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
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00af1c00_Obj* m_19c;
    bool FUN_00af1c00(int a1, unsigned int a2, unsigned int a3, char* a4);
};
// @fnv 0x00af1c00
bool S_00af1c00_cls::FUN_00af1c00(int aiOffset, unsigned int a2, unsigned int auiSize, char* apSource)
{
    void* p1 = 0;
    void* p9 = 0;
    if (m_19c->v2c(a2, auiSize, &p1, &p9, 0, 0, 0) < 0)
        return false;
    void* dst = p1;
    if (apSource)
        std::memmove(dst, apSource + aiOffset, auiSize);
    else
        std::memset(dst, 0, auiSize);
    m_19c->v4c(p1, p9, 0, 0);
    return true;
}

struct FUN_00af1d80_tgt
{
    virtual int Tick(int flag);
};


struct FUN_00af1d80_cls
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
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    FUN_00af1d80_tgt* m_2d0;
    int unk2d4;
    int unk2d8;
    unsigned char m_2dc;
    void UpdateAndReleaseTarget();
};

// If m_2dc is set, calls FUN_00ee81e6 on this; if m_2d0 is non-null, ticks it with 1 and clears m_2d0.
// @fnv 0x00af1d80
void FUN_00af1d80_cls::UpdateAndReleaseTarget()
{
    if (m_2dc != 0)
        ::FUN_00ee81e6(this);
    if (m_2d0 != 0)
    {
        FUN_00af1d80_tgt* pTarget = m_2d0;
        FUN_00af1d80_tgt* pTargetCopy = pTarget;
        (void)(pTargetCopy != 0 ? pTargetCopy->Tick(1) : 0);
        m_2d0 = 0;
    }
}

struct FUN_00af2100_cls
{
    unsigned int FUN_00af2100(unsigned char* p, unsigned int n);
};


// Repeatedly calls FUN_00ee8204 over p, advancing by the returned byte count until the running total exceeds n, and returns the total.
// @fnv 0x00af2100
unsigned int FUN_00af2100_cls::FUN_00af2100(unsigned char* pucData, unsigned int uiLength)
{
    unsigned int cur4 = 0;
    unsigned int sum = 0;
    unsigned int outTmp = 0;
    unsigned char* r3 = pucData;
    while (sum <= uiLength)
    {
        cur4 = ((unsigned int)(::FUN_00ee8204(this, (char *)(r3), uiLength - sum, 0, 2, 1, (int *)(unsigned int *)(&outTmp))));
        sum += cur4;
        r3 += cur4;
        if (cur4 == 0)
        {
            uiLength = 0;
        }
    }
    return sum;
}

typedef int(__cdecl* FUN_00af2180_ProcFn)(void* self, void* arg0, int product, int* out, int one);

struct FUN_00af2180_cls
{
    int unk00;
    int m_04;
    FUN_00af2180_ProcFn m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    unsigned char m_2c;
};

// If p is non-null, calls p->m_08 with arg0 and a*b, adds the result to p->m_04, and returns it.
// @fnv 0x00af2180
int __cdecl CallProcAndAccumulate(void* arg0, int iLeft, int iRight, FUN_00af2180_cls* p)
{
    if (p == 0)
    {
        return 0;
    }
    FUN_00af2180_cls* objTmp = p;
    unsigned char _flag = objTmp->m_2c;
    if (_flag == 0)
    {
        objTmp = objTmp;
    }
    int one = 1;
    int r = objTmp->m_08(objTmp, arg0, iLeft * iRight, &one, 1);
    objTmp->m_04 += r;
    int s7 = r;
    int res = s7;
    return res;
}

class AF2200Handler
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void Handle(void* pvEvent, void* pvData);
};

// Returns -1 if pvHandler is null; otherwise calls its Handle method with pvEvent and pvData and returns 0.
// @fnv 0x00af2200
int DispatchHandlerEvent(void* pvHandler, void* pvEvent, void* pvUnused, void* pvData)
{
    if (!pvHandler)
        return -1;
    AF2200Handler* pkHandler = static_cast<AF2200Handler*>(pvHandler);
    pkHandler->Handle(pvEvent, pvData);
    return 0;
}

struct FUN_00af2c30_cls
{
    int unk00;
    void FUN_00af2c30();
};

// @fnv 0x00af2c30
void FUN_00af2c30_cls::FUN_00af2c30()
{}

struct FUN_00af2c60_cls
{
    void* vtbl;
    void FUN_00af2c60();
};

// @fnv 0x00af2c60
void FUN_00af2c60_cls::FUN_00af2c60()
{}

// FUN_00af2c70 - an empty member function in an /Od module.
//
// The original is 11 bytes:
//   55           push ebp
//   8b ec        mov  ebp, esp
//   51           push ecx
//   89 4d fc     mov  dword ptr [ebp-4], ecx   <- the /Od spill of `this`
//   8b e5        mov  esp, ebp
//   5d           pop  ebp
//   c3           ret
//
// Under /Od MSVC 2008 always gives a member function a frame and always
// homes `this` at [ebp-4]; with no locals at all the frame is just the
// single `push ecx`, which is why the epilogue is `mov esp,ebp; pop ebp; ret`
// instead of a bare `pop ebp; ret`.
//
// The class name is deliberately tag-free so that the tag appears exactly
// once, in the mangled name of the member function itself.

struct FnvEmptyThiscall70_Class
{
    void FUN_00af2c70();
};

// @fnv 0x00af2c70
void FnvEmptyThiscall70_Class::FUN_00af2c70()
{}

// FUN_00af2c80 - an empty member function in an /Od module.
//
// The original is 11 bytes:
//   55           push ebp
//   8b ec        mov  ebp, esp
//   51           push ecx
//   89 4d fc     mov  dword ptr [ebp-4], ecx   <- the /Od spill of `this`
//   8b e5        mov  esp, ebp
//   5d           pop  ebp
//   c3           ret
//
// Under /Od MSVC 2008 always gives a member function a frame and always
// homes `this` at [ebp-4]; with no locals at all the frame is just the
// single `push ecx`, which is why the epilogue is `mov esp,ebp; pop ebp; ret`
// instead of a bare `pop ebp; ret`.

struct FnvEmptyThiscall_Class
{
    void FUN_00af2c80();
};

// @fnv 0x00af2c80
void FnvEmptyThiscall_Class::FUN_00af2c80()
{}

extern "C" __declspec(dllimport) bool __cdecl SteamAPI_IsSteamRunning();
extern "C" __declspec(dllimport) void* __cdecl SteamUser();

struct SteamUserObj
{
    virtual void v0();
    virtual bool v1();
};

typedef void(__cdecl* FUN_00af2db0_Notify)(int code, int value);

struct FUN_00af2db0_cls
{
    unsigned char m_flag00;
    FUN_00af2db0_Notify m_pfnNotify;
    void UpdateSteamRunningFlag();
};

// Recomputes m_flag00 from SteamAPI_IsSteamRunning and SteamUser, and calls m_pfnNotify(0, ...) when the flag changes.
// @fnv 0x00af2db0
void FUN_00af2db0_cls::UpdateSteamRunningFlag()
{
    unsigned char oldFlag = m_flag00;
    m_flag00 = (SteamAPI_IsSteamRunning() && SteamUser() != 0 && ((SteamUserObj*)SteamUser())->v1()) ? 1 : 0;
    if (m_flag00 != oldFlag)
    {
        if (m_pfnNotify != 0)
        {
            m_pfnNotify(0, -(m_flag00 != 0 ? -1 : 0));
        }
    }
}

// @fnv 0x00af3c40
int __cdecl WildcardMatch(const char* pcString, const char* pcPattern)
{
    char c3 = *pcPattern++;
    if (c3 == 0)
        return *pcString == 0;
    if (c3 == '?')
        return pcString ? WildcardMatch(pcString + 1, pcPattern) : 0;
    if (c3 == '*')
    {
        if (*pcPattern == 0)
            return 1;
        while (*pcString)
        {
            int result3 = WildcardMatch(pcString, pcPattern);
            if (result3)
                return result3;
            pcString++;
        }
        return 2;
    }
    if (c3 == '[')
    {
        if (*pcString == 0)
            return 0;
        bool invertX = *pcPattern == '^';
        if (invertX)
            pcPattern++;
        const char* end = pcPattern;
        bool escaped5 = false;
        while (*end)
        {
            if (escaped5)
                escaped5 = false;
            else if (*end == '\\')
                escaped5 = true;
            else if (*end == ']')
                break;
            end++;
        }
        if (*end != ']')
            return 0;
        c3 = 0;
        escaped5 = *pcPattern == '-';
        while (pcPattern < end)
        {
            if (!escaped5 && *pcPattern == '\\')
                escaped5 = true;
            else if (!escaped5 && *pcPattern == '-')
                c3 = pcPattern[-1];
            else
            {
                char sc = *pcString;
                char folded = (unsigned char)((g_uiMatchFlags & 1) ? sc : (unsigned char)toupper(sc));
                if (pcPattern[1] != '-')
                {
                    if (!c3)
                        c3 = *pcPattern;
                    while (c3 <= *pcPattern)
                    {
                        if ((unsigned char)((g_uiMatchFlags & 1) ? c3 : (unsigned char)toupper(c3)) == folded)
                            return invertX ? 0 : WildcardMatch(pcString + 1, end + 1);
                        c3++;
                    }
                }
                c3 = escaped5 = false;
            }
            pcPattern++;
        }
        return invertX ? WildcardMatch(pcString + 1, end + 1) : 0;
    }
    if (c3 == '\\')
    {
        if ((c3 = *pcPattern++) == 0)
            return 0;
    }
    {
        char sc6;
        return (unsigned char)((g_uiMatchFlags & 1) ? c3 : (unsigned char)toupper(c3)) ==
                       (unsigned char)(sc6 = *pcString, (g_uiMatchFlags & 1) ? sc6 : (unsigned char)toupper(sc6))
                   ? WildcardMatch(pcString + 1, pcPattern)
                   : 0;
    }
}

// Scans a string, skipping backslash-escaped characters, and returns true if it contains an unescaped wildcard character (?, [, ], *, ^).
// @fnv 0x00af3fd0
bool HasWildcardChars(const char* pcString)
{
    char c;
    while (*pcString != 0)
    {
        if (*pcString == '\\' && pcString[1] != 0)
        {
            pcString++;
        }
        else
        {
            c = *pcString;
            {
                int isWild;
                if (!(c == '?' || c == '[' || c == ']' || c == '*' || c == '^'))
                {
                    isWild = 0;
                }
                else
                {
                    isWild = 1;
                }
                if ((unsigned char)isWild)
                {
                    return true;
                }
            }
        }
        pcString++;
    }
    return false;
}

struct AllocatorToken
{
    unsigned char state;
};
struct FUN_00afd920_Class
{
    int value;
    void UpdateValue();
};
// Calls FUN_00ec3bad on the object's value field and stores the result back into value.
// @fnv 0x00afd920
void FUN_00afd920_Class::UpdateValue()
{
    AllocatorToken allocator = {};
    AllocatorToken copy = allocator;
    FUN_00afd920_Class* self = this;
    self->value = fnv::crt::byteswap_ulong(self->value);
}

struct AFD980Value
{
    unsigned __int64 m_uiCurrentValue;

    void ReverseBytes();
};

// Reverse the byte order of the 8-byte value in place.
// @fnv 0x00afd980
void AFD980Value::ReverseBytes()
{
    unsigned __int64 uiCopy = m_uiCurrentValue;
    for (unsigned int i = 0; i < 8; i++)
        reinterpret_cast<unsigned char*>(this)[i] = reinterpret_cast<unsigned char*>(&uiCopy)[7 - i];
}

struct Flag
{
    bool m_kPointB;
};

struct FUN_00afdb80_cls
{
    char pad00[8];
    unsigned int* m_08;

    void FUN_00afdb80();
};


// @fnv 0x00afdb80
void FUN_00afdb80_cls::FUN_00afdb80()
{
    Flag flag_ = {};
    bool copy = flag_.m_kPointB;
    unsigned int** pValue = &m_08;
    *pValue = ((unsigned int *)(std::uintptr_t)(fnv::crt::byteswap_ulong((std::uint32_t)(std::uintptr_t)(*pValue))));
}

struct FUN_00afdc00_Item
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

class FUN_00afdc00_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiItemCount;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    FUN_00afdc00_Item* m_pItems;
    bool FUN_00afdc00(int a1);
};

// @fnv 0x00afdc00
bool FUN_00afdc00_cls::FUN_00afdc00(int aiIndex)
{
    unsigned int n;
    unsigned int i;
    for (i = 0; i < (n = m_uiItemCount); i++)
    {
        if (reinterpret_cast<::FUN_00afdbc0_Class *>(&(m_pItems[i]))->IsIndexInRange(aiIndex))
        {
            return true;
        }
    }
    return false;
}

struct S_00aff060_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;

    int FUN_00aff060();
};


// Returns 0 if FlushFileBuffers returns nonzero for this->unk10, otherwise 4.
// @fnv 0x00aff060
int S_00aff060_Class::FUN_00aff060()
{
    return FlushFileBuffers(this->unk10) ? 0 : 4;
}


// Calls CopyFileA with the given paths and fail-if-exists flag, returning 0 on success or 4 on failure.
// @fnv 0x00aff0d0
int __cdecl CopyFileChecked(const char* lpExistingFileName, const char* lpNewFileName, unsigned char bFailIfExists)
{
    return CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists) ? 0 : 4;
}

class FUN_00aff180_base
{
  public:
    virtual ~FUN_00aff180_base();
    FUN_00aff180_base();
};

class FUN_00aff180 : public FUN_00aff180_base
{
  public:
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned char m_unk2c;
    unsigned char m_unk2d;
    unsigned char m_unk2e;
    unsigned char m_unk2f;
    unsigned char m_unk30;
    unsigned char m_unk31;
    unsigned char m_unk32;
    unsigned char m_unk33;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
    unsigned int m_unk40;
    unsigned char m_unk44;
    unsigned char m_unk45;
    unsigned char m_unk46;
    unsigned char m_unk47;
    unsigned int m_unk48;
    unsigned int m_unk4c;
    unsigned int m_unk50;
    unsigned int m_unk54;
    unsigned int m_unk58;
    unsigned int m_unk5c;
    unsigned int m_unk60;
    unsigned int m_unk64;
    unsigned int m_unk68;
    unsigned int m_unk6c;
    unsigned int m_unk70;
    unsigned int m_unk74;
    unsigned int m_unk78;
    unsigned int m_unk7c;
    unsigned int m_unk80;
    unsigned int m_unk84;
    unsigned int m_unk88;
    unsigned int m_unk8c;
    unsigned int m_unk90;
    unsigned int m_unk94;
    unsigned int m_unk98;
    unsigned int m_unk9c;
    unsigned int m_unka0;
    unsigned int m_unka4;
    unsigned int m_unka8;
    unsigned int m_unkac;
    unsigned int m_unkb0;
    unsigned int m_unkb4;
    unsigned int m_unkb8;
    unsigned int m_unkbc;
    unsigned int m_unkc0;
    unsigned int m_unkc4;
    unsigned int m_unkc8;
    unsigned int m_unkcc;
    unsigned int m_unkd0;
    unsigned int m_unkd4;
    unsigned int m_unkd8;
    unsigned int m_unkdc;
    unsigned int m_unke0;
    unsigned int m_unke4;
    unsigned int m_unke8;
    unsigned int m_unkec;
    unsigned int m_unkf0;
    unsigned int m_unkf4;
    unsigned int m_unkf8;
    unsigned int m_unkfc;
    unsigned int m_unk100;
    unsigned int m_unk104;
    unsigned int m_unk108;
    unsigned int m_unk10c;
    unsigned int m_unk110;
    unsigned int m_unk114;
    unsigned int m_unk118;
    unsigned int m_unk11c;
    unsigned int m_unk120;
    unsigned int m_unk124;
    unsigned int m_unk128;
    unsigned int m_unk12c;
    unsigned int m_unk130;
    unsigned int m_unk134;
    unsigned int m_unk138;
    unsigned int m_unk13c;
    unsigned int m_unk140;
    unsigned int m_unk144;
    unsigned int m_unk148;
    unsigned int m_unk14c;
    unsigned int m_unk150;
    FUN_00aff180();
    virtual ~FUN_00aff180();
};

// @fnv 0x00aff180
FUN_00aff180::FUN_00aff180()
{
    m_unk28 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk44 = 0;
    m_unk14c = 0;
    m_unk148 = 0;
    m_unk150 = 0;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = 0xffffffff;
    m_unk3c = 0;
    m_unk40 = 0;
    m_unk2c = 0;
}

struct BucketTableStorage
{
    struct Node
    {
        Node* next;
    };
    unsigned int bucketCount;
    Node** data;
    unsigned int count;
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void FreeItem(Node*);
    virtual void unk14();
    virtual void FreeNode(Node*);

    void ClearAll()
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            while (data[i])
            {
                Node* node = data[i];
                data[i] = data[i]->next;
                FreeItem(node);
                FreeNode(node);
            }
        }
        count = 0;
    }
};

struct FUN_00ae8ce0 : BucketTableStorage
{
    virtual ~FUN_00ae8ce0();
};

// @fnv 0x00ae8ce0
FUN_00ae8ce0::~FUN_00ae8ce0()
{
    unsigned int i;
    Node* node;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(data);
}

struct FUN_00ae8d90
{
    int* m_vtbl;
    int m_auiShapeKeys;
    void* m_data;
    ~FUN_00ae8d90();
};

// @fnv 0x00ae8d90
FUN_00ae8d90::~FUN_00ae8d90()
{
    unsigned int i;
    void* node;
    m_vtbl = &DAT_010a33b0;
    reinterpret_cast<::AE91F0Map *>((((S00a0d390*)this)))->ClearAll();
    ::FUN_00aa10f0(m_data);
}

struct AudioVoice
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
    virtual void SetMinDistance(float dist, int flags);
    virtual void SetMaxDistance(float dist, int flags);
};

struct SoundObj
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
    virtual void SetPosition(NiPoint3 pos);

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
    float minDistance;
    float maxDistance;
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
    void* unk198;
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
    AudioVoice* voice;
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
    NiPoint3 position;
    bool is3D;

    void FUN_00aefda0(float maxDist, float minDist);
};

// @fnv 0x00aefda0
void SoundObj::FUN_00aefda0(float maxDist, float minDist)
{
    float fScaledValue = maxDist;
    if (minDist != minDistance || maxDist != maxDistance)
    {
        minDistance = minDist;
        maxDistance = maxDist;
        if (is3D)
            SetPosition(position);
    }
    if (reinterpret_cast<::BSGameSound *>(this)->HasSoundFlagTwo() && voice && unk198)
    {
        if (maxDist > 0.0)
        {
            voice->SetMaxDistance(1000000000.0f, 0);
            maxDistance = maxDist;
        }
        else
        {
            voice->SetMaxDistance(1000000000.0f, 0);
            maxDistance = 69.99f;
        }
        if (minDist > 0.0)
        {
            voice->SetMinDistance(1000000000.0f, 0);
            minDistance = minDist;
        }
        else
        {
            voice->SetMinDistance(1000000000.0f, 0);
            minDistance = 1000000000.0f;
        }
    }
}

extern const double DAT_010a3e68;
extern const double DAT_010a3e60;
struct AudioAttenuation
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
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    short first;
    short second;
    short third;
    short fourth;
    short fifth;
    void SetAttenuationValues(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
};
// @fnv 0x00aeff60
void AudioAttenuation::SetAttenuationValues(unsigned short ausFirst, unsigned short ausSecond, unsigned short ausThird,
                                            unsigned short ausFourth, unsigned short ausFifth)
{
    first = (unsigned short)(ausFirst ? (float)std::log10((float)(ausFirst / 100.0)) * DAT_010a3e68 : DAT_010a3e60);
    second =
        (unsigned short)(ausSecond ? (float)std::log10((float)(ausSecond / 100.0)) * DAT_010a3e68 : DAT_010a3e60);
    third = (unsigned short)(ausThird ? (float)std::log10((float)(ausThird / 100.0)) * DAT_010a3e68 : DAT_010a3e60);
    fourth =
        (unsigned short)(ausFourth ? (float)std::log10((float)(ausFourth / 100.0)) * DAT_010a3e68 : DAT_010a3e60);
    fifth = (unsigned short)(ausFifth ? (float)std::log10((float)(ausFifth / 100.0)) * DAT_010a3e68 : DAT_010a3e60);
}

class CAF0290SoundBuffer
{
  public:
    virtual long QueryInterface(const void* riid, void** ppvObject);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long GetCaps(void* pCaps);
    virtual long GetCurrentPosition(unsigned long* pulPlay, unsigned long* pulWrite);
    virtual long GetFormat(void* pFormat, unsigned long ulSize, unsigned long* pulWritten);
    virtual long GetVolume(long* plVolume);
    virtual long GetPan(long* plPan);
    virtual long GetFrequency(unsigned long* pulFrequency);
};

class CAF0290Sound
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
    unsigned short unk158;
    unsigned short m_usBaseFrequency;
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
    void* m_pvPlaying;
    CAF0290SoundBuffer* m_pCacheEntry;

    float GetFrequencyRatio();
};

// Queries the sound buffer's frequency and returns it divided by m_usBaseFrequency, or 1.0 if unavailable.
// @fnv 0x00af0290
float CAF0290Sound::GetFrequencyRatio()
{
    long hr = 0x80004005;
    unsigned long ulFrequency = 0;
    float fRatio = 1.0f;
    if (m_pCacheEntry && m_pvPlaying)
        hr = m_pCacheEntry->GetFrequency(&ulFrequency);
    if (hr >= 0)
        fRatio = (float)ulFrequency / m_usBaseFrequency;
    return fRatio;
}

struct AudioFile
{
    virtual AudioFile* Destroy(unsigned int);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int offset, int origin);
    int position;
    int(__cdecl* read)(AudioFile*, void*, int, int*, int);
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    bool valid;
    __forceinline bool IsValid()
    {
        return valid;
    }
    char unk2d;
    short unk2e;
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
};
struct AudioState
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
    int position;
    AudioFile* file;
};
AudioFile* __cdecl OpenAudioFile(const char*, int, unsigned int, unsigned int);
// Handles audio file operations by op code: opens a file, closes it, reads into a buffer, or seeks, updating state->position and returning a status code.
// @fnv 0x00af0400
int AudioFileOp(AudioState* state, unsigned int op, void* data, int size)
{
    int result2;
    const char* pathX;
    AudioFile* openFileB;

    AudioFile* closeFile6;
    void* buffer2;
    AudioFile* readFile2;

    int offset;
    int originX;
    AudioFile* seekFile_2;
    {
        AudioFile* deleteA;
        AudioFile* deleteB;
        AudioFile* deleteC;
        AudioFile* deleteD;
        {
            bool isValid2;
            int count3;
            int bytes2;
            int readResult5;
            result2 = 0;
            switch (op)
            {
            case 3: {
                pathX = (const char*)data;
                openFileB = OpenAudioFile(pathX, 0, 0x4000, 8);

                if (!openFileB || !(isValid2 = openFileB->valid))
                {
                    if (openFileB)
                    {
                        deleteD = openFileB;
                        deleteB = deleteD;
                        deleteB ? deleteB->Destroy(1) : 0;
                    }
                    return 0x101;
                }
                state->position = 0;
                state->file = openFileB;
                return 0;
            }
            case 4: {
                closeFile6 = state->file;
                if (!closeFile6)
                {
                    ::FUN_005b5e40();
                    return 0x104;
                }
                {
                    deleteA = closeFile6;
                    deleteC = deleteA;
                    deleteC ? deleteC->Destroy(1) : 0;
                }
                return 0;
            }
            case 0: {
                buffer2 = data;
                readFile2 = state->file;
                if (!readFile2)
                    return 0x105;
                {
                    count3 = 1;
                    bytes2 = readFile2->read(readFile2, buffer2, size, &count3, 1);
                    readFile2->position += bytes2;
                    readResult5 = bytes2;
                    result2 = readResult5;
                }
                state->position += result2;
                return result2;
            }
            case 2: {
                offset = (int)(intptr_t)data;
                originX = DAT_010a2484;
                if (size == 0)
                    originX = DAT_010a2480;
                else if (size == 2)
                    originX = DAT_010a2488;
                seekFile_2 = state->file;
                if (!seekFile_2)
                    return 0x107;
                seekFile_2->Seek(offset, originX);
                state->position = seekFile_2->unk038 != -1 ? seekFile_2->unk038 : seekFile_2->unk150;
                return 0;
            }
            default:
                return 0x10c;
            }
        }
    }
}



struct S_008785e0
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_unk0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
    void* m_unk10;

    int OpenFile(const char* lpFileName);
};

// Opens lpFileName with CreateFileA using access and disposition derived from m_unk04/m_unk08, retries on failure, and maps GetLastError to a result code.
// @fnv 0x00afeac0
int S_008785e0::OpenFile(const char* lpFileName)
{
    unsigned long dwDesiredAccess = 0;
    unsigned long dwShareMode = 1;
    unsigned long dwCreationDisposition = 0;
    unsigned long dwFlagsAndAttributes = 0;
    unsigned long err = 0;
    int iResult = 0;
    {
        __int64 fileSize;

        switch (this->m_unk04)
        {
        case 0:
            dwDesiredAccess = 0x80000000;
            break;
        case 1:
            dwDesiredAccess = 0xC0000000;
            break;
        case 2:
            dwDesiredAccess = 0x40000000;
            break;
        }

        switch (this->m_unk08)
        {
        case 0:
            dwCreationDisposition = 3;
            break;
        case 1:
            dwCreationDisposition = 3;
            break;
        case 2:
            dwCreationDisposition = 2;
            break;
        case 3:
            dwCreationDisposition = 5;
            break;
        case 4:
            dwCreationDisposition = 1;
            break;
        }

        dwFlagsAndAttributes = 0x8000000;
        if (this->m_unk0c)
        {
            dwFlagsAndAttributes |= 0x60000000;
        }

        this->m_unk10 =
            CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, 0, dwCreationDisposition, dwFlagsAndAttributes, 0);
        if (this->m_unk10 == (void*)-1 && this->m_unk08 == 1)
        {
            dwCreationDisposition = 2;
            this->m_unk10 = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, 0, dwCreationDisposition,
                                        dwFlagsAndAttributes, 0);
        }

        if (this->m_unk10 == (void*)-1)
        {
            err = GetLastError();
            int code;
            switch (err)
            {
            case 0:
                code = 0;
                break;
            case 2:
                code = 1;
                break;
            case 3:
                code = 2;
                break;
            case 19:
                code = 3;
                break;
            default:
                code = 4;
                break;
            }
            iResult = code;
        }
        else
        {
            iResult = 0;
        }

        if (iResult == 0 && this->m_unk08 == 1 && !this->m_unk0c)
        {
            iResult = reinterpret_cast<::O *>((this))->FUN_00afeef0(0, 0, (::_LARGE_INTEGER *)(2));
        }
    }

    return iResult;
}


struct Win32ReadFile
{
    void* pVtable;
    int unk04;
    int unk08;
    bool bInvalid;
    HANDLE hFile;

    int Read(void* apBuffer, unsigned int auiSize, int aiUnused, unsigned __int64* apuiRead);
};

// Reads auiSize bytes from hFile into apBuffer via ReadFile, maps GetLastError to a result code, and stores the byte count in apuiRead on success.
// @fnv 0x00afecd0
int Win32ReadFile::Read(void* apBuffer, unsigned int auiSize, int aiUnused, unsigned __int64* apuiRead)
{
    int iResult5 = 0;
    DWORD dwBytesRead = 0;
    DWORD dwSucceeded3 = 0;
    DWORD dwError = 0;
    DWORD dwSize6;

    if (bInvalid)
    {
        iResult5 = 4;
    }
    else
    {
        dwSize6 = auiSize;
        dwSucceeded3 = ReadFile(hFile, apBuffer, dwSize6, &dwBytesRead, 0);
        if (dwSucceeded3 <= 0)
        {
            dwError = GetLastError();
            int iError;
            switch (dwError)
            {
            case ERROR_SUCCESS:
                iError = 0;
                break;
            case ERROR_FILE_NOT_FOUND:
                iError = 1;
                break;
            case ERROR_PATH_NOT_FOUND:
                iError = 2;
                break;
            case ERROR_WRITE_PROTECT:
                iError = 3;
                break;
            default:
                iError = 4;
                break;
            }
            iResult5 = iError;
        }
        else
        {
            iResult5 = 0;
            *apuiRead = dwBytesRead;
        }
    }
    return iResult5;
}

class FUN_00aff090_cls
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    HANDLE m_hHandle;
    void CloseHandleWrapper();
};

// @fnv 0x00aff090
void FUN_00aff090_cls::CloseHandleWrapper()
{
    CloseHandle(m_hHandle);
}

struct FUN_00aee580_wfx
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned short nSamplesPerSecLo;
    unsigned short nSamplesPerSecHi;
    unsigned short nAvgBytesPerSecLo;
    unsigned short nAvgBytesPerSecHi;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
struct FUN_00aee580_buf
{
    virtual long QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long AddRef() = 0;
    virtual unsigned long Release() = 0;
    virtual long GetCaps(void* pCaps) = 0;
    virtual long GetCurrentPosition(unsigned int* pdwPlay, unsigned int* pdwWrite) = 0;
    virtual long GetFormat(FUN_00aee580_wfx* pFormat, unsigned int dwSize, unsigned int* pdwWritten) = 0;
    virtual long GetVolume(long* plVolume) = 0;
    virtual long GetPan(long* plPan) = 0;
    virtual long GetFrequency(unsigned int* pdwFrequency) = 0;
    virtual long GetStatus(unsigned int* pdwStatus) = 0;
    virtual long Initialize(void* pDS, void* pDesc) = 0;
    virtual long Lock(unsigned int dwOffset, unsigned int dwBytes, void** ppv1, unsigned int* pdw1,
                                void** ppv2, unsigned int* pdw2, unsigned int dwFlags) = 0;
    virtual long Play(unsigned int dwReserved, unsigned int dwPriority, unsigned int dwFlags) = 0;
    virtual long SetCurrentPosition(unsigned int dwNewPosition) = 0;
    virtual long SetFormat(FUN_00aee580_wfx* pFormat) = 0;
    virtual long SetVolume(long lVolume) = 0;
    virtual long SetPan(long lPan) = 0;
    virtual long SetFrequency(unsigned int dwFrequency) = 0;
    virtual long Stop() = 0;
};
struct FUN_00aee580_stream
{
    int iState;
    unsigned int uiElapsedMilliseconds;
    unsigned int uiEnd;
    unsigned int uiWrap;
    unsigned int uiLength;
    unsigned int uiLastPos;
    char* pData18;
    char* pData1C;
    char* pData20;
};
struct FUN_00aee580_audio
{
    int pad[5];
    unsigned int ulFadeStartTimeTick;
    int pad18;
    unsigned int uiFlags;
};
struct FUN_00aee580_cls
{
    virtual void v00();
    virtual bool v04();
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
    virtual void v30(int iArg);
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    int unk04;
    unsigned int uiFlags08;
    int unk0c;
    unsigned int uiFlags10;
    int iSize;
    int pad18[(0x15c - 0x18) / 4];
    unsigned int m_uiState;
    int iVolume;
    int pad164[(0x198 - 0x164) / 4];
    void* p198;
    FUN_00aee580_buf* pBuffer;
    int pad1a0[(0x1dc - 0x1a0) / 4];
    unsigned int uiBufferSize;
    int pad1e0[(0x228 - 0x1e0) / 4];
    FUN_00aee580_stream* pStream;
    bool UpdateStreamBuffer(int iArg);
};


// @fnv 0x00aee580
bool FUN_00aee580_cls::UpdateStreamBuffer(int aiUnused)
{
    unsigned int uiBegin;
    unsigned int ulFadeStartTimeTick;
    FUN_00aee580_audio* pAudioTime;
    FUN_00aee580_audio* pAudio2Cur;
    FUN_00aee580_audio* pAudioMgr;
    bool bPlayingCur;
    int iNewPosition;
    unsigned int dwPos;
    FUN_00aee580_wfx kFormat;
    int iRate;
    int iError;
    bool bReleased;
    unsigned int uiPlayedMs;
    unsigned int uiElapsedValue;
    bool bComplete;
    bool bLoopAround;
    unsigned int uiSpill;
    unsigned int uiBytes;
    unsigned int uiWrite;
    bool bReset;
    unsigned int dwPlayCursor;
    unsigned int dwPlayStatus;

    if (pBuffer && p198)
    {
        pBuffer->GetStatus(&dwPlayStatus);
        bPlayingCur = (dwPlayStatus & 1) ? true : false;
        uiFlags10 = bPlayingCur ? (uiFlags10 | 0x20) : (uiFlags10 & ~0x20);
        if (v04() && (bool)((uiFlags08 & 0x4000000) || (uiFlags08 & 0x2000000) ? 1 : 0) && pStream)
        {
            dwPlayCursor = 0;
            uiWrite = 0;
            bReset = false;
            uiBytes = 0;
            pBuffer->GetCurrentPosition(&dwPlayCursor, &uiWrite);
            if (pStream->uiLastPos > dwPlayCursor)
            {
                bReset = true;
                uiBytes = uiBufferSize - pStream->uiLastPos;
            }
            else if (pStream->uiLastPos < dwPlayCursor)
                uiBytes = dwPlayCursor - pStream->uiLastPos;
            else
                return false;

            if (pStream->iState == 1)
            {
                if (uiBytes < pStream->uiEnd - pStream->uiElapsedMilliseconds)
                {
                    ((S_00af1c00_cls*)this)
                        ->FUN_00af1c00(pStream->uiElapsedMilliseconds, pStream->uiLastPos, uiBytes, pStream->pData18);
                    pStream->uiElapsedMilliseconds += uiBytes;
                }
                else if (uiBytes >= pStream->uiEnd - pStream->uiElapsedMilliseconds)
                {
                    uiBytes = pStream->uiEnd - pStream->uiElapsedMilliseconds;
                    ((S_00af1c00_cls*)this)
                        ->FUN_00af1c00(pStream->uiElapsedMilliseconds, pStream->uiLastPos, uiBytes, pStream->pData18);
                    pStream->uiElapsedMilliseconds = 0;
                    pStream->iState = 2;
                }
            }
            else if (pStream->iState == 2 && pStream->uiWrap)
            {
                bLoopAround = false;
                uiSpill = 0;
                if (uiBytes > pStream->uiWrap - pStream->uiElapsedMilliseconds)
                {
                    uiSpill = uiBytes - (pStream->uiWrap - pStream->uiElapsedMilliseconds);
                    uiBytes = pStream->uiWrap - pStream->uiElapsedMilliseconds;
                    bLoopAround = true;
                }
                ((S_00af1c00_cls*)this)
                    ->FUN_00af1c00(pStream->uiElapsedMilliseconds, pStream->uiLastPos, uiBytes, pStream->pData1C);
                pStream->uiElapsedMilliseconds = (pStream->uiElapsedMilliseconds + uiBytes) % pStream->uiWrap;
                if (bLoopAround)
                {
                    pStream->uiLastPos += uiBytes;
                    ((S_00af1c00_cls*)this)
                        ->FUN_00af1c00(pStream->uiElapsedMilliseconds, pStream->uiLastPos, uiSpill, pStream->pData1C);
                    pStream->uiElapsedMilliseconds = uiSpill;
                }
            }
            else if (pStream->iState == 4)
            {
                bComplete = false;
                if ((bool)(uiFlags08 & 0x2000000 ? 1 : 0))
                {
                    pStream->uiElapsedMilliseconds = 0;
                    bReset = true;
                    if (uiBufferSize > pStream->uiLength)
                    {
                        pBuffer->Stop();
                        pBuffer->SetCurrentPosition(0);
                        uiBytes = pStream->uiLength;
                        ((S_00af1c00_cls*)this)->FUN_00af1c00(0, 0, uiBytes, pStream->pData20);
                        ((S_00af1c00_cls*)this)->FUN_00af1c00(0, uiBytes, uiBufferSize - uiBytes, 0);
                        pStream->iState = 6;
                        pBuffer->Play(0, 0, 0);
                    }
                    else
                    {
                        pBuffer->Stop();
                        pBuffer->SetCurrentPosition(0);
                        uiBytes = uiBufferSize;
                        ((S_00af1c00_cls*)this)->FUN_00af1c00(0, 0, uiBytes, pStream->pData20);
                        pBuffer->Play(0, 0, 1);
                        pStream->iState = 5;
                        pStream->uiElapsedMilliseconds += uiBytes;
                    }
                    pStream->uiLastPos = 0;
                    return false;
                }
                else if ((bool)(uiFlags08 & 0x4000000 ? 1 : 0))
                {
                    pStream->iState = 3;
                    pBuffer->Stop();
                    pBuffer->Play(0, 0, 0);
                }
            }
            else if (pStream->iState == 5)
            {
                if (uiBytes < pStream->uiLength - pStream->uiElapsedMilliseconds)
                {
                    ((S_00af1c00_cls*)this)
                        ->FUN_00af1c00(pStream->uiElapsedMilliseconds, pStream->uiLastPos, uiBytes, pStream->pData20);
                    pStream->uiElapsedMilliseconds += uiBytes;
                }
                else if (uiBytes >= pStream->uiLength - pStream->uiElapsedMilliseconds)
                {
                    pBuffer->Stop();
                    uiBytes = pStream->uiLength - pStream->uiElapsedMilliseconds;
                    ((S_00af1c00_cls*)this)
                        ->FUN_00af1c00(pStream->uiElapsedMilliseconds, pStream->uiLastPos, uiBytes, pStream->pData20);
                    pBuffer->Play(0, 0, 0);
                    pStream->iState = 6;
                    uiFlags10 &= ~0x20;
                    uiFlags10 &= ~0x40;
                }
            }

            if (bReset)
                pStream->uiLastPos = 0;
            else
                pStream->uiLastPos = dwPlayCursor;
        }
        else if (v04() && (bool)(uiFlags08 & 0x1000000u ? 1 : 0))
        {
            if (!(bool)(uiFlags10 & 0x100000 ? 1 : 0) &&
                (bool)((pAudioMgr = (FUN_00aee580_audio*)DAT_011f6d98)->uiFlags & 1 ? 1 : 0))
            {
                uiFlags10 = 1 ? (uiFlags10 | 0x100000) : (uiFlags10 & ~0x100000);
                v34();
            }
            else if ((bool)(uiFlags10 & 0x100000 ? 1 : 0) &&
                     !(bool)((pAudio2Cur = (FUN_00aee580_audio*)DAT_011f6d98)->uiFlags & 1 ? 1 : 0))
            {
                uiFlags10 = 0 ? (uiFlags10 | 0x100000) : (uiFlags10 & ~0x100000);
                v30(0);
            }

            if (!(bool)(uiFlags10 & 0x100000 ? 1 : 0))
            {
                std::memset(&kFormat, 0, sizeof(kFormat));
                dwPos = 0;
                bReleased = false;
                pBuffer->GetCurrentPosition(&dwPos, 0);
                pBuffer->GetFormat(&kFormat, sizeof(kFormat), 0);
                iRate = *(unsigned int*)&kFormat.nAvgBytesPerSecLo / 1000.0;
                uiPlayedMs = dwPos / (*(unsigned int*)&kFormat.nAvgBytesPerSecLo / 1000.0);
                pAudioTime = (FUN_00aee580_audio*)DAT_011f6d98;
                ulFadeStartTimeTick = pAudioTime->ulFadeStartTimeTick;
                uiBegin = m_uiState;
                uiElapsedValue = ulFadeStartTimeTick - uiBegin;
                iError = 0;
                if (uiPlayedMs > uiElapsedValue)
                    iError = -(int)(uiPlayedMs - uiElapsedValue);
                else if (uiPlayedMs < uiElapsedValue)
                    iError = uiElapsedValue - uiPlayedMs;
                if (iError > 50 || -iError > 50)
                {
                    iNewPosition = iError * iRate + dwPos;
                    if (iNewPosition > iSize * iRate * DAT_010290f8)
                    {
                        iVolume = 100;
                        m_uiState = 0;
                        uiFlags08 &= ~0x1000000;
                        v38();
                        bReleased = true;
                    }
                    else if (iNewPosition > iSize * iRate)
                        iNewPosition = iSize * iRate;
                    else if (iNewPosition < 0)
                        iNewPosition = 0;
                    if (!bReleased)
                        pBuffer->SetCurrentPosition(iNewPosition);
                }
            }
        }
    }
    v40();
    return true;
}


struct FUN_00aea150_Class
{
    unsigned int unk00;
    unsigned int unk04;
    int unk08;

    void FUN_00aea150();
};

// @fnv 0x00aea150
void FUN_00aea150_Class::FUN_00aea150()
{
    unk08 = 0;
    unk00 = 0x927c0;
    unk04 = GetTickCount();
}

struct xFlags
{
    unsigned int u;
};

struct xMMCKINFO
{
    unsigned int ckid;
    unsigned int cksize;
    unsigned int fccType;
    unsigned int dwDataOffset;
    unsigned int dwFlags;
};

struct xMMIOINFO
{
    unsigned int dwFlags;
    unsigned int fccIOProc;
    void* pIOProc;
    unsigned int wErrorRet;
    void* htask;
    int cchBuffer;
    char* pchBuffer;
    char* pchNext;
    char* pchEndRead;
    char* pchEndWrite;
    int lBufOffset;
    int lDiskOffset;
    unsigned int adwInfo[3];
    unsigned int dwReserved1;
    unsigned int dwReserved2;
    void* hmmio;
};

struct xPCMWAVEFORMAT
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
};

struct xWAVEFORMATEX
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};

struct xSamplerChunk
{
    unsigned int adwData[11];
    unsigned int m_dwLoopStart;
    unsigned int dwLoopEnd;
    unsigned int adwRest[2];
};

struct xGuid
{
    unsigned int adw[4];
};

struct xAudioSettings
{
    unsigned int adwData[8];
    unsigned int dwHardware;
    unsigned int adwRest[15];
};

struct xAudio
{
    char _pad0[0x40];
    xAudioSettings m_kSettings;
};

struct xMemoryManager
{
};

extern "C" void*(* xmmioOpen)(char* pszFile, xMMIOINFO* pInfo, unsigned int dwFlags);
extern "C" unsigned int(* xmmioDescend)(void* h, xMMCKINFO* pck, const xMMCKINFO* pckParent,
                                                 unsigned int uFlags);
extern "C" unsigned int(* xmmioClose)(void* h, unsigned int uFlags);
extern "C" int(* xmmioRead)(void* h, char* pch, int cch);
extern "C" unsigned int(* xmmioAscend)(void* h, xMMCKINFO* pck, unsigned int uFlags);
extern "C" unsigned int(* xmmioGetInfo)(void* h, xMMIOINFO* pInfo, unsigned int uFlags);
extern "C" unsigned int(* xmmioAdvance)(void* h, xMMIOINFO* pInfo, unsigned int uFlags);
struct xAudioPtr
{
    xAudio* p;
};

struct xFmtPtr
{
    xWAVEFORMATEX* p;
};

// memset called as a __cdecl member: same pushes, but the pointer temp is numbered before the size temp
struct xMemsetTarget
{
    void* __cdecl FUN_00ec61c0(int, unsigned int);
};
struct xCharPtr
{
    char* p;
};

struct xGameSound
{
    void* m_vtbl;
    char _pad04[4];
    xFlags m_kFlags;
    char _pad0c[4];
    unsigned int m_uiFlags2;
    int m_iDuration;
    char _pad18[0x1c];
    unsigned short m_usFrequency;
    char m_acInputFilePath[0x40];
    char _pad76[0x14c - 0x76];
    unsigned int m_uiSize14c;
    char _pad150[0x15a - 0x150];
    unsigned short m_usFrequency2;
    char _pad15c[0x174 - 0x15c];
    unsigned int m_uiLoopStart;
    unsigned int m_uiLoopEnd;
    char _pad17c[0x1a4 - 0x17c];
    unsigned int m_uiDescSize;
    unsigned int m_uiDescFlags;
    unsigned int m_uiBufferBytes;
    char _pad1b0[4];
    xFmtPtr m_pDataFormat;
    xGuid m_kAlgorithm;
    xCharPtr m_pData;
    int m_iUnk1cc;
    char _pad1d0[0x1dc - 0x1d0];
    unsigned int m_uiValue5;
    bool FUN_00aeb270();
};

struct Marker
{
    char b;
};
struct FUN_00afdb20_Class
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    void FUN_00afdb20();
};
// Replaces m_08 and m_0c with FUN_00ec3bad applied to each of their current values.
// @fnv 0x00afdb20
void FUN_00afdb20_Class::FUN_00afdb20()
{
    Marker c0 = {};
    Marker f0 = c0;
    int* ptr0 = &m_08;
    *ptr0 = fnv::crt::byteswap_ulong(*ptr0);
    Marker e0 = {};
    Marker f1 = e0;
    int* ptr1 = &m_0c;
    *ptr1 = fnv::crt::byteswap_ulong(*ptr1);
}


struct FUN_009b7940_shell
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};

struct FUN_00afe9f0_Class : public FUN_009b7940_shell
{
    void* FUN_00afe9f0(unsigned int a);
};

// Sets the vtable pointer to DAT_010472d0 and calls FUN_006b3eb0 with a twice, returning this.
// @fnv 0x00afe9f0
void* FUN_00afe9f0_Class::FUN_00afe9f0(unsigned int a)
{
    int x;
    int y;
    *reinterpret_cast<const void**>(this) = &DAT_010472d0;
    FUN_006b3eb0(a, a);
    return this;
}

struct FUN_00ae8090_Node
{
    FUN_00ae8090_Node* next;
    FUN_00ae8090_Node* prev;
    void* value;
};

struct FUN_00ae8090_Allocator
{
    unsigned int count;
};

struct FUN_00ae8090_Locals
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
};

class FUN_00ae8090_Class
{
  public:
    FUN_00ae8090_Node* head;
    FUN_00ae8090_Node* tail;
    FUN_00ae8090_Allocator allocator;

    void* FUN_00ae8090(FUN_00ae8090_Node** position);
};

// Removes the node at the given position from the linked list, updates the position pointer, and returns the node's value.
// @fnv 0x00ae8090
void* FUN_00ae8090_Class::FUN_00ae8090(FUN_00ae8090_Node** position)
{
    int m[13];

    FUN_00ae8090_Node* node = *position;
    if (node == head)
    {
        *position = node->next;
        return reinterpret_cast<::SndStack70 *>(this)->FUN_00ae7f90();
    }
    if (node == tail)
    {
        *position = 0;
        return reinterpret_cast<::FUN_00ae8010_cls *>(this)->PopFront();
    }

    FUN_00ae8090_Node* prevNode = node->prev;
    FUN_00ae8090_Node* pNext = node->next;
    *position = pNext;

    if (prevNode)
        prevNode->next = pNext;
    if (pNext)
        pNext->prev = prevNode;

    void* value = node->value;
    node->value = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(allocator))->FUN_0045cee0(node);
    allocator.count = allocator.count - 1;
    return value;
}

struct ObjC
{
    int m_00;
    int m_04;
    unsigned int m_08;
    int unk0c;
    int unk10;
    int unk14;
    char* m_18;
    char* m_1c;
};
struct AED080_Cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual bool v0c();
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
    virtual void v3c(float a);
    virtual void v16();
    virtual void v44(int a);
    int unk004;
    int m_08;
    int unk00c;
    int m_10;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    float m_24;
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
    int m_14c;
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
    IDSBufStub* m_198;
    IDSBufStub* m_19c;
    IDSBufStub* m_1a0;
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
    unsigned int m_1dc;
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
    ObjC* m_228;
    bool FUN_00aed080(bool p);
};
// Calls Play(0, 0, p) on m_19c and m_1a0, first forcing p and adjusting m_19c's position and m_228 under some m_08 flag bits; then clears the callback.
// @fnv 0x00aed080
bool AED080_Cls::FUN_00aed080(bool p)

{
    int result = (int)0x80004005;
    bool doneFlag = false;
    int diff;
    if (this->m_19c != 0 && this->m_198 != 0)
    {
        if ((unsigned char)(((this->m_08 & 0x10) != 0) ? 1 : 0))
        {
            p = true;
            int n = this->m_14c;
            this->m_19c->SetCurrentPosition((unsigned int)std::rand() % (unsigned int)(n - 1));
        }
        else
        {
            if ((unsigned char)(((this->m_08 & 0x10) || (this->m_08 & 0x4000000) || (this->m_08 & 0x2000000)) ? 1 : 0))
            {
                if (!(this->v0c() && this->m_228 != 0 && this->m_228->m_00 == 5))
                {
                    p = true;
                    if ((unsigned char)(((this->m_08 & 0x4000000) || (this->m_08 & 0x2000000)) ? 1 : 0))
                    {
                        if (this->m_228 != 0 && this->m_228->m_18 != 0 && this->m_228->m_00 != 1 &&
                            this->m_228->m_00 != 2)
                        {
                            this->m_19c->SetCurrentPosition(0);
                            if (this->m_228->m_08 > this->m_1dc)
                            {
                                reinterpret_cast<::S_00af1c00_cls *>((this))->FUN_00af1c00(0, 0, this->m_1dc, this->m_228->m_18);
                                this->m_228->m_04 = this->m_1dc;
                                this->m_228->m_00 = 1;
                            }
                            else
                            {
                                diff = this->m_1dc - this->m_228->m_08;
                                reinterpret_cast<::S_00af1c00_cls *>((this))->FUN_00af1c00(0, 0, this->m_228->m_08, this->m_228->m_18);
                                reinterpret_cast<::S_00af1c00_cls *>((this))->FUN_00af1c00(0, this->m_228->m_08, diff, this->m_228->m_1c);
                                this->m_228->m_04 = this->m_228->m_08 + diff;
                                this->m_228->m_00 = 2;
                            }
                        }
                    }
                }
            }
        }
    merge:
        if (p)
        {
            result = this->m_19c->Play(0, 0, 1);
            if (this->m_1a0 != 0)
                this->m_1a0->Play(0, 0, 1);
        }
        else
        {
            result = this->m_19c->Play(0, 0, 0);
            if (this->m_1a0 != 0)
                this->m_1a0->Play(0, 0, 0);
        }
        ::ClearCallback((char *)(this));
    }
    if (result >= 0)
    {
        this->m_10 |= 0x20;
        this->m_10 &= ~0x40;
    }
    this->v3c(this->m_24);
    if (doneFlag)
        this->v44(0);
    return result >= 0;
}

// DirectSound buffer copy and auxiliary stream-state duplication.

typedef unsigned int U32;

typedef unsigned short U16;

struct GuidValue
{
    U32 data0;
    U32 data1;
    U32 data2;
    U32 data3;
};

struct WaveFormat
{
    U16 tag;
    U16 channels;
    U32 m_uiSamplesPerSecond;
    U32 averageBytes;
    U16 blockAlign;
    U16 m_usBitsPerSample;    U16 cbSize;
};

struct AudioInterface
{

    virtual long QueryInterface(const void*, void**) = 0;

    virtual long AddRef() = 0;

    virtual long Release() = 0;

    virtual long CreateBuffer(void*, void**, void*) = 0;

    virtual long v10() = 0;

    virtual long v14(WaveFormat*, U32, U32*) = 0;

    virtual long v18() = 0;

    virtual long v1c() = 0;

    virtual long v20() = 0;

    virtual long v24() = 0;

    virtual long v28() = 0;

    virtual long Lock(U32, U32, void**, U32*, void**, U32*, U32) = 0;

    virtual long v30() = 0;

    virtual long v34() = 0;

    virtual long v38() = 0;

    virtual long v3c() = 0;

    virtual long v40() = 0;

    virtual long SetValue(float, U32) = 0;

    virtual long v48() = 0;

    virtual long Unlock(void*, U32, void*, U32) = 0;
};

struct CopyState
{
    U32 idle;
    U32 active;
    U32 byteCount;
    U32 segmentSize;
    U32 thirdSize;
    U32 index;
    void* bytes;
    void* segments;
    void* third;
};

struct AudioConfig
{

    U32 m_00;

    U32 m_04;

    U32 m_08;

    U32 m_0c;

    U32 m_10;

    U32 m_14;

    U32 m_18;

    U32 m_1c;

    U32 m_20;

    U32 m_24;

    U32 m_28;

    U32 m_2c;

    U32 m_30;

    U32 m_34;

    U32 m_38;

    U32 m_3c;

    U32 m_40;

    U32 m_44;

    U32 m_48;

    U32 m_4c;

    U32 m_50;

    U32 m_54;

    U32 m_58;

    U32 m_5c;
};

struct AudioMemory
{
};

struct AudioOptionsSource
{
    U32 unk00;
    U32 unk04;
    U32 unk08;
    U32 unk0c;
    U32 unk10;
    U32 unk14;
    U32 unk18;
    U32 unk1c;
    U32 unk20;
    U32 unk24;
    U32 unk28;
    U32 unk2c;
    U32 unk30;
    U32 unk34;
    U32 unk38;
    U32 unk3c;
    AudioConfig options;
};





extern const char DAT_010a4168[], DAT_010a4130[], DAT_010a40f0[], DAT_010a40b0[], DAT_010a4074[], DAT_010a4038[];

extern const char DAT_010a3ffc[], DAT_010a3fc0[], DAT_010a3f84[], DAT_010a3f48[], DAT_010a3f0c[], DAT_010a3ed0[];


struct AF1d80;

class AudioBuffer
{

  public:
    virtual void v00() = 0;

    virtual void v04() = 0;

    virtual void v08() = 0;

    virtual void v0c() = 0;

    virtual void v10() = 0;

    virtual void v14() = 0;

    virtual void v18() = 0;

    virtual void v1c() = 0;

    virtual void v20() = 0;

    virtual void v24() = 0;

    virtual void OnCopied() = 0;

    unsigned int unk_004;

    unsigned int m_flags;

    unsigned int unk_00c;

    unsigned int m_uiContentCount;

    int m_playLength;

    unsigned int unk_018;

    unsigned int unk_01c;

    unsigned int unk_020;

    unsigned int unk_024;

    unsigned int unk_028;

    unsigned int unk_02c;

    unsigned int unk_030;

    unsigned short m_sampleRate;
    char m_fileName[0x112];

    unsigned int m_copy148;

    unsigned int m_copy14c;

    unsigned int unk_150;

    unsigned int unk_154;

    unsigned short m_unused158;
    unsigned short m_sampleCount;

    unsigned int unk_15c;

    unsigned int unk_160;

    unsigned int unk_164;

    unsigned int unk_168;

    unsigned int unk_16c;

    unsigned int unk_170;

    unsigned int unk_174;

    unsigned int unk_178;

    unsigned int unk_17c;

    unsigned int unk_180;

    unsigned int unk_184;

    unsigned int unk_188;

    unsigned int unk_18c;

    unsigned int unk_190;

    unsigned int unk_194;

    AudioInterface* m_device;

    AudioInterface* m_buffer;

    unsigned int m_ctrl1a0;

    unsigned int m_descSize;

    unsigned int m_descFlags;

    unsigned int m_bufferBytes;

    unsigned int unk_1b0;

    WaveFormat* m_eVertexFormat;

    GuidValue m_algo;

    void* m_oldBuffer;

    AudioInterface* m_duplicate;

    unsigned int m_ctrl1d0;

    AudioInterface* m_iBufferSize;

    unsigned int m_ctrl1d8;

    unsigned int m_totalBytes;

    unsigned int unk_1e0;

    unsigned int unk_1e4;

    unsigned int unk_1e8;

    unsigned int unk_1ec;

    unsigned int unk_1f0;

    unsigned int unk_1f4;

    unsigned int unk_1f8;

    unsigned int unk_1fc;

    unsigned int unk_200;

    unsigned int unk_204;

    unsigned int unk_208;

    unsigned int unk_20c;

    unsigned int unk_210;

    unsigned int unk_214;

    unsigned int unk_218;

    unsigned int unk_21c;

    unsigned int unk_220;

    unsigned int unk_224;

    CopyState* m_copyState;

    AF1d80* m_stream;

    __forceinline bool IsBuffered()
    {
        return (m_flags & 0x10) || (m_flags & 0x4000000) || (m_flags & 0x2000000);
    }
    __forceinline bool Any()
    {
        return (m_flags & 0x4000000) || (m_flags & 0x2000000);
    }
    void FUN_00af0630(AudioBuffer*, bool);
    bool Setup(bool& bHalf, unsigned int& nSize);
public:
    bool FUN_00aebff0();
};
// Opens a WAV file via RIFF mmio, reads fmt and data chunks, allocates a buffer, copies audio data, and optionally reads loop points from an smpl chunk.
// @fnv 0x00aeb270
bool xGameSound::FUN_00aeb270()
{
    unsigned int qfTOqo;
    xPCMWAVEFORMAT qsSDDgz;
    unsigned int qrEZrs;
    unsigned int qpqRa;
    char* qSVM;
    void* qdqWL;
    xMMCKINFO qpTd;
    unsigned int qvyWyw;
    xMMIOINFO qHXYKT;
    xMMCKINFO qbGYp;
    unsigned int qnuVZg;
    int qSuoDt;
    xMMIOINFO qzzQr;
    unsigned int qkbsJ;
    xSamplerChunk qhxpxJd;
    void* qahtre;
    xAudioSettings qjXCGmG;
    m_uiFlags2 |= 0x1000;
    if (!reinterpret_cast<::FUN_00af1ba0_Class *>(this)->EnsureAudio())
        return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
    if ((xFlags(m_kFlags).u & 0x1000) || (xFlags(m_kFlags).u & 0x2000) || (xFlags(m_kFlags).u & 4) ||
        (xFlags(m_kFlags).u & 0x400000) || (xFlags(m_kFlags).u & 0x100000) || (xFlags(m_kFlags).u & 0x800))
    {
        if (reinterpret_cast<::AudioBuffer *>(this)->FUN_00aebff0())
            return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(true);
    }
    qSVM = std::strstr(m_acInputFilePath, ".mp3");
    if (!qSVM)
        qSVM = std::strstr(m_acInputFilePath, ".ogg");
    if (qSVM)
    {
        qSVM[1] = 'w';
        qSVM[2] = 'a';
        qSVM[3] = 'v';
    }
    m_iUnk1cc = 0;
    qSuoDt = 0;
    std::memset(&qzzQr, 0, 0x48);
    qzzQr.fccIOProc = 0x564157;
    qzzQr.pIOProc = ((long (&)(char *, unsigned int, long, long))::AudioFileOp);
    qdqWL = xmmioOpen(m_acInputFilePath, &qzzQr, 0x10000);
    if (!qdqWL)
    {
        ::FUN_005b5e40();
        if ((xFlags(m_kFlags).u & 0x400000) || (xFlags(m_kFlags).u & 0x100000))
        {
            fnv::crt::strcpy_s(m_acInputFilePath, 0x40, "Data\\Sound\\FX\\UI\\RADIO\\TEMP_radioassetmissing.wav");
            reinterpret_cast<::BSGameSound *>(this)->LoadFromFilename(1);
            qdqWL = xmmioOpen(m_acInputFilePath, &qzzQr, 0x10000);
            if (!qdqWL)
                return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
        }
        else if (xFlags(m_kFlags).u & 4)
        {
            fnv::crt::strcpy_s(m_acInputFilePath, 0x40, "Data\\Sound\\FX\\TEMP_Missing_Voice_Asset.wav");
            reinterpret_cast<::BSGameSound *>(this)->LoadFromFilename(1);
            qdqWL = xmmioOpen(m_acInputFilePath, &qzzQr, 0x10000);
            if (!qdqWL)
                return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
        }
        else if ((unsigned char)(((m_kFlags.u & 0x10) || (m_kFlags.u & 0x4000000) || (m_kFlags.u & 0x2000000)) ? 1 : 0))
        {
            m_kFlags.u &= ~0x2000000;
            m_kFlags.u &= ~0x4000000;
            fnv::crt::strcpy_s(m_acInputFilePath, 0x40, "Data\\Sound\\FX\\silent_lp.wav");
            reinterpret_cast<::BSGameSound *>(this)->LoadFromFilename(1);
            qdqWL = xmmioOpen(m_acInputFilePath, &qzzQr, 0x10000);
            if (!qdqWL)
                return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
        }
        else
        {
            return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
        }
    }
    qpqRa = xmmioDescend(qdqWL, &qbGYp, 0, 0);
    if (qpqRa == 0x109)
    {
        xmmioClose(qdqWL, 0);
        return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
    }
    qpTd.ckid = 0x20746d66;
    qpqRa = xmmioDescend(qdqWL, &qpTd, &qbGYp, 0x10);
    if (qpqRa == 0x109)
    {
        xmmioClose(qdqWL, 0);
        return false;
    }
    if (qpTd.cksize < 0x10)
    {
        xmmioClose(qdqWL, 0);
        return false;
    }
    xmmioRead(qdqWL, (char*)&qsSDDgz, 0x10);
    if (qsSDDgz.wFormatTag != 1)
    {
        xmmioClose(qdqWL, 0);
        return false;
    }
    xmmioAscend(qdqWL, &qpTd, 0);
    qpTd.ckid = 0x61746164;
    xmmioDescend(qdqWL, &qpTd, &qbGYp, 0x10);
    m_uiValue5 = qpTd.cksize;
    m_uiSize14c = qpTd.cksize;
    m_uiDescSize = 0x24;
    if (qsSDDgz.nChannels > 1 && (!(xFlags(m_kFlags).u & 1) || (xFlags(m_kFlags).u & 2)))
    {
        m_kFlags.u = xFlags(m_kFlags).u | 1;
        m_kFlags.u = xFlags(m_kFlags).u & ~2;
        if (!(xFlags(m_kFlags).u & 0x8000000))
            ::FUN_005b5e40();
    }
    if (xFlags(m_kFlags).u & 1)
    {
        m_uiDescFlags = 0x40;
        m_kAlgorithm = (*reinterpret_cast<::xGuid *>(&::DAT_01093f04));
    }
    else
    {
        m_uiDescFlags = 0x30010;
        qjXCGmG = xAudioPtr((*reinterpret_cast<::xAudioPtr *>(&::DAT_011f6d98))).p->m_kSettings;
        if (qjXCGmG.dwHardware)
            m_kAlgorithm = (*reinterpret_cast<::xGuid *>(&::DAT_01100fe4));
        else
            m_kAlgorithm = (*reinterpret_cast<::xGuid *>(&::DAT_01093f04));
    }
    m_uiDescFlags |= 0x2a0;
    m_uiBufferBytes = m_uiValue5;
    std::memmove(xFmtPtr(m_pDataFormat).p, &qsSDDgz, 0x10);
    m_pDataFormat.p->cbSize = 0;
    qnuVZg = 0;
    qvyWyw = 0;
    m_usFrequency = m_pDataFormat.p->nSamplesPerSec;
    m_usFrequency2 = m_usFrequency;
    qnuVZg = m_usFrequency / 1000;
    qvyWyw = m_pDataFormat.p->wBitsPerSample / 8;
    m_iDuration = m_uiValue5 / qvyWyw / qnuVZg;
    qfTOqo = 0;
    qrEZrs = 0;
    if (m_iDuration <= 150)
    {
        if (!(unsigned char)(((m_kFlags.u & 0x10) || (m_kFlags.u & 0x4000000) || (m_kFlags.u & 0x2000000)) ? 1 : 0))
        {
            m_uiDescFlags &= ~0x200;
            qfTOqo = (250 - m_iDuration) * qvyWyw * qnuVZg;
        }
    }
    if (!(unsigned char)(((m_kFlags.u & 0x10) || (m_kFlags.u & 0x4000000) || (m_kFlags.u & 0x2000000)) ? 1 : 0))
    {
        qfTOqo += (unsigned int)((((m_uiValue5 * 0.2f) > (qvyWyw * 500 * qnuVZg))
                                      ? (m_uiValue5 * 0.2f)
                                      : (qvyWyw * 500 * qnuVZg)) < (qvyWyw * 1000 * qnuVZg)
                                     ? (((m_uiValue5 * 0.2f) > (qvyWyw * 500 * qnuVZg)) ? (m_uiValue5 * 0.2f)
                                                                                        : (qvyWyw * 500 * qnuVZg))
                                     : (qvyWyw * 1000 * qnuVZg));
    }
    {
        qahtre = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::xMemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(static_cast<const unsigned int&>(qpTd.cksize + qfTOqo + qrEZrs));
        m_pData.p = (char*)qahtre;
    }
    if (!m_pData.p)
    {
        xmmioClose(qdqWL, 0);
        return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
    }
    std::memset(xCharPtr(m_pData).p, 0, qpTd.cksize + qfTOqo + qrEZrs);
    xmmioGetInfo(qdqWL, &qHXYKT, 0);
    for (qkbsJ = qrEZrs; qkbsJ < qpTd.cksize; qkbsJ++)
    {
        if (qHXYKT.pchNext == qHXYKT.pchEndRead && xmmioAdvance(qdqWL, &qHXYKT, 0))
        {
            xmmioClose(qdqWL, 0);
            return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
        }
        m_pData.p[qkbsJ] = *qHXYKT.pchNext;
        qHXYKT.pchNext++;
    }
    m_uiValue5 += qfTOqo + qrEZrs;
    m_uiBufferBytes = m_uiValue5;
    m_uiSize14c = m_uiBufferBytes;
    m_iDuration = m_uiValue5 / qvyWyw / qnuVZg;
    if ((m_kFlags.u & 0x2000000) || (m_kFlags.u & 0x4000000))
    {
        xmmioAscend(qdqWL, &qpTd, 0);
        qpTd.ckid = 0x6c706d73;
        qpqRa = xmmioDescend(qdqWL, &qpTd, &qbGYp, 0x10);
        if (qpqRa == 0x109)
        {
            qpTd.ckid = 0x20746d66;
            xmmioClose(qdqWL, 0);
            ::FUN_005b5e40(
                );
            return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(false);
        }
        else
        {
            xmmioRead(qdqWL, (char*)&qhxpxJd, 0x3c);
            m_uiLoopStart = qhxpxJd.m_dwLoopStart;
            m_uiLoopEnd = qhxpxJd.dwLoopEnd;
        }
    }
    xmmioClose(qdqWL, 0);
    return reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(true);
}

// Copies audio data and state from a previous AudioBuffer, creates a new device buffer, and optionally triggers OnCopied.
// @fnv 0x00af0630
void AudioBuffer::FUN_00af0630(AudioBuffer* apSource, bool notify)
{
    AudioBuffer* source0;
    U32 dst2Bytes3;
    void* dst44_2;
    int rateInKHz_;
    int tempB;
    void* dst32;
    U32 temp3;
    void* src7;
    U32 src2Bytes3;
    void* src3;
    int savedBytes2;
    int slotX;
    float ratio_2;
    int result5;
    U32 src1Bytes2;
    char message11[256];
    {
        AudioConfig options;
        {
            void* allocatedThird6;
            void* allocatedSegments5;
            void* temp3c;
            void* allocatedCopy4;
            {
                U32 local78;
                const void* local69;
                void* local49;
                U32 local40;
                const void* copySrc2_2;
                void* local37;
                U32 local35;
                const void* copySrc_;
                void* copyDst_;
                U32 local14;
                U32 valueX;
                U32 allocSize7;
                U32 flags2_2;
                U32 copySize_2;
                const void* copySrc7;
                void* copyDst7;
                AudioOptionsSource* audioNodeVal;
                U32 flags_2;
                U32 flags56;
                U32 flags40;
                U32 flags35;
                U32 flags15;
                U32 copyValue3;
                source0 = apSource;
                if (source0->m_oldBuffer != 0)
                    source0->OnCopied();
                reinterpret_cast<::BSGameSound *>(this)->Copy((::BSGameSound *)(apSource), true);
                m_ctrl1a0 = 0;
                m_ctrl1d0 = 0;
                m_ctrl1d8 = 0;
                {
                    copyValue3 = apSource->m_copy148;
                    m_copy148 = copyValue3;
                }
                m_totalBytes = source0->m_totalBytes;
                m_copy14c = m_totalBytes;
                m_sampleRate = source0->m_sampleRate;
                m_sampleCount = source0->m_sampleCount;
                m_buffer = 0;
                m_iBufferSize = 0;
                m_device = source0->m_device;
                if (source0 == 0 || source0->m_buffer == 0)
                    return;
                flags15 = m_flags;
                if ((flags15 & 1) == 0)
                {
                    flags35 = m_flags;
                    if ((flags35 & 2) == 0)
                        m_flags |= 1;
                }
                dst44_2 = 0;
                dst32 = 0;
                temp3 = 0;
                dst2Bytes3 = 0;
                src7 = 0;
                src3 = 0;
                src1Bytes2 = 0;
                src2Bytes3 = 0;
                m_descSize = 36;
                m_bufferBytes = source0->m_bufferBytes;
                source0->m_buffer->v14(m_eVertexFormat, 18, &temp3);
                flags40 = m_flags;
                if ((flags40 & 1) != 0 || (m_eVertexFormat && m_eVertexFormat->channels > 1))
                    m_descFlags = 0x40;
                else
                {
                    flags56 = m_flags;
                    if ((flags56 & 2) != 0)
                        m_descFlags = 0x30010;
                }
                m_descFlags |= 0x2a0;
                tempB = (int)m_eVertexFormat->m_usBitsPerSample / 8;
                slotX = 0;
                savedBytes2 = 0;
                rateInKHz_ = (int)m_sampleRate / 1000;
                if (m_playLength <= 150)
                {
                    m_descFlags &= ~0x200;
                    if (!((unsigned char)(((m_flags & 0x10) || (m_flags & 0x4000000) || (m_flags & 0x2000000)) ? 1
                                                                                                               : 0)))
                        slotX = (250 - m_playLength) * tempB * rateInKHz_;
                }
                m_totalBytes += slotX + savedBytes2;
                m_bufferBytes = m_totalBytes;
                m_copy14c = m_bufferBytes;
                m_playLength = m_totalBytes / tempB / rateInKHz_;
                flags_2 = m_flags;
                if ((flags_2 & 1) != 0)
                    m_algo = (*reinterpret_cast<::GuidValue *>(&::DAT_01093f04));
                else
                {
                    audioNodeVal = (AudioOptionsSource*)DAT_011f6d98;
                    options = audioNodeVal->options;
                    if (options.m_20 != 0)
                        m_algo = DAT_01100fe4;
                    else
                        m_algo = (*reinterpret_cast<::GuidValue *>(&::DAT_01093f04));
                }
                ratio_2 = (float)m_sampleCount / (float)m_sampleRate;
                m_sampleRate = (U16)m_eVertexFormat->m_uiSamplesPerSecond;
                m_sampleCount = (U16)((float)m_sampleRate * ratio_2);
                m_playLength =
                    m_totalBytes / ((int)m_eVertexFormat->m_usBitsPerSample / 8) / ((int)m_sampleRate / 1000);
                result5 = m_device->CreateBuffer(&m_descSize, (void**)&m_duplicate, 0);
                if (result5 < 0)
                {

                    switch ((unsigned int)result5)
                    {
                    case 0x8878000a:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a4168);
                        break;
                    case 0x88780064:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a4130);
                        break;
                    case 0x887800b4:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a40f0);
                        break;
                    case 0x8878001e:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a40b0);
                        break;
                    case 0x887800be:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a4074);
                        break;
                    case 0x88780032:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a4038);
                        break;
                    case 0x80070057:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a3ffc);
                        break;
                    case 0x80040110:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a3fc0);
                        break;
                    case 0x8007000e:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a3f84);
                        break;
                    case 0x887800aa:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a3f48);
                        break;
                    case 0x80004001:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a3f0c);
                        break;
                    default:
                        fnv::crt::strcpy_s(message11, 255, DAT_010a3ed0);
                        break;
                    }
                    ::FUN_005b5e40();
                    return;
                }
                if (m_duplicate->Lock(0, 0, &dst44_2, &temp3, &dst32, &dst2Bytes3, 2) < 0)
                    return;
                if (source0->m_buffer->Lock(0, 0, &src7, &src1Bytes2, &src3, &src2Bytes3, 2) >= 0)
                {
                    copySize_2 = m_bufferBytes;
                    copySrc7 = src7;
                    copyDst7 = dst44_2;
                    std::memmove(copyDst7, copySrc7, copySize_2);
                    source0->m_buffer->Unlock(src7, src1Bytes2, src3, src2Bytes3);
                }
                m_duplicate->Unlock(dst44_2, temp3, dst32, dst2Bytes3);
                m_duplicate->QueryInterface(&(*reinterpret_cast<::GuidValue *>((void *)&::g_IID_SndBuffer8)), (void**)&m_buffer);
                if (m_buffer != 0)
                {
                    flags2_2 = m_flags;
                    if ((flags2_2 & 2) != 0)
                    {
                        m_buffer->QueryInterface(&(*reinterpret_cast<::GuidValue *>((void *)&::g_IID_Snd3DBuffer)), (void**)&m_iBufferSize);
                        if (m_iBufferSize != 0)
                            m_iBufferSize->SetValue(::g_fSndMinDistance, 1);
                    }
                }
                if (((unsigned char)(((source0->m_flags & 0x4000000) || (source0->m_flags & 0x2000000)) ? 1 : 0)) &&
                    source0->m_copyState != 0)
                {
                    allocatedCopy4 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::AudioMemory *>(&::g_memoryManager))))->FUN_00aa3e40(36);
                    m_copyState = (CopyState*)allocatedCopy4;
                    m_copyState->byteCount = source0->m_copyState->byteCount;
                    m_copyState->thirdSize = source0->m_copyState->thirdSize;
                    m_copyState->segmentSize = source0->m_copyState->segmentSize;
                    m_copyState->index = 0;
                    m_copyState->idle = 0;
                    m_copyState->active = 0;
                    allocSize7 = m_copyState->byteCount;
                    temp3c = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::AudioMemory *>(&::g_memoryManager))))->FUN_00aa3e40(allocSize7);
                    m_copyState->bytes = temp3c;
                    valueX = m_copyState->segmentSize;
                    allocatedSegments5 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::AudioMemory *>(&::g_memoryManager))))->FUN_00aa3e40(valueX);
                    m_copyState->segments = allocatedSegments5;
                    local14 = m_copyState->thirdSize;
                    allocatedThird6 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::AudioMemory *>(&::g_memoryManager))))->FUN_00aa3e40(local14);
                    m_copyState->third = allocatedThird6;
                    {
                        local35 = m_copyState->byteCount;
                        copySrc_ = source0->m_copyState->bytes;
                        copyDst_ = m_copyState->bytes;
                        std::memmove(copyDst_, copySrc_, local35);
                    }
                    {
                        local40 = m_copyState->segmentSize;
                        copySrc2_2 = source0->m_copyState->segments;
                        local37 = m_copyState->segments;
                        std::memmove(local37, copySrc2_2, local40);
                    }
                    {
                        local78 = m_copyState->thirdSize;
                        local69 = source0->m_copyState->third;
                        local49 = m_copyState->third;
                        std::memmove(local49, local69, local78);
                    }
                }
                m_uiContentCount = 0;
                reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(true);
                if (notify)
                    OnCopied();
            }
        }
    }
}

namespace fnv_00afdda0 {
struct MemoryAllocator
{
};
struct PathList
{
    void FUN_00afdda0(const char* path);
};
// Copies path into a new allocated buffer, appending a backslash if it lacks one, and passes the buffer to FUN_007cb2e0.
// @fnv 0x00afdda0
void PathList::FUN_00afdda0(const char* path)
{
    if (path)
    {
        size_t length = std::strlen(path);
        bool appendSlash = path[length - 1] != 0x5c;
        size_t allocationSize = std::strlen(path) + appendSlash + 1;
        char* buf = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00afdda0::MemoryAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(allocationSize);
        char* copyBuffer = buf;
        char* buffer = copyBuffer;
        fnv::crt::strcpy_s(buffer, allocationSize, path);
        if (appendSlash)
        {
            copyBuffer[length] = 0x5c;
            copyBuffer[length + 1] = 0;
        }
        reinterpret_cast<::FUN_00438690 *>(this)->FUN_007cb2e0((unsigned int *)&(copyBuffer));
        {
            int ReportDiagnostic, unused1, unused2;
        }
    }
}
}  // namespace fnv_00afdda0

struct FUN_00aea020_cls
{
    int unk00;
    FUN_00aea020_cls();
    ~FUN_00aea020_cls();
};


// Constructs a function-local static object once and stores its address in DAT_011f6d98.
// @fnv 0x00aea020
void __cdecl FUN_00aea020()
{
    static FUN_00aea020_cls obj;
    DAT_011f6d98 = (BSAudio*)&obj;
}

struct FUN_00af33f0
{
    void* vtbl;
    int x;
    FUN_00af33f0();
    ~FUN_00af33f0();
};

// Returns a pointer to a static instance of FUN_00af33f0, creating it on first call.
// @fnv 0x00af3020
void* __cdecl FUN_00af3020()
{
    static FUN_00af33f0 instance;
    return &instance;
}

namespace Worker114 {
struct FUN_00ae9360_Base
{
    virtual ~FUN_00ae9360_Base();
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
    unsigned short flags034;
    char fileName[260];
    unsigned short unk13a;
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
    FUN_00ae9360_Base();
};
}
struct Allocate114
{
};
struct FUN_00aeac20 : Worker114::FUN_00ae9360_Base
{
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    void* unk1b4;
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
    unsigned short unk20c;
    unsigned short unk20e;
    unsigned short unk210;
    unsigned short unk212;
    unsigned short unk214;
    unsigned short unk216;
    NiPoint3 position218;
    unsigned char flag224;
    unsigned int unk228, unk22c;
    FUN_00aeac20(const char* name);
    virtual ~FUN_00aeac20();
};
// Initializes the object by copying name into fileName, zeroing fields, allocating 0x12 bytes, and setting default values for unk20e through unk214.
// @fnv 0x00aeac20
FUN_00aeac20::FUN_00aeac20(const char* name)
{
    if (name)
    {
        unsigned int length = std::strlen(name) + 1;
        fnv::crt::strcpy_s(fileName, length, name);
    }
    else
        std::memset(fileName, 0, 260);
    unk1dc = 0;
    unk19c = 0;
    unk1a0 = 0;
    unk1d4 = 0;
    unk1d8 = 0;
    unk1d0 = 0;
    unk198 = 0;
    unk204 = 0;
    unk208 = 0;
    flag224 = 0;
    position218 = ::NiPoint3::ZERO;
    std::memset(&unk1a4, 0, 0x24);
    void* allocation = reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<Allocate114*>(&g_memoryManager)))->FUN_00aa3e40(0x12);
    unk1b4 = allocation;
    unk1c8 = 0;
    unk20c = 0;
    unk20e = 600;
    unk210 = 1400;
    unk212 = 2600;
    unk214 = 5000;
    unk228 = 0;
    unk22c = 0;
}

// @fnv 0x00af4070
void __cdecl FUN_00af4070(char* result, const char* source)
{
    if (::g_uiMatchFlags & 8)
    {
        while (*source && *source == ' ')
            ++source;
    }
    if (::g_uiMatchFlags & 6)
    {
        char _Drive[3];
        char _Dir[256];
        char _Fname[256];
        char _Ext[256];
        fnv::crt::splitpath_s(source, _Drive, 3, _Dir, 256, _Fname, 256, _Ext, 256);
        if (!(::g_uiMatchFlags & 2))
        {
            _Drive[0] = 0;
            _Dir[0] = 0;
        }
        if (!(::g_uiMatchFlags & 4))
            _Ext[0] = 0;
        fnv::crt::makepath_s(result, 260, _Drive, _Dir, _Fname, _Ext);
    }
    else
        fnv::crt::strcpy_s(result, 260, source);
}


struct SystemFileWriter : Win32ReadFile
{
    int FUN_00afede0(void* buf, DWORD len, int unused, unsigned __int64* outRead);
};
// Writes len bytes from buf to hFile via WriteFile, mapping GetLastError codes to 0-4 and storing bytes written in outRead on success.
// @fnv 0x00afede0
int SystemFileWriter::FUN_00afede0(void* buf, DWORD len, int unused, unsigned __int64* outRead)
{
    int rc = 0;
    DWORD nRead = 0;
    DWORD status = 0;
    DWORD ok = 0;
    DWORD n;
    if (bInvalid)
    {
        rc = 4;
    }
    else
    {
        n = len;
        status = WriteFile(hFile, buf, n, &nRead, 0);
        if (status <= 0)
        {
            ok = GetLastError();
            int code;
            switch (ok)
            {
            case 0:
                code = 0;
                break;
            case 2:
                code = 1;
                break;
            case 3:
                code = 2;
                break;
            case 0x13:
                code = 3;
                break;
            default:
                code = 4;
                break;
            }
            rc = code;
        }
        else
        {
            rc = 0;
            *outRead = nRead;
        }
    }
    return rc;
}

extern "C" long __cdecl _fseek(void* stream, long offset, int whence);

long __cdecl FUN_00aea180(void* stream, long offset, int whence, int pad);

extern "C" long __cdecl _fseek(void* stream, long offset, int whence);

long __cdecl FUN_00af1cf0(void* stream, long offset, int whence, int pad);

int __cdecl CloseAndDeleteFile(BSFile* f);

char __cdecl FUN_00af2750();

size_t __cdecl _strlen(const char* s);

int __cdecl _strcpy_s(char* dst, size_t size, const char* src);

long FUN_00aeabf0(void* stream, long offset, int whence, int pad);

long __cdecl FUN_00af2290(void* param_1);

void* __cdecl SndMemCopy(void* dst, const void* src, unsigned int n);

void* __cdecl SndMemSet(void* dst, int c, unsigned int n);

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

void __cdecl FUN_00ec61c0(void*, int, unsigned int);

int __cdecl CallProcAndAccumulate(void* arg0, int a, int b, FUN_00af2180_cls* p);

int DispatchHandlerEvent(void* pvHandler, void* pvEvent, void* pvUnused, void* pvData);

bool HasWildcardChars(const char* s);

unsigned int* __cdecl FUN_00ec3bad(unsigned int* value);

int __cdecl CopyFileChecked(const char* lpExistingFileName, const char* lpNewFileName, unsigned char bFailIfExists);

class NiRefObject
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiObjPtr
{
    NiRefObject* m_pObject;

    NiObjPtr& operator=(const NiObjPtr& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    ~NiObjPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct AE8DE0_Record
{
    int unk00;
    int m_04;
    NiObjPtr m_08;
};

class AE8DE0_Class
{
  public:
    int unk00;

    void FUN_00ae8de0(AE8DE0_Record* a1, int a2, NiObjPtr a3);
};

// @fnv 0x00ae8de0
void AE8DE0_Class::FUN_00ae8de0(AE8DE0_Record* a1, int a2, NiObjPtr a3)
{
    a1->m_04 = a2;
    a1->m_08 = a3;
}

struct ScopeGuard_b10070
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    __forceinline ~ScopeGuard_b10070()
    {}
};

struct FUN_00ae8e70_cls
{
    void* vtbl;
    int unk04;
    void* m_08;

    void FUN_00ae8e70();
};

// @fnv 0x00ae8e70
void FUN_00ae8e70_cls::FUN_00ae8e70()
{
    *(void**)this = (void*)&DAT_010a3308;
    {
        ScopeGuard_b10070 g;
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
    *(void**)this = (void*)&DAT_010a33b0;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_08);
}

struct SoundList936
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    SoundList936()
    {
        m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
    ~SoundList936();
};

struct FUN_00ae9360
{
    virtual void V00();
    int unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020;
    int unk024, unk028, unk02C, unk030, unk034, unk038, unk03C, unk040;
    int unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080;
    int unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0;
    int unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0;
    int unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0;
    int unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100;
    int unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120;
    int unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140;
    int unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160;
    int unk164, unk168, unk16C, unk170, unk174, unk178, unk17C, unk180;
    int unk184, unk188;
    SoundList936 m_kList;

    FUN_00ae9360();
};

// @fnv 0x00ae9360
FUN_00ae9360::FUN_00ae9360()
{
    ::FUN_00ae95e0((char *)this);
}

inline float SqrtA810(float f)
{
    return (float)sqrt(f);
}

struct Pt3A810
{
    float x, y, z;
    Pt3A810()
    {}
    Pt3A810(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Pt3A810 operator-(const Pt3A810& pt) const
    {
        return Pt3A810(x - pt.x, y - pt.y, z - pt.z);
    }
    float Length() const
    {
        return SqrtA810(x * x + y * y + z * z);
    }
};

struct SpeedA810
{
    void* vtbl;
    Pt3A810 m_pos;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    unsigned long m_lastTime;
    float m_speed;
    void FUN_00aea810(const Pt3A810& pos);
};

// @fnv 0x00aea810
void SpeedA810::FUN_00aea810(const Pt3A810& pos)
{
    unsigned long uiNow = timeGetTime();
    Pt3A810 kDelta = pos - m_pos;
    m_speed = reinterpret_cast<::NiPoint3 *>((void *)&(kDelta))->ComputeMagnitude() / ((uiNow - m_lastTime) * 1000) * DAT_010a3be8;
    m_pos = pos;
    m_lastTime = uiNow;
}

struct WavFmt
{
    unsigned short wFormatTag;
    unsigned short wChannels;
    unsigned int dwSamplesPerSec;
    unsigned int dwAvgBytesPerSec;
    unsigned short wBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short wCbSize;
};

struct SndInfo
{
    int unk0;
    int f4;
    int f8;
};

struct Mgr
{
};

struct AF1d80
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
    void* m2d0;
    int m2d4;
    SndInfo* m2d8;
    unsigned char m2dc;
    unsigned char unk2dd;
    unsigned char unk2de;
    unsigned char unk2df;
    AF1d80();
    ~AF1d80()
    {
        reinterpret_cast<::FUN_00af1d80_cls *>(this)->UpdateAndReleaseTarget();
    }

    __forceinline int SamplesPerSec()
    {
        return this->m2d8 ? this->m2d8->f8 : 0;
    }
    __forceinline unsigned int Channels()
    {
        return this->m2d8 ? this->m2d8->f4 : 1;
    }
    __forceinline unsigned int BytesPerFrame()
    {
        return (this->m2d8 ? this->m2d8->f4 : 1) * (this->m2d4 * 2);
    }
};

__forceinline bool AudioBuffer::Setup(bool& bHalf, unsigned int& nSize)
{
    void* p;
    if (this->Any() && ((this->m_flags & 0x2000) || (this->m_flags & 0x1000)))
        this->m_flags |= 0x10;
    this->m_flags &= 0xfdffffff;
    this->m_flags &= 0xfbffffff;
    bHalf = (this->m_flags & 0x400000) || (this->m_flags & 0x100000);
    nSize = 0;
    this->m_descSize = 0x24;
    this->m_eVertexFormat->cbSize = 0;
    this->m_eVertexFormat->tag = 1;
    this->m_eVertexFormat->m_uiSamplesPerSecond = this->m_stream->SamplesPerSec();
    this->m_eVertexFormat->m_usBitsPerSample = 0x10;
    this->m_eVertexFormat->channels = this->m_stream->Channels();
    this->m_eVertexFormat->blockAlign = (this->m_eVertexFormat->m_usBitsPerSample / 8) * this->m_eVertexFormat->channels;
    this->m_eVertexFormat->averageBytes = this->m_eVertexFormat->m_uiSamplesPerSecond * this->m_eVertexFormat->blockAlign;
    this->m_bufferBytes = this->m_stream->BytesPerFrame();
    this->m_totalBytes = this->m_bufferBytes;
    if (bHalf)
        nSize = this->m_bufferBytes + (this->m_eVertexFormat->averageBytes >> 1);
    else
        nSize = this->m_bufferBytes;
    p = reinterpret_cast<::MemoryManagerStandIn *>((((Mgr*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa3e40(nSize);
    this->m_oldBuffer = p;
    std::memset(this->m_oldBuffer, 0, nSize);
    this->m_sampleRate = this->m_eVertexFormat->m_uiSamplesPerSecond;
    this->m_sampleCount = this->m_sampleRate;
    this->m_playLength = this->m_totalBytes / (2 * this->m_stream->Channels()) / (this->m_sampleRate / 1000);
    reinterpret_cast<::FUN_00af2100_cls *>((this->m_stream))->FUN_00af2100((unsigned char *)(this->m_oldBuffer), this->m_bufferBytes);
    if ((this->m_flags & 1) || (this->m_stream->Channels() > 1))
    {
        this->m_descFlags = 0x40;
        this->m_flags &= 0xfffffffd;
        this->m_flags |= 1;
    }
    else
    {
        this->m_descFlags = 0x30010;
    }
    this->m_descFlags |= 0x2a0;
    if (bHalf)
    {
        this->m_bufferBytes = this->m_bufferBytes + (this->m_eVertexFormat->averageBytes >> 1);
        this->m_totalBytes = this->m_bufferBytes;
        this->m_playLength = this->m_playLength + 0x1f4;
    }
    return reinterpret_cast<::FUN_00ae9c50_s *>((this))->SetFlagState(true);
}

struct AE8150_Node
{
    AE8150_Node* m_pkNext;
    AE8150_Node* m_pkPrev;
    void* m_element;
};

typedef AE8150_Node* AE8150_Pos;

struct AE8150_List
{
    AE8150_Node* m_pkHead;
    AE8150_Node* m_pkTail;
    AE8150_Pos GetHeadPos() const
    {
        return m_pkHead;
    }
    void* const& GetNext(AE8150_Pos& kPos) const
    {
        void* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    AE8150_Pos FindPos(void* const& element, AE8150_Pos kPos = 0) const
    {
        if (kPos == 0)
            kPos = GetHeadPos();
        while (kPos)
        {
            AE8150_Pos kPrev = kPos;
            if (element == GetNext(kPos))
                return kPrev;
        }
        return 0;
    }
    void Reserve() const
    {
        int unused[15];
        (void)unused;
    }
    void* FUN_00ae8150(void* const& element);
};

// @fnv 0x00ae8150
void* AE8150_List::FUN_00ae8150(void* const& element)
{
    AE8150_Pos kPos = FindPos(element);
    Reserve();
    return kPos ? ((void *)(reinterpret_cast<::FUN_00ae8090_Class *>(this)->FUN_00ae8090((::FUN_00ae8090_Node **)&(kPos)))) : element;
}

struct MapStorageBase : BucketTableStorage
{
    inline ~MapStorageBase()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(data);
    }
};

struct FUN_00ae8c60 : MapStorageBase
{
    ~FUN_00ae8c60();
};

// @fnv 0x00ae8c60
FUN_00ae8c60::~FUN_00ae8c60()
{
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
}

struct MemoryManager8D10
{
    void Deallocate(void* pvMem);
};

extern MemoryManager8D10 g_kMemoryManager8D10;

struct MapItem8D10
{
    MapItem8D10* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBase8D10
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager8D10.Deallocate(pvMem);
    }
    virtual ~MapBase8D10()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItem8D10* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItem8D10* pkItem);
    virtual MapItem8D10* NewItem();
    virtual void DeleteItem(MapItem8D10* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItem8D10* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItem8D10** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00ae8d10 : public MapBase8D10
{
  public:
    virtual ~FUN_00ae8d10();
};

// @fnv 0x00ae8d10
FUN_00ae8d10::~FUN_00ae8d10()
{
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
}

struct FUN_00ae93f0 : FUN_00ae9360_Base
{
    virtual ~FUN_00ae93f0();
};

struct AudioCleanupHelper
{
    __forceinline ~AudioCleanupHelper();
};

struct AudioStreamStorage
{
    int state;
    unsigned int position;
    unsigned int headSize;
    unsigned int bodySize;
    unsigned int tailSize;
    unsigned int tailPosition;
    void* head;
    void* body;
    void* tail;
};

struct FUN_00aeafb0 : FUN_00ae93f0
{

    int unk198;
    SndUnknown* unk19C;
    SndUnknown* unk1A0;
    Stub1A4 unk1A4;
    void* unk1C8;
    int unk1CC;
    int unk1D0;
    SndUnknown* unk1D4;
    SndUnknown* unk1D8;
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
    unsigned short unk20C;
    unsigned short unk20E;
    unsigned short unk210;
    unsigned short unk212;
    unsigned short unk214;
    unsigned short unk216;
    NiPoint3 unk218;
    char unk224;
    AudioStreamStorage* unk228;
    AudioCleanupHelper* unk22C;
    virtual ~FUN_00aeafb0();
};

namespace fnv_00af1cc0 {
struct MemoryManager
{
};
struct FUN_00af1cc0_Class
{
    void* FUN_00af1cc0(unsigned int flags);
};
// Calls FUN_00aeafb0, deallocates this via _g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00af1cc0
void* FUN_00af1cc0_Class::FUN_00af1cc0(unsigned int flags)
{
    reinterpret_cast<::FUN_00aeafb0 *>(this)->FUN_00aeafb0::~FUN_00aeafb0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00af1cc0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00af1cc0

// @fnv 0x00aeafb0
FUN_00aeafb0::~FUN_00aeafb0()
{
    if (unk19C)
    {
        while (unk19C->Release())
        {
        }
        unk19C = 0;
    }
    if (unk1D4)
    {
        while (unk1D4->Release())
        {
        }
        unk1D4 = 0;
    }
    if (unk1A0)
    {
        --DAT_011f7128;
        while (unk1A0->Release())
        {
        }
        unk1A0 = 0;
    }
    if (unk1D8)
    {
        while (unk1D8->Release())
        {
        }
        unk1D8 = 0;
    }
    if (unk1A4.pBuf)
    {
        void* buffer = unk1A4.pBuf;
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(buffer);
        unk1A4.pBuf = 0;
    }
    if (unk1C8)
    {
        void* buffer = unk1C8;
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(buffer);
        unk1C8 = 0;
    }
    if (unk228)
    {
        if (unk228->head)
        {
            void* buffer = unk228->head;
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(buffer);
        }
        if (unk228->tail)
        {
            void* buffer = unk228->tail;
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(buffer);
        }
        if (unk228->body)
        {
            void* buffer = unk228->body;
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(buffer);
        }
        {
            void* buffer = unk228;
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(buffer);
        }
    }
    if (unk22C)
    {
        delete unk22C;
        unk22C = 0;
    }
}

struct VolumeCurve
{
};

struct VolumeBuffer
{
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int slot5();
    virtual int slot6();
    virtual int slot7();
    virtual int slot8();
    virtual int slot9();
    virtual int slot10();
    virtual int slot11();
    virtual int slot12();
    virtual int slot13();
    virtual int slot14();
    virtual long SetVolume(long);
};

struct BSWin32GameSound
{
    int unk00;
    int unk04;
    int flags08;
    int unk0c;
    int flags10;
    int unk14;
    unsigned short attenuation18, percent1a, attenuation1c, attenuation1e, attenuation20, unk22;
    float volume24;
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
    VolumeBuffer* buffer19c;
    VolumeBuffer* buffer1a0;
    __forceinline unsigned short GetPercent() const
    {
        return percent1a;
    }
    bool IsFlag10Set(unsigned int uiFlag) const
    {
        return (flags10 & uiFlag) != 0;
    }
    bool IsFlag08Set(unsigned int uiFlag) const
    {
        return (flags08 & uiFlag) != 0;
    }
    bool FUN_00aed660(float volume);
};

// @fnv 0x00aed660
bool BSWin32GameSound::FUN_00aed660(float volume)
{
    unsigned int scaled;
    long result3;
    volume24 = volume;
    float scaleA = GetPercent();
    long attenuationTmp = 0;
    long adjusted3 = 0;
    scaleA /= 100.0;
    if (buffer19c)
    {
        volume = volume > 1.0 ? 1.0f : volume;
        volume = volume < 0.0 ? 0.0f : volume;
        volume = reinterpret_cast<::AudioMgr_adac30 *>((((::VolumeCurve *)(::FUN_00ad9060()))))->FUN_00adac30(volume, flags08);
        if (!IsFlag10Set(0x200) && IsFlag10Set(0x10000) && !IsFlag08Set(0x1000))
            volume = 0.00001f;
        volume = volume < 9.999999747378752e-06 ? 0.00001f : volume;
        attenuationTmp = (int)((float)std::log10(volume) * 2000.0);
        attenuationTmp -= attenuation18 + attenuation1c + attenuation20;
        if (reinterpret_cast<::BSGameSound *>(this)->HasSoundFlagTwo() || reinterpret_cast<::BSGameSound *>(this)->CanStartPlayback())
            attenuationTmp -= attenuation1e;
        if (flags10 & 0x8)
        {
        }
        attenuationTmp = attenuationTmp > -10000 ? attenuationTmp : -10000;
        attenuationTmp = attenuationTmp < -1 ? attenuationTmp : -1;
        scaled = (unsigned int)(scaleA * -10000.0);
        adjusted3 = attenuationTmp + scaled;
        adjusted3 = adjusted3 > -10000 ? adjusted3 : -10000;
        adjusted3 = adjusted3 < -1 ? adjusted3 : -1;
        if (!IsFlag10Set(0x400))
        {
            result3 = 0x80004005;
            if (buffer1a0)
                buffer1a0->SetVolume(adjusted3);
            if (buffer19c)
                result3 = buffer19c->SetVolume(attenuationTmp);
            if (result3 >= 0)
                return true;
            else
                return false;
        }
        else
        {
            if (buffer1a0)
                buffer1a0->SetVolume(-10000);
            return buffer19c->SetVolume(-10000) >= 0;
        }
    }
    else
        return false;
}

inline float P010Root(float f)
{
    return FUN_004579e0(f);
}

struct P010Vec
{
    float x, y, z;
    P010Vec()
    {}
    P010Vec(float a, float b, float c) : x(a), y(b), z(c)
    {}
    inline P010Vec operator-(const P010Vec& r) const
    {
        return P010Vec(x - r.x, y - r.y, z - r.z);
    }
    inline P010Vec operator+(const P010Vec& r) const
    {
        return P010Vec(x + r.x, y + r.y, z + r.z);
    }
    inline float DotProduct(const P010Vec& r) const
    {
        return x * r.x + y * r.y + z * r.z;
    }
    inline float FUN_00457990() const
    {
        return P010Root(x * x + y * y + z * z);
    }
};

inline P010Vec __cdecl FUN_004a3760(float s, const P010Vec& r)
{
    return P010Vec(s * r.x, s * r.y, s * r.z);
}

struct P010Listener
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual const P010Vec* Position();
};

struct P010Audio
{
    int unk00, unk04, unk08, unk0c;
    P010Listener* listener;
    __forceinline static P010Audio* Get()
    {
        return (P010Audio*)DAT_011f6d98;
    }
    __forceinline P010Listener* Listener()
    {
        return listener;
    }
};

struct P010Sound
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void SetPosition(float, float, float, int);
};

struct P010Object;

struct P010ObjectVtable
{
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0c;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1c;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2c;
    void* slot30;
    void* slot34;
    void* slot38;
    void(* update)(P010Object*, float);
};

struct P010Object
{
    P010ObjectVtable* vtable;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c, volume;
    unsigned int unk20;
    float unk24;
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
    float unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    float unk150;
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
    P010Vec origin;
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
    P010Sound* sound1d4;
    P010Sound* sound1d8;
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
    unsigned short attenuation20c, attenuation20e;
    unsigned short attenuation210, attenuation212;
    unsigned short attenuation214, attenuation216;
    P010Vec position;
    bool dirty;
    inline bool IsProjected() const
    {
        return (unk8 & 0x10000000) != 0;
    }
    inline bool IsLine() const
    {
        return (unk10 & 0x8000) != 0;
    }
    inline void SetDistance(float d)
    {
        unk150 = d;
    }
    inline void SetVolume(unsigned short a)
    {
        volume = a;
        vtable->update(this, unk24);
    }
    void FUN_00aef090(float x, float y, float z);
};

// @fnv 0x00aef090
void P010Object::FUN_00aef090(float x, float y, float z)
{
    P010Vec tempVector;
    P010Vec output;
    output = *(const P010Vec*)&::NiPoint3::ZERO;
    tempVector = *(const P010Vec*)&::NiPoint3::ZERO;
    bool changed = false;
    if ((reinterpret_cast<::BSGameSound *>(this)->HasSoundFlagTwo() || reinterpret_cast<::BSGameSound *>(this)->CanStartPlayback()) && unk198)
    {
        float distance;
        P010Listener* listener;
        {
            P010Vec current, delta8, toListener4;

            float local41, local1, ratio7, lowVal, mid4, highVal;
            {
                if (P010Audio::Get()->Listener())
                {
                    listener = P010Audio::Get()->Listener();
                    tempVector = *listener->Position();
                    if (unk8 & 0x40000)
                    {
                        x = tempVector.x;
                        y = tempVector.y;
                        z = tempVector.z;
                    }
                    if (position.x != x || position.y != y || position.z != z)
                    {
                        position.x = x;
                        position.y = y;
                        position.z = z;
                        changed = true;
                    }
                }
                dirty = true;
                if (sound1d4)
                {
                    if ((!IsProjected() || !IsLine()) && changed)
                    {
                        sound1d4->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8), float(y * DAT_010a3be8),
                                              1);
                        if (sound1d8)
                            sound1d8->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8),
                                                  float(y * DAT_010a3be8), 1);
                    }
                    else if (P010Audio::Get()->Listener() && IsProjected() && IsLine())
                    {
                        local41 = 0.0f;
                        local1 = 0.0f;
                        ratio7 = 0.0f;
                        current = *P010Audio::Get()->Listener()->Position();
                        delta8 = origin - position;
                        toListener4 = current - position;
                        local41 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(toListener4))->DotProduct((void *)&(delta8));
                        if (local41 <= 0.0)
                            output = position;
                        else
                        {
                            local1 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(delta8))->DotProduct((void *)&(delta8));
                            if (local1 <= local41)
                                output = origin;
                            else
                            {
                                ratio7 = local41 / local1;
                                output = position + FUN_004a3760(ratio7, delta8);
                            }
                        }
                        sound1d4->SetPosition(float(output.x * DAT_010a3be8), float(output.z * DAT_010a3be8),
                                              float(output.y * DAT_010a3be8), 1);
                        if (sound1d8)
                            sound1d8->SetPosition(float(output.x * DAT_010a3be8), float(output.z * DAT_010a3be8),
                                                  float(output.y * DAT_010a3be8), 1);
                    }
                }
                SetDistance(reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::P010Vec &)((tempVector - position)))->ComputeMagnitude());
                distance = unk150;
                if (IsProjected() && IsLine() && P010Audio::Get()->Listener())
                {
                    distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::P010Vec &)((output - *P010Audio::Get()->Listener()->Position())))->ComputeMagnitude();
                }
                if (fabs(unk13c - unk140) > 10.0)
                {
                    lowVal = (unk13c - unk140) * 0.25 + unk140;
                    mid4 = (unk13c - unk140) * 0.5 + unk140;
                    highVal = (unk13c - unk140) * 0.75 + unk140;
                    if (distance >= unk13c)
                    {
                        SetVolume(10000);
                    }
                    else if (distance > highVal && unk13c - highVal > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation212 + (attenuation214 - attenuation212) *
                                                                        ((distance - highVal) / (unk13c - highVal))));
                    }
                    else if (distance > mid4 && highVal - mid4 > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation210 + (attenuation212 - attenuation210) *
                                                                        ((distance - mid4) / (highVal - mid4))));
                    }
                    else if (distance > lowVal && mid4 - lowVal > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation20e + (attenuation210 - attenuation20e) *
                                                                        ((distance - lowVal) / (mid4 - lowVal))));
                    }
                    else if (distance > unk140 && lowVal - unk140 > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation20c + (attenuation20e - attenuation20c) *
                                                                        ((distance - unk140) / (lowVal - unk140))));
                    }
                    else
                    {
                        SetVolume(0);
                    }
                }
                else
                {
                    if (distance >= unk13c)
                    {
                        SetVolume(10000);
                    }
                    else
                    {
                        SetVolume(0);
                    }
                }
                vtable->update(this, unk24);
            }
        }
    }
}

struct OggFile
{
    virtual ~OggFile();
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
    bool bGood;
    __forceinline bool IsGood() const
    {
        return bGood;
    }
};

struct OvCallbacks
{
    unsigned int(__cdecl* read_func)(void* ptr, unsigned int size, unsigned int nmemb, void* datasource);
    int(__cdecl* seek_func)(void* datasource, __int64 offset, int whence);
    int(__cdecl* close_func)(void* datasource);
    long(__cdecl* tell_func)(void* datasource);
};

unsigned int __cdecl CallProcAndAccumulate(void* ptr, unsigned int size, unsigned int nmemb, void* datasource);

int __cdecl DispatchHandlerEvent(void* datasource, __int64 offset, int whence);

long __cdecl FUN_00af2290(void* datasource);

struct OggStream;

extern "C" int __cdecl ov_open_callbacks(void* datasource, OggStream* vf, char* initial, long ibytes,
                                         OvCallbacks callbacks);

struct VorbisInfo;

struct OggStream
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
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    OggFile* pFile;
    int iTotal;
    VorbisInfo* iInfo;
    bool bOpen;

    bool FUN_00af1e00(const char* name);
};

// @fnv 0x00aebff0
bool AudioBuffer::FUN_00aebff0()
{
    this->m_stream = new AF1d80();
    if (!reinterpret_cast<::OggStream *>((this->m_stream))->FUN_00af1e00(this->m_fileName))
    {
        delete this->m_stream;
        this->m_stream = 0;
        return false;
    }
    bool bHalf;
    unsigned int nSize;
    return Setup(bHalf, nSize);
}

// @fnv 0x00af1e00
bool OggStream::FUN_00af1e00(const char* name)
{
    // Legacy target lowercases259 bytes after strcpy, including the unused tail beyond NUL.
    char path3[260];
    strcpy(path3, name);
    for (int i4 = 0; i4 < 259; i4++)
        path3[i4] = tolower(path3[i4]);
    char* ext3 = strstr(path3, ".ogg");
    if (!ext3)
    {
        ext3 = strstr(path3, ".mp3");
        if (!ext3)
            ext3 = strstr(path3, ".wav");
        if (ext3)
        {
            ext3[1] = 'o';
            ext3[2] = 'g';
            ext3[3] = 'g';
        }
        else
        {
            return false;
        }
    }
    pFile = (OggFile*)FileFinder::GetFile(path3, 0, 0x4000, 0x10);
    if (!pFile || !pFile->IsGood())
    {
        if (pFile)
        {
            delete pFile;
            pFile = 0;
        }
        return false;
    }
    OvCallbacks cb_ = {CallProcAndAccumulate, DispatchHandlerEvent, 0, FUN_00af2290};
    int ret = ov_open_callbacks(pFile, this, 0, 0, cb_);
    if (ret)
    {
        reinterpret_cast<::BSFile *>((pFile))->Close();
        delete pFile;
        pFile = 0;
        return false;
    }
    bOpen = true;
    iInfo = ((::VorbisInfo *)(::FUN_00ee81f8(this, -1)));
    if (((long)(::FUN_00ee81f2(this))))
        iTotal = static_cast<int>(::FUN_00ee81ec(this, 0));
    return true;
}

inline void NiEndianSwap(unsigned int& uiValue, Flag kFlag)
{
    unsigned int* puiValue = &uiValue;
    *puiValue = fnv::crt::byteswap_ulong(*puiValue);
}

inline void NiEndianSwap(unsigned short& usValue, Flag kFlag)
{
    unsigned short* pusValue = &usValue;
    *pusValue = fnv::crt::byteswap_ushort(*pusValue);
}

struct ArchiveHeader
{
    unsigned int m_uiMagic;
    unsigned int m_uiSize;
    unsigned int m_uiType;
    FUN_00afd920_Class m_kFlags;
    unsigned int m_uiValueBeforeCount;
    unsigned int m_uiCharacterCount;
    unsigned int m_uiHash;
    unsigned int m_uiCRC;
    unsigned short m_usElementCount;

    void FUN_00afd9d0();
};

// @fnv 0x00afd9d0
void ArchiveHeader::FUN_00afd9d0()
{
    NiEndianSwap(m_uiMagic, Flag());
    NiEndianSwap(m_uiSize, Flag());
    NiEndianSwap(m_uiType, Flag());
    m_kFlags.UpdateValue();
    NiEndianSwap(m_uiValueBeforeCount, Flag());
    NiEndianSwap(m_uiCharacterCount, Flag());
    NiEndianSwap(m_uiHash, Flag());
    NiEndianSwap(m_uiCRC, Flag());
    NiEndianSwap(m_usElementCount, Flag());
}

struct MemoryManagerAllocator
{
};

inline void CopyChars(unsigned short* destination, const unsigned short* source, unsigned int size)
{
    std::memmove(destination, source, size);
}

struct WideString
{
    unsigned short* data;
    unsigned short length;
    unsigned short capacity;
    bool FUN_00afff50(const unsigned short* input, unsigned int reserve);
};

// @fnv 0x00afff50
bool WideString::FUN_00afff50(const unsigned short* input, unsigned int reserve)
{
    unsigned int a;
    a = input ? std::wcslen((const wchar_t *)(input)) : 0;
    unsigned int newSize = a > reserve ? a : reserve;
    unsigned short* required;
    if (newSize <= capacity)
    {
        if (newSize)
        {
            if (input)
            {
                CopyChars(data, input, 2 * a + 2);
            }
            else
            {
                *data = 0;
            }
        }
        else
        {
            if (data)
                delete[] data;
            data = 0;
            newSize = 0;
            capacity = newSize <= 0xffff ? (unsigned short)newSize : 0xffff;
        }
    }
    else
    {
        required = data;
        data = new unsigned short[newSize + 1];
        if (input)
        {
            CopyChars(data, input, 2 * a + 2);
        }
        else
        {
            *data = 0;
        }
        if (required)
            delete[] required;
        capacity = newSize <= 0xffff ? (unsigned short)newSize : 0xffff;
    }
    length = a <= 0xffff ? (unsigned short)a : 0xffff;
    return a != 0;
}

struct AE92D0_Range
{
    int m_kRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    AE92D0_Range()
    {
        m_uiItemCount = 0;
        m_kRayStart = 0;
        m_kRayEnd = 0;
    }
    ~AE92D0_Range();
};

struct AE92D0_Object
{
    virtual ~AE92D0_Object();
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
    AE92D0_Range m_range;
    AE92D0_Object(int unused);
};

// @fnv 0x00ae92d0
AE92D0_Object::AE92D0_Object(int unused)
{
    ::FUN_00ae95e0((char *)this);
}

void* __cdecl FUN_00ec7230(void* dst, const void* src, unsigned int size);

class FUN_005eee10
{
  public:
    typedef const char* Elem;
    void** m_vtbl;
    const char** m_data;
    unsigned int m_iElementCount;
    ~FUN_005eee10();

    void FUN_0042fb60(const char** pDst, const char** pSrc, unsigned int ItemUpdateArray)
    {
        if (ItemUpdateArray <= 0)
            return;
        if (pDst < pSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(const char*));
        }
        else if (pDst > pSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(const char*));
        }
    }

    void RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray)
    {
        unsigned int uiMove;
        unsigned int uiTail = m_iElementCount - uiIndex - ItemUpdateArray;
        uiMove = uiTail < ItemUpdateArray ? uiTail : ItemUpdateArray;
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
            (m_data + uiIndex + i)->~Elem();
        FUN_0042fb60(m_data + uiIndex, m_data + m_iElementCount - uiMove, uiMove);
        m_iElementCount -= ItemUpdateArray;
    }
};

class FileFinderImpl
{
  public:
    FUN_005eee10 m_ppData;
    ~FileFinderImpl();
};

// @fnv 0x00afdcf0
FileFinderImpl::~FileFinderImpl()
{
    unsigned int uiSize = m_ppData.m_iElementCount;
    unsigned int uiIndex = uiSize;
    while (uiIndex--)
    {
        const char* item = m_ppData.m_data[uiIndex];
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060((void*)item);
        reinterpret_cast<::S_00afea20_Arr *>(&(m_ppData))->RemoveRange(uiIndex, 1);
    }
    if ((*reinterpret_cast<::FileFinderImpl * *>(&::g_fileFinder)) == this)
    {
        (*reinterpret_cast<::FileFinderImpl * *>(&::g_fileFinder)) = 0;
    }
}

struct MgrAF
{
};

struct GuidAF
{
    unsigned int a;
    unsigned short b, c;
    unsigned char d[8];
};

extern GuidAF DAT_01101004, DAT_01100fd4;

class Setting_01017720_011f96a0
{
  public:
    int vtable;
    unsigned int value;
};

struct OutputAF;

struct AudioAF
{
    int u0, u4, u8, uc;
    void* p10;
    inline OutputAF* GetOutput()
    {
        return (OutputAF*)p10;
    }
    static inline AudioAF* Instance()
    {
        return (AudioAF*)DAT_011f6d98;
    }
};

struct OutputAF
{
    virtual void x0();
    virtual void x4();
    virtual void x8();
    virtual void xc();
    virtual void x10();
    virtual void x14();
    virtual void x18();
    virtual void x1c();
    virtual void x20();
    virtual void x24();
    virtual void x28();
    virtual unsigned int x2c();
};

struct BufferAF
{
    virtual long Query(void*, void**);
    virtual void x04();
    virtual void x08();
    virtual void x0c();
    virtual void x10();
    virtual long Format(void*, unsigned long, unsigned long*);
    virtual void x18();
    virtual void x1c();
    virtual void x20();
    virtual void x24();
    virtual void x28();
    virtual long Lock(unsigned long, unsigned long, void**, unsigned long*, void**, unsigned long*,
                                unsigned long);
    virtual void x30();
    virtual void x34();
    virtual void x38();
    virtual void x3c();
    virtual void x40();
    virtual void x44();
    virtual void x48();
    virtual long Unlock(void*, unsigned long, void*, unsigned long);
    virtual void x50();
    virtual long Effect(unsigned long, void*, void*);
    virtual void x58();
    virtual long Object(void*, unsigned long, void*, void**);
};

struct DeviceAF
{
    virtual void x00();
    virtual void x04();
    virtual void x08();
    virtual long Create(void*, void**, void*);
};

struct EffectObjectAF
{
    virtual void x00();
    virtual void x04();
    virtual void x08();
    virtual void x0c();
    virtual void x10();
    virtual long Set(unsigned int);
};

struct EffectAF
{
    unsigned int size, flags;
    GuidAF guid;
    unsigned int reserved1, reserved2;
};

struct DescAF
{
    unsigned int size, flags, bytes, reserved;
    void* format;
    GuidAF guid;
};

inline bool& EnableAF()
{
    return &::g_011f7130 ? *(bool*)&::g_011f7130.value : (*(bool*)&(*reinterpret_cast<unsigned int *>(&::DAT_01202800)) = false, *(bool*)&(*reinterpret_cast<unsigned int *>(&::DAT_01202800)));
}

inline unsigned int& LimitAF()
{
    return &::g_011f713c ? ::g_011f713c.value : ((*reinterpret_cast<unsigned int *>(&::DAT_01202800)) = 0, (*reinterpret_cast<unsigned int *>(&::DAT_01202800)));
}

inline void* AllocateAF(unsigned int size)
{
    void* p = reinterpret_cast<::MemoryManagerStandIn *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa3e40(size);
    return p;
}

inline void FreeAF(void* p)
{
    reinterpret_cast<::FNV_MemoryManager *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(p);
}

inline void ZeroAF(void* dest, unsigned int size)
{
    std::memset(dest, 0, size);
}

inline void CopyAF(void* dest, const void* source, unsigned int size)
{
    std::memmove(dest, source, size);
}

struct AF1430
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
    DeviceAF* device;
    BufferAF* source;
    BufferAF* buffer;
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
    BufferAF* created;
    unsigned int unk1d4;
    void* unkEffect;
    unsigned int unk1dc;
    void* object;
    __forceinline unsigned int Flags()
    {
        return unk008;
    }
    __forceinline bool Any()
    {
        return (unk008 & 0x4000000) || (unk008 & 0x2000000);
    }
    bool FUN_00af1430();
};

// Creates the DirectSound buffer for the sound, sets up streaming chunks and 3D/reverb parameters, then updates flags.
// @fnv 0x00aec530
void FUN_00aec530_cls::FUN_00aec530()
{
    long hr5;
    SndEffectDesc gate;
    unsigned long flagVal;
    char* found2;
    unsigned int entry2;
    int gap;
    char* data4;
    void* buf;
    char* head2;
    long hr3;
    unsigned long countB;
    int bytes;
    {
        float* entry6;
        unsigned int endA;
        char* element4;
        unsigned int iter4;
        char* indexX;
        unsigned int id8;
        char* holder7;
        unsigned int group4;
        unsigned int fresh4;
        char* handleA;
        unsigned int hashA;
        char* gammaA;
        unsigned int gateVal;
        char* bVal;
        unsigned int bResult;
        char* flagJ;
        unsigned int flagH;
        unsigned int fcList;
        unsigned int f11;
        void* iterVal;
        void* curVal;
        void* chc;
        void* first2;
        void* input2;
        void* itemB;

        if (m_pDirectInputDevice == 0)
        {
            reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(0);
            return;
        }
        bytes = m_kDesc.lpwfxFormat->wBitsPerSample / 8;
        if (reinterpret_cast<::BSGameSound *>(this)->HasSoundFlagTwo() || reinterpret_cast<::BSGameSound *>(this)->CanStartPlayback())
        {
            m_sFrequency = 10000;
        }
        if (m_pData != 0)
        {
            if ((unsigned char)(((m_uiValue1 & 0x4000000) || (m_uiValue1 & 0x2000000)) ? 1 : 0))
            {
                gap = 0x400;
                itemB = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::SndHeap *>(&::g_memoryManager))))->FUN_00aa3e40(0x24);
                m_pBinaryStream = (SndStream*)itemB;
                m_pBinaryStream->uiHeadSize = m_iLoopStart * bytes;
                m_pBinaryStream->uiTailSize = m_uiSize - m_iLoopEnd * bytes;
                m_pBinaryStream->uiBodySize = m_uiSize - (m_pBinaryStream->uiHeadSize + m_pBinaryStream->uiTailSize);
                m_uiSize = m_kDesc.lpwfxFormat->nAvgBytesPerSec / 2;
                m_kDesc.dwBufferBytes = m_uiSize;
                m_pBinaryStream->uiTailPos = 0;
                m_pBinaryStream->iState = 0;
                m_pBinaryStream->uiPos = 0;
                f11 = m_pBinaryStream->uiHeadSize;
                input2 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::SndHeap *>(&::g_memoryManager))))->FUN_00aa3e40(f11);
                m_pBinaryStream->pHead = (char*)input2;
                fcList = m_pBinaryStream->uiBodySize;
                first2 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::SndHeap *>(&::g_memoryManager))))->FUN_00aa3e40(fcList);
                m_pBinaryStream->pBody = (char*)first2;
                flagH = m_pBinaryStream->uiTailSize + gap;
                chc = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::SndHeap *>(&::g_memoryManager))))->FUN_00aa3e40(flagH);
                m_pBinaryStream->pTail = (char*)chc;
                data4 = m_pData;
                bResult = m_pBinaryStream->uiHeadSize;
                flagJ = m_pBinaryStream->pHead;
                std::memmove(flagJ, data4, bResult);
                data4 += m_pBinaryStream->uiHeadSize;
                gateVal = m_pBinaryStream->uiBodySize;
                bVal = m_pBinaryStream->pBody;
                std::memmove(bVal, data4, gateVal);
                data4 += m_pBinaryStream->uiBodySize;
                hashA = m_pBinaryStream->uiTailSize;
                gammaA = m_pBinaryStream->pTail;
                std::memmove(gammaA, data4, hashA);
                handleA = (char*)*(void* volatile*)&m_pBinaryStream->pTail + m_pBinaryStream->uiTailSize;
                std::memset(handleA, 0, gap);
                m_pBinaryStream->uiTailSize = m_pBinaryStream->uiTailSize + gap;
            }
            if (m_iValueAt14 < 0x96 &&
                (unsigned char)(((m_uiValue1 & 0x10) || (m_uiValue1 & 0x4000000) || (m_uiValue1 & 0x2000000)) ? 1 : 0))
            {
                m_kDesc.dwFlags = m_kDesc.dwFlags & 0xfffffdff;
            }
            hr3 = m_pDirectInputDevice->CreateSoundBuffer(&m_kDesc, &m_pBuffer, 0);
            if (hr3 < 0)
            {
                fresh4 = m_uiValue1;
                if ((fresh4 & 2) && m_kDesc.lpwfxFormat->nChannels > 1)
                {
                    ::FUN_005b5e40();
                }
                else if (hr3 == 0x887800b4)
                {
                    ::FUN_005b5e40();
                }
                if (m_pData != 0)
                {
                    curVal = m_pData;
                    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::SndHeap *>(&::g_memoryManager))))->FUN_00aa4060(curVal);
                    m_pData = 0;
                }
                reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(0);
                return;
            }
            hr3 = m_pBuffer->QueryInterface(&g_IID_SndBuffer8, &m_pBuffer8);
            if (m_pBuffer8 != 0)
            {
                group4 = m_uiValue1;
                if (group4 & 2)
                {
                    hr3 = m_pBuffer8->QueryInterface(&g_IID_Snd3DBuffer, &m_p3DBuffer);
                    m_p3DBuffer->SetMinDistance(g_fSndMinDistance, 1);
                    SetPosition(g_fSndConeValue, g_fSndConeValue, g_fSndConeValue);
                    m_fUnk150 = ::DAT_01016970;
                    m_pBuffer->SetVolume(-10000);
                }
            }
            buf = 0;
            countB = 0;
            hr3 = m_pBuffer8->Lock(0, m_uiSize, &buf, &countB, 0, 0, 0);
            if (hr3 < 0)
            {
                reinterpret_cast<::FUN_00ae9c50_s *>(this)->SetFlagState(0);
                return;
            }
            head2 = (char*)buf;
            if ((unsigned char)(((m_uiValue1 & 0x4000000) || (m_uiValue1 & 0x2000000)) ? 1 : 0) &&
                m_pBinaryStream != 0 && m_pBinaryStream->pHead != 0)
            {
                if (m_pBinaryStream->uiHeadSize > m_uiSize)
                {
                    id8 = m_uiSize;
                    holder7 = m_pBinaryStream->pHead;
                    std::memmove(head2, holder7, id8);
                    m_pBinaryStream->uiPos = m_uiSize;
                    m_pBinaryStream->iState = 1;
                }
                else
                {
                    entry2 = m_uiSize - m_pBinaryStream->uiHeadSize;
                    found2 = head2 + m_pBinaryStream->uiHeadSize;
                    iter4 = m_pBinaryStream->uiHeadSize;
                    indexX = m_pBinaryStream->pHead;
                    std::memmove(head2, indexX, iter4);
                    m_pBinaryStream->uiPos = 0;
                    m_pBinaryStream->uiTailPos = m_pBinaryStream->uiHeadSize;
                    m_pBinaryStream->iState = 2;
                }
            }
            else
            {
                endA = m_uiSize;
                element4 = m_pData;
                std::memmove(head2, element4, endA);
            }
            m_pBuffer8->Unlock(buf, countB, 0, 0);
            if (m_pData != 0)
            {
                iterVal = m_pData;
                reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::SndHeap *>(&::g_memoryManager))))->FUN_00aa4060(iterVal);
                m_pData = 0;
            }
            SetVolume(m_fPlaybackVolume);
        }
        if (m_iValueAt14 >= 0x96)
        {
            reinterpret_cast<::AF1430 *>(this)->FUN_00af1430();
        }
        if (m_uiValue1 & 0x80000)
        {
            gate.dwSize = 0x20;
            gate.dwFlags = 0;
            gate.guidDSFXClass = g_GUID_SndFX;
            gate.dwReserved1 = 0;
            gate.dwReserved2 = 0;
            hr5 = m_pBuffer8->SetFX(1, &gate, &flagVal);
            hr5 = m_pBuffer8->GetObjectInPath(&g_GUID_SndFX, 0, &g_IID_SndFXParams, &m_pReverb);
            if (hr5 >= 0)
            {
                entry6 = (&(*reinterpret_cast<::SndFloatHolder *>(&::g_011f7154)) != 0) ? &(*reinterpret_cast<::SndFloatHolder *>(&::g_011f7154)).fValue
                                                  : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, &(*reinterpret_cast<float *>(&::DAT_01202800)));
                m_afReverb[0] = *entry6;
                m_afReverb[1] = 0.0f;
                m_afReverb[2] = ::runtimeFloatSettingDefault247;
                m_afReverb[3] = g_fSndReverb2;
                m_afReverb[4] = ::runtimeFloatSettingDefault247;
                m_pReverb->SetAllParameters(m_afReverb);
            }
        }
        reinterpret_cast<::BSGameSound *>(this)->Prepare();
    }
}

// @fnv 0x00af1430
bool AF1430::FUN_00af1430()
{
    void* src1Bytes2;
    unsigned long srcn8;
    void* src2Bytes;
    unsigned long CNA;
    {
        DescAF desc;
        {
            unsigned long n;
            {
                EffectAF effect;
                {
                    void* CSAB;
                    void* CSA6;
                    void* CSA2;
                    void* free1_2;
                    void* allocatedB;
                    unsigned int count30;
                    unsigned long n222;
                    void* dst2BytesTmp;
                    long hRefId2;
                    void* dst2Bytes3;
                    if ((Flags() & 0x20) || !EnableAF() || !device || !source || !AudioAF::Instance()->GetOutput() ||
                        !AudioAF::Instance()->GetOutput()->x2c() || Any() || LimitAF() <= (unsigned int)DAT_011f7128)
                        return false;
                    dst2BytesTmp = 0;
                    dst2Bytes3 = 0;
                    n = 0;
                    n222 = 0;
                    src1Bytes2 = 0;
                    src2Bytes = 0;
                    CNA = 0;
                    srcn8 = 0;
                    std::memset(&desc, 0, 0x24);
                    desc.size = 0x24;
                    if (Flags() & 1)
                        desc.flags = 0x40;
                    else
                        desc.flags = 0x30010;
                    desc.flags |= 0x2a0;
                    desc.bytes = unk1dc + (unsigned int)(unk1dc * 0.25);
                    desc.guid = *(GuidAF*)&DAT_01093f04;
                    allocatedB = reinterpret_cast<::MemoryManagerStandIn *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa3e40(0x12);
                    desc.format = allocatedB;
                    source->Format(desc.format, 0x12, &n);
                    DAT_011f7128++;
                    if (device->Create(&desc, (void**)&created, 0) < 0)
                    {
                        (free1_2 = desc.format, reinterpret_cast<::FNV_MemoryManager *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(free1_2));
                        return false;
                    }
                    created->Query((void*)&(*reinterpret_cast<::GuidAF *>((void *)&::g_IID_SndBuffer8)), (void**)&buffer);
                    if (buffer)
                        buffer->Query((void*)&(*reinterpret_cast<::GuidAF *>((void *)&::g_IID_Snd3DBuffer)), &unkEffect);
                    else
                    {
                        (CSA2 = desc.format, reinterpret_cast<::FNV_MemoryManager *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(CSA2));
                        return false;
                    }
                    effect.size = 0x20;
                    effect.flags = 0;
                    effect.guid = DAT_01101004;
                    effect.reserved1 = 0;
                    effect.reserved2 = 0;
                    hRefId2 = buffer->Effect(1, &effect, 0);
                    hRefId2 = buffer->Object(&DAT_01101004, 0, &DAT_01100fd4, &object);
                    if (hRefId2 >= 0)
                    {
                        count30 = unk154;
                        if (AudioAF::Instance()->GetOutput())
                        {
                            count30 = AudioAF::Instance()->GetOutput()->x2c();
                        }
                        if (count30 > 0)
                        {
                            --count30;
                            hRefId2 = ((EffectObjectAF*)object)->Set(count30);
                        }
                    }
                    n = 0;
                    if (buffer->Lock(0, 0, &dst2BytesTmp, &n, &dst2Bytes3, &n222, 2) < 0)
                    {
                        (CSA6 = desc.format, reinterpret_cast<::FNV_MemoryManager *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(CSA6));
                        return false;
                    }
                    if (source->Lock(0, 0, &src1Bytes2, &CNA, &src2Bytes, &srcn8, 2) >= 0)
                    {
                        ZeroAF(dst2BytesTmp, desc.bytes);
                        CopyAF(dst2BytesTmp, src1Bytes2, unk1ac);
                        source->Unlock(src1Bytes2, CNA, src2Bytes, srcn8);
                    }
                    buffer->Unlock(dst2BytesTmp, n, dst2Bytes3, n222);
                    (CSAB = desc.format, reinterpret_cast<::FNV_MemoryManager *>((((MgrAF*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(CSAB));
                    return true;
                }
            }
        }
    }
}

struct AudioVec
{
    float x, y, z;
    AudioVec()
    {}
    AudioVec(float a, float b, float c) : x(a), y(b), z(c)
    {}
    inline AudioVec FUN_00439ef0(const AudioVec& rhs) const
    {
        const AudioVec* self = this;
        return AudioVec(self->x - rhs.x, self->y - rhs.y, self->z - rhs.z);
    }
    inline float DotProduct(const AudioVec& rhs) const
    {
        const AudioVec* self = this;
        float result = self->x * rhs.x + self->y * rhs.y + self->z * rhs.z;
        return result;
    }
};

AudioVec __cdecl FUN_004a3760(float, const AudioVec&);

__forceinline float Absolute(float value)
{
    return float(fabs(value));
}

struct Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual const AudioVec& Position();
};

struct AudioSystem
{
    unsigned int unk00, unk04, unk08, unk0c;
    Listener* listener;
    __forceinline Listener* GetListener()
    {
        return listener;
    }
};

__forceinline AudioSystem* GetSystem()
{
    return reinterpret_cast<AudioSystem*>(DAT_011f6d98);
}

struct PositionOutput
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
    virtual void SetPosition(float, float, float, unsigned int);
};

struct AudioSound
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
    virtual void Refresh(float);
    unsigned int unk004;
    unsigned int flags;
    unsigned int unk00c;
    unsigned int state;
    unsigned int unk014;
    unsigned int unk018;
    unsigned short unk1c;
    unsigned short attenuation;
    unsigned int unk020;
    float volume;
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
    float outer;
    float inner;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    float distance;
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
    AudioVec source;
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
    PositionOutput* primary;
    PositionOutput* secondary;
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
    unsigned short level0;
    unsigned short level1;
    unsigned short level2;
    unsigned short level3;
    unsigned short level4;
    unsigned short unk216;
    AudioVec point;

    __forceinline bool IsSegment()
    {
        return (flags & 0x10000000) != 0;
    }
    __forceinline bool HasSegment()
    {
        return (state & 0x8000) != 0;
    }
    __forceinline void Attenuate(unsigned short value)
    {
        attenuation = value;
        Refresh(volume);
    }
    void FUN_00aed990();
};

// @fnv 0x00aed990
void AudioSound::FUN_00aed990()
{
    float x = 0.0f, coordY = 0.0f, z = 0.0f;
    AudioVec projected3 = reinterpret_cast<const AudioVec&>(::NiPoint3::ZERO);
    if (((unsigned char)(reinterpret_cast<::BSGameSound *>(this)->HasSoundFlagTwo())) || ((unsigned char)(reinterpret_cast<::BSGameSound *>(this)->CanStartPlayback())))
    {
        if (GetSystem()->GetListener())
        {
            if (flags & 0x40000)
            {
                Listener* listenerC3 = GetSystem()->GetListener();
                AudioVec listenerPosition = listenerC3->Position();
                x = listenerPosition.x;
                coordY = listenerPosition.y;
                z = listenerPosition.z;
                if (primary)
                {
                    primary->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8), float(coordY * DAT_010a3be8),
                                         1);
                    if (secondary)
                        secondary->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8),
                                               float(coordY * DAT_010a3be8), 1);
                }
            }
            else if (IsSegment() && HasSegment())
            {
                float projection = 0.0f, squaredLength = 0.0f, fractionX = 0.0f;
                AudioVec center = GetSystem()->GetListener()->Position();
                AudioVec direction2;
                ::NiPoint3 kDirectionDiff;
                direction2 = (*(::AudioVec *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(source))->FUN_00439ef0(&kDirectionDiff, *(const ::NiPoint3 *)&(point))));
                AudioVec delta;
                ::NiPoint3 kDeltaDiff;
                delta = (*(::AudioVec *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(center))->FUN_00439ef0(&kDeltaDiff, *(const ::NiPoint3 *)&(point))));
                projection = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(delta))->DotProduct((void *)&(direction2));
                if (projection <= 0.0)
                {
                    projected3 = point;
                }
                else
                {
                    squaredLength = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(direction2))->DotProduct((void *)&(direction2));
                    if (squaredLength <= projection)
                    {
                        projected3 = source;
                    }
                    else
                    {
                        fractionX = projection / squaredLength;
                        AudioVec scaled = FUN_004a3760(fractionX, direction2);
                        AudioVec sum;
                        projected3 = (*(::AudioVec *)(reinterpret_cast<::Point3Offset *>((void *)&(point))->ProjectileLaunched((::NiPoint3 *)(void *)(&sum), (::NiPoint3 *)(void *)(&scaled))));
                    }
                }
                if (primary)
                {
                    primary->SetPosition(float(projected3.x * DAT_010a3be8), float(projected3.z * DAT_010a3be8),
                                         float(projected3.y * DAT_010a3be8), 1);
                    if (secondary)
                        secondary->SetPosition(float(projected3.x * DAT_010a3be8), float(projected3.z * DAT_010a3be8),
                                               float(projected3.y * DAT_010a3be8), 1);
                }
            }
            float distance = this->distance;
            if (IsSegment() && HasSegment() && GetSystem()->GetListener())
            {
                ::NiPoint3 kProjectedDiff;
                distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::AudioVec &)((*(::AudioVec *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(projected3))->FUN_00439ef0(&kProjectedDiff, *(const ::NiPoint3 *)&(GetSystem()->GetListener()->Position()))))))->ComputeMagnitude();
                this->distance = distance;
            }
            else if (GetSystem()->GetListener())
            {
                ::NiPoint3 kPositionDiff;
                distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::AudioVec &)((*(::AudioVec *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(point))->FUN_00439ef0(&kPositionDiff, *(const ::NiPoint3 *)&(GetSystem()->GetListener()->Position()))))))->ComputeMagnitude();
                this->distance = distance;
            }
            if (Absolute(outer - inner) > 10.0 && outer * ::DAT_010290f8 > distance)
            {
                float quarter = float((outer - inner) * 0.25 + inner);
                float midpointVal = float((outer - inner) * 0.5 + inner);
                float threeQuarter2 = float((outer - inner) * 0.75 + inner);
                if (distance >= outer)
                {
                    Attenuate(10000);
                }
                else if (distance > threeQuarter2 && outer - threeQuarter2 > 0.0)
                {
                    Attenuate((unsigned short)(level3 + (level4 - level3) *
                                                            ((distance - threeQuarter2) / (outer - threeQuarter2))));
                }
                else if (distance > midpointVal && threeQuarter2 - midpointVal > 0.0)
                {
                    Attenuate((unsigned short)(level2 + (level3 - level2) * ((distance - midpointVal) /
                                                                             (threeQuarter2 - midpointVal))));
                }
                else if (distance > quarter && midpointVal - quarter > 0.0)
                {
                    Attenuate((unsigned short)(level1 +
                                               (level2 - level1) * ((distance - quarter) / (midpointVal - quarter))));
                }
                else if (distance > inner && quarter - inner > 0.0)
                {
                    Attenuate((unsigned short)(level0 + (level1 - level0) * ((distance - inner) / (quarter - inner))));
                }
                else
                {
                    Attenuate(0);
                }
            }
            else
            {
                if (distance >= outer)
                {
                    Attenuate(10000);
                }
                else
                {
                    Attenuate(0);
                }
            }
            Refresh(volume);
        }
    }
}

void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);

long __cdecl FUN_00aea180(void* stream, long offset, int whence, int iWhenceArg);

long __cdecl FUN_00af1cf0(void* stream, long offset, int whence, int iWhenceArg);

int __cdecl CloseAndDeleteFile(BSFile* apFile);

long FUN_00aeabf0(void* stream, long offset, int whence, int iOrigin);

void* __cdecl _fnv_zlib_memset(void* p, int c, int n);

void __cdecl FUN_00ec44d0(void*, const void*, unsigned int);

bool HasWildcardChars(const char* pcString);

int __cdecl FUN_00ec3bad(int value);

double FUN_00ecbc80(double);

extern "C" char* __cdecl xStrstr(char* s, const char* sub);

extern "C" void* __cdecl xMemcpy(void* d, const void* s, unsigned int n);

int __cdecl FUN_00ec3bad(int value);

int __cdecl FUN_00ecadb8();

extern void __cdecl FUN_00ec65a6(char*, U32, const char*);

void __cdecl FUN_00aea020();

namespace ListenerDestruction {
struct ListenerBase
{
    virtual ~ListenerBase() = 0;
    int state04, state08, state0c, state10;
    int state14, state18, state1c, state20;
    int state24, state28, state2c, state30;
    int state34, state38, state3c, state40;
    int environment;
};
inline ListenerBase::~ListenerBase()
{
    environment = 0;
}
struct FUN_00aea770 : ListenerBase
{
    IDSBufStub* listener;
// @fnv 0x00aea770
    virtual __declspec(noinline) ~FUN_00aea770()
    {
        if (listener)
        {
            listener->Release();
            listener = 0;
        }
    }
};
void DestroyListener(void* object)
{
    static_cast<FUN_00aea770*>(object)->FUN_00aea770::~FUN_00aea770();
}
}

// Calls FUN_00aea770, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00aeaa80
void* FUN_00aeaa80_Class::FUN_00aeaa80(unsigned int flags)
{
    reinterpret_cast<::ListenerDestruction::FUN_00aea770 *>(this)->ListenerDestruction::FUN_00aea770::~FUN_00aea770();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

#include "generated/data/staging/blk_00ae0000_od.inc"
#include "generated/data/staging/blk_00ae0000_od_ob1_variant.inc"
#include "generated/data/staging/blk_00ae0000_od_ob1_rtm_variant.inc"
