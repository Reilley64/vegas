// gamebryo2.2/corelibs/nimain/niimageconverter.cpp: NiImageConverter, ImageOwner (17 functions)

#include <cstdint>
#include <windows.h>
#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A8Class.h"
#include "fnv/decl/FUN_00a7c030.h"
#include "fnv/decl/FUN_00a8ae50.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiPixelFormat.h"
#include "fnv/decl/NiRefObject.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/fnv_00aa2820__FileNameComponents.h"
#include "fnv/symbols_00a76000.h"
#include "fnv/symbols_00a8b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "niimageconverter_worker.h"

// @fnv 0x00a76640
NiImageConverter* NiImageConverter::GetSharedImageConverter()
{
    return DAT_011f4a7c;
}

struct NiRefObject2
{
    virtual ~NiRefObject2();
    virtual void DeleteThis();
    long refs;
    NiRefObject2() throw()
    {
        refs = 0;
        InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
};
struct Sub80
{
};
struct BSFadeNode
{
    static void* operator new(size_t) throw();
};
struct NiImageConverter2 : NiRefObject2
{
    char pad[0x78];
    Sub80 s;
    char pad2[0x6ff];
    NiImageConverter2() throw()
    {
        new ((void *)&(s)) ::FUN_00a8ae50();
    }
    void* operator new(size_t n)
    {
        return BSFadeNode::operator new(n);
    }
};
inline void Rel(NiRefObject2* o)
{
    if (!InterlockedDecrement(&o->refs))
        o->DeleteThis();
}
// Allocates a NiImageConverter2, releases the previous global converter, stores the new one in DAT_011f4a7c and increments its reference count.
// @fnv 0x00a76ab0
void CreateImageConverter()
{
    NiRefObject2* p = new NiImageConverter2();
    if ((NiRefObject2*)DAT_011f4a7c != p)
    {
        if (DAT_011f4a7c)
            Rel((NiRefObject2*)DAT_011f4a7c);
        DAT_011f4a7c = (NiImageConverter*)p;
        if (p)
            InterlockedIncrement(&p->refs);
    }
}

struct NiFile;
struct NiImageReader;
struct NiPixelData;
struct NiPixelFormat;
struct NiStream;
struct blob68
{
    char b[68];
};

struct VTable_FUN_00a76d40
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual bool v20(const NiPixelFormat&) const;
    virtual bool v24(const NiPixelFormat&) const;
};

// @fnv 0x00a76d40
bool FUN_00a76d40(const VTable_FUN_00a76d40* pThis, int, const NiPixelFormat& kSrcFmt)
{
    if (pThis->v20(kSrcFmt) || pThis->v24(kSrcFmt))
        return true;
    return false;
}

namespace fnv_00a76650 {
struct Sub80
{
};
struct NiRefObject
{
    unsigned int m_uiRefCount;
    NiRefObject() : m_uiRefCount(0)
    {
        InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
    virtual ~NiRefObject();
};
struct FUN_00a76650 : NiRefObject
{
    FUN_00a76650();
    virtual ~FUN_00a76650();
};
// Constructs the object and calls FUN_00a8ae50 on the Sub80 subobject at offset 0x80.
// @fnv 0x00a76650
FUN_00a76650::FUN_00a76650()
{
    new ((void *)(((Sub80*)((char*)this + 0x80)))) ::FUN_00a8ae50();
}
}  // namespace fnv_00a76650

namespace fnv_00a76680 {
struct Sub80
{
};
struct NiRefObject
{
    unsigned int m_uiRefCount;
    virtual ~NiRefObject()
    {
        InterlockedDecrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
};
struct FUN_00a76680 : NiRefObject
{
    virtual ~FUN_00a76680();
};
// Frees the global DAT_011f4a78, clears it, then calls FUN_00a8ada0 on the sub-object at offset 0x80.
// @fnv 0x00a76680
FUN_00a76680::~FUN_00a76680()
{
    if ((*reinterpret_cast<void * *>(&::DAT_011f4a78)))
        ::FUN_00aa10f0((*reinterpret_cast<void * *>(&::DAT_011f4a78)));
    (*reinterpret_cast<void * *>(&::DAT_011f4a78)) = 0;
    reinterpret_cast<::A8Class *>((((Sub80*)((char*)this + 0x80))))->FUN_00a8ada0();
}
}  // namespace fnv_00a76680

struct FUN_00a76890_eq
{
    bool operator==(const NiPixelFormat&) const;
};

// @fnv 0x00a76890
bool ArePixelFormatsEqual(void* apFormatA, void* apFormatB)
{
    NiPixelFormat& a = *(NiPixelFormat*)apFormatA;
    NiPixelFormat& b = *(NiPixelFormat*)apFormatB;
    return reinterpret_cast<::NiPixelFormat *>((void *)&((*(FUN_00a76890_eq*)&a)))->operator==(b);
}

namespace fnv_00a76960 {
struct FileNameComponents
{
    FileNameComponents(const char* pcFullPath);
    char m_acHead[0x303];
    char m_acTail[0x100];
};
struct NiGlobalStringTable
{
};
// @fnv 0x00a76960
void FUN_00a76960(char** apszSource, char** apszDest)
{
    if (::DAT_011f4a78)
    {
        FileNameComponents kName(*apszSource);
        fnv::crt::strcpy_s(kName.m_acTail, 0x100, ::DAT_011f4a78);
        char acBuf[0x104];
        ::FUN_00aa29d0();
        char* pcOldString = *apszDest;
        if (pcOldString != acBuf)
        {
            *apszDest = ::NiGlobalStringTable::AddString(acBuf);
            if (pcOldString != ::DAT_0109b220)
                InterlockedDecrement((long volatile*)(pcOldString - 8));
        }
    }
    else
    {
        char* pcNewString = *apszSource;
        if (*apszDest != pcNewString)
        {
            if (pcNewString != ::DAT_0109b220)
                InterlockedIncrement((long volatile*)(pcNewString - 8));
            if (*apszDest != ::DAT_0109b220)
                InterlockedDecrement((long volatile*)(*apszDest - 8));
            *apszDest = pcNewString;
        }
    }
}
}  // namespace fnv_00a76960

namespace fnv_00a76b30 {
struct RefObj
{
    virtual void Unk0();
    virtual void Unk1();
    long m_refs;
    void DecRef()
    {
        if (!InterlockedDecrement(&m_refs))
            Unk1();
    }
};
// If the global RefObj pointer DAT_011f4a7c is set, decrements its reference count and clears the pointer.
// @fnv 0x00a76b30
void FUN_00a76b30()
{
    if (DAT_011f4a7c)
    {
        ((RefObj*)DAT_011f4a7c)->DecRef();
        DAT_011f4a7c = 0;
    }
}
}  // namespace fnv_00a76b30

namespace fnv_00a76b60 {
struct RefObj
{
    virtual void Unk0();
    virtual void Unk1();
    long m_refs;
    void AcquireReference()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRef()
    {
        if (!InterlockedDecrement(&m_refs))
            Unk1();
    }
};
// Replaces the global image converter pointer, releasing the previous reference and incrementing the new one's reference count.
// @fnv 0x00a76b60
void AssignImageConverter(NiImageConverter* conv)
{
    RefObj* p = (RefObj*)conv;
    if ((RefObj*)DAT_011f4a7c != p)
    {
        if (DAT_011f4a7c)
            ((RefObj*)DAT_011f4a7c)->DecRef();
        DAT_011f4a7c = conv;
        if (p)
            p->AcquireReference();
    }
}
}  // namespace fnv_00a76b60

namespace fnv_00a76c10 {
struct NiPixelData;
struct NiStream;
struct blob68
{
    char b[68];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct NiPixelFormat
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    static struct blob68 BuildPixelFormat(unsigned char, unsigned int, unsigned int, unsigned int, unsigned int);
    int GetFormat();
    unsigned char GetBitsPerPixel();
    unsigned int GetRendererHint();
    unsigned int GetExtraData();
    int GetTiling();
    bool GetLittleEndian();
    void SetFormat(int);
    void SetBitsPerPixel(unsigned char);
    void SetRendererHint(unsigned int);
    void SetExtraData(unsigned int);
    void SetTiling(int);
    void SetLittleEndian(bool);
    bool GetComponent(unsigned int, int*, int*, unsigned char*, bool*);
    void SetComponent(unsigned int, int, int, unsigned char, bool);
    unsigned int GetNumComponents();
    bool GetPalettized();
    bool GetPaletteHasAlpha();
    bool GetCompressed();
    unsigned int GetMask(int);
    unsigned char GetPixelBitData(int);
    unsigned char GetShift(int);
    unsigned char QBitsPerPixel();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void InitPixelFormat(int, unsigned char, int, bool, unsigned int, int, int, unsigned char, bool, int, int,
                         unsigned char, bool, int, int, unsigned char, bool, int, int, unsigned char, bool);
    void SetComponentFormat(int, unsigned char, unsigned int*);
    static unsigned int CalcMaskSize(unsigned int);
    unsigned char m_uiObjectFlags;
    unsigned char m_ucBitsPerPixel;
    char _pad_2[2];
    int m_eFormat;
    int m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    char m_akComponents[48];
};
struct FUN_00a76c10_shell : public NiImageConverter
{
    NiPixelData* FUN_00a76c10(void*, void*, NiPixelData*, bool);
};

struct BSFadeNode
{
    static void* __cdecl operator new(size_t size);
};
struct PixelFormatOps
{
    bool operator==(const NiPixelFormat& other) const;
    bool operator!=(const NiPixelFormat& other) const;
};
struct NiPalette
{
    char data[0x24];
    NiPalette(const NiPalette& other);
    static void* operator new(size_t, void* p)
    {
        return p;
    }
};
struct NiPixelData
{
    char base[8];
    NiPixelFormat m_kPixelFormat;
    NiPalette* m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    char tail[0x10];
    NiPalette* GetPalette() const
    {
        return m_spPalette;
    }
};

// @fnv 0x00a76c10
NiPixelData* FUN_00a76c10_shell::FUN_00a76c10(void* src, void* apDestFmt, NiPixelData* pkOptDest, bool bMipmap)
{
    const NiPixelData& kSrc = *(const NiPixelData*)src;
    const NiPixelFormat& kDestFmt = *(const NiPixelFormat*)apDestFmt;
    if (reinterpret_cast<::NiPixelFormat *>((void *)(((const PixelFormatOps*)&kSrc.m_kPixelFormat)))->operator!=((const ::NiPixelFormat &)(kDestFmt)))
        return 0;
    if (pkOptDest)
    {
        if (pkOptDest == &kSrc)
            return pkOptDest;
        if (reinterpret_cast<::NiPixelFormat *>((void *)(((const PixelFormatOps*)&pkOptDest->m_kPixelFormat)))->operator==((const ::NiPixelFormat &)(kDestFmt)) &&
            *pkOptDest->m_puiWidth == *kSrc.m_puiWidth && *pkOptDest->m_puiHeight == *kSrc.m_puiHeight &&
            pkOptDest->m_uiMipmapLevels <= kSrc.m_uiMipmapLevels)
        {
            unsigned int uiMaxLevel = pkOptDest->m_uiMipmapLevels;
            for (unsigned int uiMip = 0; uiMip < uiMaxLevel; uiMip++)
            {
                std::memmove(pkOptDest->m_pucPixels + pkOptDest->m_puiOffsetInBytes[uiMip],
                         kSrc.m_pucPixels + kSrc.m_puiOffsetInBytes[uiMip],
                         kSrc.m_puiOffsetInBytes[uiMip + 1] - kSrc.m_puiOffsetInBytes[uiMip]);
            }
            if (kSrc.m_spPalette)
            {
                if (!pkOptDest->m_spPalette)
                {
                    void* pal = BSFadeNode::operator new(0x24);
                    reinterpret_cast<::Owner *>((pkOptDest))->FUN_00a76a60((::Item *)(::fnv_00a76c10::NiPalette *)(pal ? new (pal) NiPalette(*kSrc.GetPalette()) : 0));
                }
                else
                    ::FUN_00a8b190((::MyObj *)(pkOptDest->m_spPalette), (void *)&(*kSrc.m_spPalette), {});
            }
            return pkOptDest;
        }
    }
    void* pNewPixelData = BSFadeNode::operator new(0x74);
    return pNewPixelData ? ((::fnv_00a76c10::NiPixelData *)(new ((void *)(((NiPixelData*)pNewPixelData))) ::FUN_00a7c030((const ::FUN_00a7c030 &)(kSrc)))) : 0;
}
}  // namespace fnv_00a76c10

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };

    virtual ~NiFile();
    virtual operator bool() const;

    static NiFile* GetFile(const char* pcName, OpenMode eMode, unsigned int uiBufferSize);
};

struct FUN_00aa27d0
{
    FUN_00aa27d0(const char* pcPath);

    char m_acPrefix[0x103];
    char m_acPath[0x301];
};

class Loader766
{
  public:
    virtual void v00();
    virtual bool CanLoad(const char* pcPath);
    virtual void v02();
    virtual bool Load(NiFile* pkFile, void* p4, void* p5, void* p2, void* p3, void* p6);
};

class Owner766
{
  public:
    bool LoadFile(const char* pcFile, void* p2, void* p3, void* p4, void* p5, void* p6);

    char pad[0x80];
    Loader766 m_kLoader;
};

// Builds a path from pcFile, checks the loader can load it, opens the file read-only, and delegates to the loader's Load, deleting the file handle.
// @fnv 0x00a766d0
bool Owner766::LoadFile(const char* pcFile, void* p2, void* p3, void* p4, void* p5, void* p6)
{
    FUN_00aa27d0 kPath(pcFile);
    if (!m_kLoader.CanLoad(kPath.m_acPath))
        return false;
    NiFile* pkFile = NiFile::GetFile(pcFile, NiFile::READ_ONLY, 0x8000);
    if (!pkFile)
        return false;
    if (*pkFile)
    {
        if (m_kLoader.Load(pkFile, p4, p5, p2, p3, p6))
        {
            delete pkFile;
            return true;
        }
        delete pkFile;
        return false;
    }
    delete pkFile;
    return false;
}

struct Fmt
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShift[4];
    unsigned char m_aucBits[4];
};
static inline unsigned short Chan(unsigned int p, const Fmt* s, const Fmt* d, int c)
{
    unsigned char v = (unsigned char)((p & s->m_auiMask[c]) >> s->m_aucShift[c]);
    v = (unsigned char)(v << s->m_aucBits[c]);
    v = (unsigned char)(v >> d->m_aucBits[c]);
    return (unsigned short)((unsigned short)v << d->m_aucShift[c]) & (unsigned short)d->m_auiMask[c];
}
// Converts each 16-bit source pixel to the destination format by remapping its four channels through Chan and OR-ing them together.
// @fnv 0x00a76d70
void FUN_00a76d70(unsigned int uiWidth, unsigned int uiHeight, unsigned int, unsigned char* pucDst, uintptr_t,
                  const Fmt* pDstFmt, const unsigned char* pucSrc, const Fmt* pSrcFmt)
{
    const unsigned short* pSrcPixels = (const unsigned short*)pucSrc;
    unsigned short* pDstPixels = (unsigned short*)pucDst;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pDstPixels++ = Chan(*pSrcPixels, pSrcFmt, pDstFmt, 1) | Chan(*pSrcPixels, pSrcFmt, pDstFmt, 0) |
                            Chan(*pSrcPixels, pSrcFmt, pDstFmt, 2) | Chan(*pSrcPixels, pSrcFmt, pDstFmt, 3);
            pSrcPixels++;
        }
    }
}

struct NiPalette;
struct PixelFormatBitLayout;

// @fnv 0x00a76e90
void __cdecl FUN_00a76e90(unsigned int a, unsigned int b, unsigned int c, unsigned char* d, NiPalette const* e,
                          PixelFormatBitLayout const& f, unsigned char const* g, PixelFormatBitLayout const& h)
{
    ::FUN_00a76d70(a, b, c, d, (uintptr_t)(e), (const ::Fmt *)&(f), g, (const ::Fmt *)&(h));
}


// @fnv 0x00aa29d0
void __cdecl FUN_00aa29d0(void)
{
    static_cast<::fnv_00aa2820::FileNameComponents *>(nullptr)->BuildFullPath({}, {});
}

#include <string.h>

struct FileNameComponents
{
    char m_acFullPath[256];
    char m_acDriveLetter[3];
    char m_acFolderPath[256];
    char m_acBaseName[256];
    char m_acExtension[256];

    FileNameComponents(const char* pcPath);
    void SetExt(const char* pcExt)
    {
        fnv::crt::strcpy_s(m_acExtension, 0x100, pcExt);
    }
};

// Populates a buffer from pcPath, setting its extension from DAT_011f4a78 when that value is non-null.
// @fnv 0x00a768b0
char* GetPathWithExtension(const char* pcPath)
{
    char* pcDest = (char*)::FUN_00aa1070(0x104);
    if (DAT_011f4a78)
    {
        FileNameComponents kFilename(pcPath);
        kFilename.SetExt(DAT_011f4a78);
        ::FUN_00aa29d0();
    }
    else
    {
        fnv::crt::strncpy_s(pcDest, 0x104, pcPath, strlen(pcPath));
    }
    return pcDest;
}

namespace fnv_00a76bb0 {
struct Sub80
{
};
struct NiRefObject
{
    unsigned int m_uiRefCount;
    virtual ~NiRefObject()
    {
        InterlockedDecrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
};
struct FUN_00a76bb0 : NiRefObject
{
    char m_data[0x778];
    virtual ~FUN_00a76bb0();
    static void operator delete(void*, size_t);
};
// Frees and clears DAT_011f4a78, then calls FUN_00a8ada0 on the subobject at offset 0x80.
// @fnv 0x00a76bb0
FUN_00a76bb0::~FUN_00a76bb0()
{
    if ((*reinterpret_cast<void * *>(&::DAT_011f4a78)))
        ::FUN_00aa10f0((*reinterpret_cast<void * *>(&::DAT_011f4a78)));
    (*reinterpret_cast<void * *>(&::DAT_011f4a78)) = 0;
    reinterpret_cast<::A8Class *>((((Sub80*)((char*)this + 0x80))))->FUN_00a8ada0();
}
}  // namespace fnv_00a76bb0

struct ImageResult;
struct PathParts
{
    char directory[256];
    char drive[3];
    char extension[256];
    char filename[256];
    char platform[256];
    PathParts(const char*);
    const char* Ext() const
    {
        return extension;
    }
};
struct InputFile
{
    virtual ~InputFile();
    virtual operator bool() const;
    static InputFile* __cdecl FUN_00aa1a20(const char*, int, unsigned);
};
struct ImageLoader
{
    virtual ~ImageLoader();
    virtual bool Supports(const char*) const;
    virtual ImageResult* Read(InputFile&, ImageResult*);
};

struct ImageOwner
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
    ImageLoader loader;
    ImageResult* LoadImage(const char* name, ImageResult* destination, InputFile* supplied);
};
// Loads an image from a file path using the loader, returning the result or null on failure.
// @fnv 0x00a767c0
ImageResult* ImageOwner::LoadImage(const char* apPath, ImageResult* destination, InputFile* apInputFile)
{

    PathParts pathParts(apPath);
    if (loader.Supports(pathParts.Ext()))
    {
        InputFile* pInputFile = apInputFile ? apInputFile : InputFile::FUN_00aa1a20(apPath, 0, 32768);
        if (!pInputFile || !*pInputFile)
        {
            delete pInputFile;
            return 0;
        }
        ImageResult* result = loader.Read(*pInputFile, destination);
        if (result)
        {
            delete pInputFile;
            return result;
        }
        delete pInputFile;
    }
    else
    {
        delete apInputFile;
    }
    return 0;
}

#include "generated/data/gamebryo2.2/corelibs/nimain/niimageconverter.inc"
