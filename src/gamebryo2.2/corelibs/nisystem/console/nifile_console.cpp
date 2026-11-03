// gamebryo2.2/corelibs/nisystem/console/nifile_console.cpp: NiFile, NiBinaryStream (9 functions)

#include <windows.h>
#include <cstdio>
#include "runtime/crt.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FileTransferCallbacks.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_011f6000.h"
#include "nifile_console.h"
#include "fnv/symbols_011f8000.h"

// Destructor: if the file is good and open, flushes and closes m_pFile, then frees m_pBuffer.
// @fnv 0x00aa1690
NiFile::~NiFile()
{
    if (m_bGood && m_pFile)
    {
        Flush();
        std::fclose((std::FILE *)(m_pFile));
    }
    ::FUN_00aa10f0(m_pBuffer);
}

// @fnv 0x00aa15a0
bool NiFile::Flush()
{
    if (m_eMode == READ_ONLY)
        m_uiBufferReadSize = 0;
    else if (m_uiPos > 0)
    {
        char* buffer = m_pBuffer;
        FILE* file = m_pFile;
        if (WriteBytesToFile(buffer, 1, m_uiPos, file) != m_uiPos)
        {
            m_bGood = false;
            return false;
        }
    }
    m_uiPos = 0;
    return true;
}

// Unmatched reconstruction retained for the next pass. See NOTES.md.
unsigned int NiBinaryStream::GetLine(char* buffer, unsigned int maxChars)
{
    unsigned int total = 0;
    unsigned int position = 0;
    while (position + 1 < maxChars)
    {
        char ch;
        unsigned int size = 1;
        unsigned int read = m_pfnRead(this, &ch, 1, &size, 1);
        m_uiStreamFlags += read;
        total += read;
        if (read == 1)
        {
            if (ch == '\n')
                break;
            if (ch != '\r')
                buffer[position++] = ch;
        }
        else
            break;
    }
    buffer[position] = 0;
    return total;
}

struct S_00aa15f0
{
    unsigned char _pad[0x24];
    void* _f;
    int GetFileSize();
};
// @fnv 0x00aa15f0
int S_00aa15f0::GetFileSize()
{
    int cur = std::ftell((std::FILE *)(_f));
    if (cur < 0)
        return 0;
    std::fseek((std::FILE *)(_f), 0, 2);
    int len = std::ftell((std::FILE *)(_f));
    std::fseek((std::FILE *)(_f), cur, 0);
    return len < 0 ? 0 : len;
}

// FUN_00aa14d0 : NiFile constructor (name, open mode, buffer size).
// Installs the NiFile vtable, opens the file with fopen-style mode string
// selected from the open mode, records good/bad and allocates a read buffer.

extern int DAT_010a2490;
extern const char kModeReadBinary[];

typedef struct _iobuf FILE;


struct NiBinaryStreamBase
{
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    void* m_pfnWrite;
    NiBinaryStreamBase();
    virtual void vFirst();
};

struct FUN_00aa14d0_cls : NiBinaryStreamBase
{
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
    unsigned int m_uiTotalFileSize;
    char* m_pBuffer;
    FILE* m_pFile;
    unsigned int m_eMode;
    unsigned char m_bGood;

    FUN_00aa14d0_cls(const char* name, unsigned int mode, unsigned int bufSize);
};

// @fnv 0x00aa14d0
FUN_00aa14d0_cls::FUN_00aa14d0_cls(const char* name, unsigned int mode, unsigned int bufSize)
{
    reinterpret_cast<::FileTransferCallbacks *>(this)->FUN_00aa1b30(0);
    m_uiTotalFileSize = 0;
    m_eMode = mode;
    const char* openMode;
    if (mode == 0)
        openMode = kModeReadBinary;
    else if (mode == 1)
        openMode = (*reinterpret_cast<const char (*)[]>((void *)&::DAT_0106e798));
    else
        openMode = "ab";
    int bOpened = (fnv::crt::fopen_s((std::FILE **)(&m_pFile), name, openMode) == 0 && m_pFile != 0) ? 1 : 0;
    m_bGood = (unsigned char)bOpened;
    m_uiBufferAllocSize = bufSize;
    m_uiBufferReadSize = 0;
    m_uiPos = 0;
    if ((unsigned char)bOpened != 0 && bufSize > 0)
        m_pBuffer = (char*)FUN_00aa1070(bufSize);
    else
        m_pBuffer = 0;
}


// @fnv 0x00aa1670
bool __cdecl IsDirectory(const char* pcPath)
{
    unsigned long uiAttributes = GetFileAttributesA(pcPath);
    if (uiAttributes == 0xffffffff)
        return false;
    return (uiAttributes & 0x10) != 0;
}


struct FUN_00aa16d0_cls : NiFile
{
    void FUN_00aa16d0(unsigned int offset, unsigned int whence);
};

// Seeks the file: advances within the read buffer when possible, otherwise flushes and calls the underlying seek, updating position and good flag.
// @fnv 0x00aa16d0
void FUN_00aa16d0_cls::FUN_00aa16d0(unsigned int offset, unsigned int whence)
{
    if (!m_bGood)
    {
        return;
    }
    if (whence == 1)
    {
        unsigned int newPos = m_uiPos + offset;
        if ((int)newPos >= 0 && (int)newPos < (int)m_uiBufferReadSize)
        {
            m_uiStreamFlags += offset;
            m_uiPos = newPos;
            return;
        }
        if (m_eMode == READ_ONLY)
        {
            offset += m_uiPos - m_uiBufferReadSize;
        }
    }
    Flush();
    m_bGood = ((int)(::NiFile::RequestFileAccess((const char *)(m_pFile), offset, whence))) == 0;
    if (m_bGood)
    {
        m_uiTotalFileSize = std::ftell((std::FILE *)(m_pFile));
        m_uiStreamFlags = m_uiTotalFileSize;
    }
}

class AA1F10BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(AA1F10BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(AA1F10BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 1;
        return BinaryRead(pvBuffer, uiBytes, &uiSize, 1);
    }

    unsigned int ReadLine(char* pcBuffer, unsigned int uiMaxBytes);
};

// @fnv 0x00aa1f10
unsigned int AA1F10BinaryStream::ReadLine(char* pcLineBuffer, unsigned int uiMaxBytes)
{
    unsigned int uiBytesRead = 0;
    unsigned int i = 0;
    while (i + 1 < uiMaxBytes)
    {
        char c;
        unsigned int uiRead = Read(&c, 1);
        uiBytesRead += uiRead;
        if (uiRead != 1 || c == '\n')
            break;
        if (c != '\r')
            pcLineBuffer[i++] = c;
    }
    pcLineBuffer[i] = 0;
    return uiBytesRead;
}

#include <windows.h>
// @fnv 0x00aa1650
unsigned char __cdecl FUN_00aa1650(char* path)
{
    return CreateDirectoryA(path, 0) != 0;
}

struct P03MM
{
};
struct NiFileFlushExposer : NiFile
{
    bool CallFlush()
    {
        return Flush();
    }
};
struct FUN_00aa18c0 : NiBinaryStream
{
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
    unsigned int m_uiTotalFileSize;
    char* m_pBuffer;
    FILE* m_pFile;
    NiFile::OpenMode m_eMode;
    bool m_bGood;
    virtual ~FUN_00aa18c0();
};
// When m_bGood and m_pFile are set, flushes and closes the file, then frees m_pBuffer.
// @fnv 0x00aa18c0
FUN_00aa18c0::~FUN_00aa18c0()
{
    if (m_bGood && m_pFile)
    {
        ((NiFileFlushExposer*)(void*)this)->CallFlush();
        std::fclose((std::FILE *)(m_pFile));
    }
    ::FUN_00aa10f0(m_pBuffer);
}


struct MersenneTwister
{
    int _0;
    int _4;
    char _8[0x9C0];
    int _9C8;
    void FUN_00aa5170(unsigned int);
    void Seed(unsigned int);
};
// @fnv 0x00aa5170
void MersenneTwister::FUN_00aa5170(unsigned int a)
{
    _4 = 0;
    _9C8 = 0x271;
    Seed(a);
}


struct ArchiveManager
{
    void* FUN_00afe0d0(const char* name, unsigned int a, unsigned int b, unsigned int c);
};


class FileStream
{
  public:
    virtual ~FileStream();
    virtual operator bool() const;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    char* unk20;
    FILE* unk24;
    int unk28;
    bool unk2C;
    FileStream(const char* name, int mode, unsigned int bufferSize);
};

// @fnv 0x00afde50
bool FUN_00afde50(const char* name, int mode)
{
    if (mode == 0)
    {
        return (*reinterpret_cast<::ArchiveManager * *>(&::g_fileFinder)) ? (*reinterpret_cast<::ArchiveManager * *>(&::g_fileFinder))->FUN_00afe0d0(name, 0, 0, 0xffffffff) : 0;
    }
    FileStream kFile(name, mode, 0);
    return kFile;
}
#include "generated/data/gamebryo2.2/corelibs/nisystem/console/nifile_console.inc"
