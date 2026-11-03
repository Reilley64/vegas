
// src/gamebryo2.2/corelibs/nisystem/nimemstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nimemstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstring>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00aa1d30_cls.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_011f6000.h"
struct NiBinaryStream
{
};

struct NiMemStream : NiBinaryStream
{
    void FUN_00aa2d70(int iNumBytes);
};

// @fnv 0x00aa2d70
void NiMemStream::FUN_00aa2d70(int iNumBytes)
{
    int iValue = *(unsigned int*)((char*)this + 0x14) + iNumBytes;
    if (iValue >= 0 && iValue < *(unsigned int*)((char*)this + 0x1c))
    {
        *(unsigned int*)((char*)this + 0x14) = (unsigned int)iValue;
        *(unsigned int*)((char*)this + 4) = (unsigned int)iValue;
    }
}


// @fnv 0x00aa2dd0
unsigned int FUN_00aa2dd0(NiMemStream* pThis, void* unused, const void* data, unsigned int numBytes)
{
    if (*(unsigned char*)(pThis + 0x20))
        return 0;

    unsigned int freeSpace = *(unsigned int*)(pThis + 0x1c) - *(unsigned int*)(pThis + 0x14);
    if (numBytes > freeSpace)
    {
        unsigned int oldEnd = *(unsigned int*)(pThis + 0x1c);
        unsigned int oldStart = *(unsigned int*)(pThis + 0x14);
        unsigned int newSize;
        if (numBytes <= oldEnd + freeSpace)
            newSize = oldEnd * 2;
        else
            newSize = (oldEnd - freeSpace) + numBytes;

        void* newBuffer = ::FUN_00aa1070(newSize);
        std::memmove(newBuffer, *(void**)(pThis + 0x10), *(unsigned int*)(pThis + 0x18));
        ::FUN_00aa10f0(*(void**)(pThis + 0x10));
        *(void**)(pThis + 0x10) = newBuffer;
        *(unsigned int*)(pThis + 0x1c) = newSize;
    }

    std::memmove((char*)*(void**)(pThis + 0x10) + *(unsigned int*)(pThis + 0x14), data, numBytes);
    *(unsigned int*)(pThis + 0x14) += numBytes;
    if (*(unsigned int*)(pThis + 0x14) > *(unsigned int*)(pThis + 0x18))
        *(unsigned int*)(pThis + 0x18) = *(unsigned int*)(pThis + 0x14);

    return numBytes;
}

namespace fnv_00aa2e60 {

struct NiMemStream
{
    char pad[0x10];
    char* m_kRayStart;
    unsigned int m_pos;
    unsigned int m_kRayEnd;
};

// Copies up to count bytes from the stream's buffer at m_pos into dest, advances m_pos, and returns the number of bytes copied.
// @fnv 0x00aa2e60
unsigned int FUN_00aa2e60(NiMemStream* stream, void* dest, unsigned int count)
{
    unsigned int available = stream->m_kRayEnd - stream->m_pos;
    if (count > available)
        count = available;
    std::memmove(dest, stream->m_kRayStart + stream->m_pos, count);
    stream->m_pos += count;
    return count;
}
}  // namespace fnv_00aa2e60

// Copies up to uLen bytes from the stream's buffer at its current position into pData, advances the position, and calls SwapBufferBySizes on the data.
// @fnv 0x00aa2ec0
unsigned int __cdecl FUN_00aa2ec0(NiMemStream* pStream, void* apBuffer, unsigned int auiLength, void* apArgA,
                                  void* apArgB)
{
    if (auiLength <= 0)
        return 0;
    unsigned int uiPosition = *(unsigned int*)((char*)pStream + 0x14);
    unsigned int uiAvailable = *(unsigned int*)((char*)pStream + 0x18) - uiPosition;
    unsigned int uiCopied = auiLength;
    if (uiCopied > uiAvailable)
        uiCopied = uiAvailable;
    char* pBufferBase = *(char**)((char*)pStream + 0x10);
    std::memmove(apBuffer, pBufferBase + uiPosition, uiCopied);
    *(unsigned int*)((char*)pStream + 0x14) += uiCopied;
    ::SwapBufferBySizes((char *)(apBuffer), auiLength, (const unsigned int *)(apArgA), (uintptr_t)(apArgB));
    return uiCopied;
}

struct S_00aa2dd0
{
};
// Copies uSize bytes from pSrc into a temporary buffer, passes it to SwapBufferBySizes, writes it to pStream, frees the buffer and returns the write result.
// @fnv 0x00aa2f20
unsigned int __cdecl FUN_00aa2f20(NiMemStream* pStream, const void* pSrc, uintptr_t uSize, void* pA, void* pB)
{
    if (uSize <= 0)
        return 0;
    void* pBuffer = ::FUN_00aa1070(uSize);
    std::memmove(pBuffer, pSrc, uSize);
    ::SwapBufferBySizes((char *)(pBuffer), uSize, (const unsigned int *)(pA), (uintptr_t)(pB));
    unsigned int uRet = ::FUN_00aa2dd0((::NiMemStream *)(((S_00aa2dd0*)pStream)), (void *)(pBuffer), (const void *)(uSize), {});
    ::FUN_00aa10f0(pBuffer);
    return uRet;
}

namespace fnv_00aa2f80 {

struct NiMemStream
{
    char pad[8];
    void (*m_read)(void*);
    void (*m_write)(void*);
    void SetSwapMode(bool bDoSwap);
};

// Assigns the read and write function pointers based on bDoSwap, choosing one pair of handlers or the other.
// @fnv 0x00aa2f80
void NiMemStream::SetSwapMode(bool bDoSwap)
{
    if (bDoSwap)
    {
        m_read = ((void (&)(void *))::FUN_00aa2ec0);
        m_write = ((void (&)(void *))::FUN_00aa2f20);
    }
    else
    {
        m_read = ((void (&)(void *))::fnv_00aa2e60::FUN_00aa2e60);
        m_write = ((void (&)(void *))::FUN_00aa2ea0);
    }
}
}  // namespace fnv_00aa2f80

unsigned int FUN_00aa2dd0(NiMemStream* pThis, void* unused, const void* data, unsigned int numBytes);
unsigned int __cdecl FUN_00aa2ec0(NiMemStream* pStream, void* pData, unsigned int uLen, void* pA, void* pB);

unsigned int __cdecl FUN_00aa2f20(NiMemStream* pStream, const void* pSrc, uintptr_t uSize, void* pA, void* pB);

// @fnv 0x00aa2ea0
void __cdecl FUN_00aa2ea0(S_00aa2dd0* pThis, const void* pData, uintptr_t uLen)
{
    ::FUN_00aa2dd0((::NiMemStream *)(pThis), (void *)(pData), (const void *)(uLen), {});
}

struct NiAlloc
{
};

struct FUN_00aa2d90 : NiBinaryStream
{
    void* unk04;
    void* unk08;
    void* unk0c;
    void* buffer;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned char flag20;
    unsigned char flag21;

    virtual ~FUN_00aa2d90();
};

// When both flags are zero, passes buffer to FUN_00aa10f0, then calls FUN_00aa1d30.
// @fnv 0x00aa2d90
FUN_00aa2d90::~FUN_00aa2d90()
{
    if (!flag20 && !flag21)
    {
        FUN_00aa10f0(buffer);
    }
    reinterpret_cast<::FUN_00aa1d30_cls *>(this)->FUN_00aa1d30();
}
