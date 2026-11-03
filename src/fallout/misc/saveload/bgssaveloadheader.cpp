// fallout/misc/saveload/bgssaveloadheader.cpp: free functions (4 functions)

#include <windows.h>
#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_004381b0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00846330_shell.h"
#include "fnv/decl/FUN_00846490_t.h"
#include "fnv/decl/FUN_0084ff90_shell.h"
#include "fnv/decl/FUN_00851bf0_shell.h"
#include "fnv/decl/FUN_00864740_shell.h"
#include "fnv/decl/FUN_00865c40_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/MgrStandIn851.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkCapsuleShape.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_008646f0__FUN_008646f0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004f3000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_00878000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "bgssaveloadheader_decls.h"

struct SaveContentDescriptor
{
    unsigned long DeviceID;
    unsigned long dwContentType;
    char szDisplayName[256];
    char szFileName[42];
    char _pad_132[2];
};
struct FUN_00850030_shell : public BGSSaveLoadManager
{
    SaveLoadFile* FUN_00850030(char*, bool, int, int);
};


// @fnv 0x00850030
SaveLoadFile* FUN_00850030_shell::FUN_00850030(char* apFileName, bool abWrite, int aeBufferType, int aiDeviceID)
{
    unsigned int ibufferSize;
    SaveLoadFile* pfile;
    char pfullFileName[260];

    reinterpret_cast<::FUN_0084ff90_shell *>(this)->BuildWeaponPath(apFileName, pfullFileName, abWrite);

    if (aeBufferType == 0)
        ibufferSize = 0x10000;
    else if (aeBufferType == 1)
        ibufferSize = 0x200000;
    else
        ibufferSize = 0x10000;

    if (abWrite)
    {
        if (fnv::crt::access(pfullFileName, 0) != -1)
            DeleteFileA(pfullFileName);
    }

    pfile = (SaveLoadFile*)((void *)(::FUN_00846520(pfullFileName, abWrite, ibufferSize)));
    ((BGSLoadGameBuffer*)pfile)->FUN_008464f0((SaveLoadFile*)apFileName);
    ::FUN_008463c0((::UnknownOwner008463c0 *)(((BGSLoadGameBuffer*)pfile)));

    return pfile;
}


struct LGB : public BGSLoadGameBuffer
{
    LGB();
    ~LGB();
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
    unsigned int iVersion;
};

// @fnv 0x0084d8c0
int __cdecl ReadSaveHeader(SaveLoadFile* apFile)
{
    BGSLoadGameBuffer* apLoadGameBuffer;
    int iversion;
    unsigned int iresult;
    char pheaderString[260];
    pheaderString[0] = 0;
    std::memset(&pheaderString[1], 0, sizeof(pheaderString) - 1);
    iresult = apFile->Read(pheaderString, strlen(DAT_011a2224));
    if (iresult == 0)
        return 0;
    if (FUN_00408b20(pheaderString, DAT_011a2224))
        return -1;

    LGB loadBuffer;
    reinterpret_cast<::FUN_00864740_shell *>(&(loadBuffer))->ReadAndVerifySize(apFile);
    apLoadGameBuffer = &loadBuffer;
    iversion = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iversion), 4);
    if (iversion == 0x30)
    {
        char* pdata4 = ((char *)(::GetCombinedValue((int)(apLoadGameBuffer))));
        if (pdata4[4] == '|')
        {
        }
        else
        {
            char lname[64];
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(lname), 0x40);
        }
    }
    else
    {
        char lname[64];
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(lname), 0x40);
    }
    unsigned int iscreenshotWidth2 = 0;
    unsigned int iscreenshotHeight = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iscreenshotWidth2), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iscreenshotHeight), 4);
    reinterpret_cast<::FUN_00846490_t *>((apFile))->AdvancePosition(iscreenshotWidth2 * iscreenshotHeight * 3);
    return iversion;
}

struct HeaderFile
{
};
struct HeaderBuffer
{
    void* data;
    unsigned int unk04, unk08, unk0C, unk10;
    HeaderBuffer();
    ~HeaderBuffer();
};
struct HeaderManager
{
};
struct HeaderPlayer
{
};
struct HeaderSetting
{
    unsigned char* FUN_00408d60();
};
struct HeaderPixels
{
    virtual ~HeaderPixels();
};
int FUN_00406d50(char*, unsigned int, const char*);
// @fnv 0x0084d4b0
void FUN_0084d4b0(HeaderFile* file)
{
    reinterpret_cast<::FUN_00846330_shell *>((file))->WriteToFile(DAT_011a2224, strlen(DAT_011a2224));
    HeaderBuffer buffer_;
    HeaderBuffer* stream = &buffer_;
    unsigned int version = reinterpret_cast<::bhkCapsuleShape *>(((*reinterpret_cast<::HeaderManager * *>(&::DAT_011de134))))->FUN_0066d730();
    reinterpret_cast<::FUN_00865e50_shell *>((stream))->FUN_00865e50((void *)(&version), 4, false);
    char playerName3[64];
    ::FUN_00403d30(playerName3, 0, 64);
    FUN_00406d50(playerName3, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HeaderSetting *>(&::g_011c3cb4))))->GetMenuTitle())));
    reinterpret_cast<::FUN_00865e50_shell *>((stream))->FUN_00865e50((void *)(playerName3), 64, false);
    bool wide6 = (double)FUN_004dc200() / ((int)(::FUN_004dc1f0())) < 0.75;
    int height5 = wide6 ? 512 : 432;
    int width2 = wide6 ? 512 : 432;
    char screenshotPath_2[260];
    screenshotPath_2[0] = 0;
    std::memset(screenshotPath_2 + 1, 0, 259);
    if (*(*reinterpret_cast<::HeaderSetting *>(&::g_011de2fc)).FUN_00408d60())
    {
        ::TaskQueueInterface::CopyStringToBuffer(screenshotPath_2, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HeaderSetting *>(&::g_011c3f74))))->GetMenuTitle())));
        FUN_00406d50(screenshotPath_2, 260, ((const char *)(static_cast<void *>(file))));
        FUN_00406d50(screenshotPath_2, 260, ".bmp");
    }
    HeaderPixels* pixels = 0;
    if (!((bool)(reinterpret_cast<::FUN_00424940_shell *>(((*reinterpret_cast<::HeaderManager * *>(&::DAT_011de134))))->FUN_00424940())))
        pixels = ((::HeaderPixels *)(::FUN_00878f60(&height5, &width2, screenshotPath_2)));
    else
    {
        float aspect3 = (double)FUN_004dc200() / ((int)(::FUN_004dc1f0()));
        width2 = (int)(width2 * aspect3);
    }
    reinterpret_cast<::FUN_00865e50_shell *>((stream))->FUN_00865e50((void *)(&height5), 4, false);
    reinterpret_cast<::FUN_00865e50_shell *>((stream))->FUN_00865e50((void *)(&width2), 4, false);
    unsigned int numberVal = reinterpret_cast<::BGSSaveLoadManager *>(::DAT_011de134)->m_uiSaveLoadSubstate;
    reinterpret_cast<::FUN_00865e50_shell *>((stream))->FUN_00865e50((void *)(&numberVal), 4, false);
    reinterpret_cast<::FUN_00865e70_shell *>((stream))->FUN_00865e70(reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::HeaderPlayer * *>(&::_g_thePlayer))))->FUN_0055d520(), false);
    reinterpret_cast<::FUN_00865e70_shell *>((stream))->FUN_00865e70(::FUN_0047e0e0((::Actor *)((*reinterpret_cast<::HeaderPlayer * *>(&::_g_thePlayer)))), false);
    unsigned int level2 = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::HeaderPlayer * *>(&::_g_thePlayer))))->FUN_0087f9f0();
    reinterpret_cast<::FUN_00865e50_shell *>((stream))->FUN_00865e50((void *)(&level2), 4, false);
    char location9[260];
    reinterpret_cast<::MgrStandIn851 *>(((*reinterpret_cast<::HeaderManager * *>(&::DAT_011de134))))->CopyPlayerName(location9);
    reinterpret_cast<::FUN_00865e70_shell *>((stream))->FUN_00865e70(location9, false);
    char time[260];
    reinterpret_cast<::FUN_00851bf0_shell *>(((*reinterpret_cast<::HeaderManager * *>(&::DAT_011de134))))->FormatPlayTime(time, true);
    reinterpret_cast<::FUN_00865e70_shell *>((stream))->FUN_00865e70(time, false);
    reinterpret_cast<::FUN_00865c40_shell *>(&(buffer_))->FUN_00865c40((::FUN_00846330_shell *)(file));
    if (!((bool)(reinterpret_cast<::FUN_00424940_shell *>(((*reinterpret_cast<::HeaderManager * *>(&::DAT_011de134))))->FUN_00424940())))
        reinterpret_cast<::FUN_00846330_shell *>((file))->WriteToFile(((void *)(reinterpret_cast<::S_0064dac0 *>((pixels))->FUN_0064dac0(0, 0))), height5 * width2 * 3);
    else
        reinterpret_cast<::FUN_00846330_shell *>((file))->WriteToFile(0, height5 * width2 * 3);
    delete pixels;
}

class NiPixelFormat
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
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
};


class ScreenshotPixelData : public NiMemObject
{
  public:
    ScreenshotPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format, unsigned int mipmapLevels,
                        unsigned int faces);
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
};

struct ScreenshotTexFormat
{
    ScreenshotTexFormat();
    int iPixelLayout;
    int iAlphaFormat;
    int iMipMapped;
};

struct ScreenshotName
{
    ScreenshotName(const char* str);
    ~ScreenshotName();
    operator const char*() const;
    const char* pString;
};


// Seeks to offset in file, reads width*height*3 bytes into a new ScreenshotPixelData, and creates a texture named BGSSaveLoadHeader_Screenshot.
// @fnv 0x0084dda0
NiTexture* __cdecl LoadScreenshotTexture(SaveLoadFile* file, unsigned int offset, unsigned int width,
                                         unsigned int height)
{
    file->SetFilePosition(offset);
    NiPixelFormat format = ::DAT_011aa2e8;
    ScreenshotPixelData* pixelData2 = new ScreenshotPixelData(width, height, format, 1, 1);
    file->Read(((void *)(reinterpret_cast<::S_0064dac0 *>((pixelData2))->FUN_0064dac0(0, 0))), width * height * 3);
    ScreenshotTexFormat aTexFormat;
    aTexFormat.iPixelLayout = 2;
    aTexFormat.iMipMapped = 0;
    aTexFormat.iAlphaFormat = 0;
    ScreenshotName textureName("BGSSaveLoadHeader_Screenshot");
    return ((::NiTexture *)(::fnv_00a5ff10::FUN_00a5ff10((::fnv_00a5ff10::RefCounted *)(pixelData2), (void *)(textureName.pString), (const ::fnv_00a5ff10::OwnerTriple *)(::ScreenshotTexFormat *)(&aTexFormat))));
}

#include "generated/data/fallout/misc/saveload/bgssaveloadheader.inc"
