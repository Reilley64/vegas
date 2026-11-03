// fallout/misc/saveload/bgssaveloadfile.cpp: BGSSaveLoadFileEntry, SaveLoadFile, BGSSaveLoadManager (23 functions)

#include <windows.h>
#include <new>
#include <cstdio>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_0084ff90_shell.h"
#include "fnv/decl/FUN_00850030_shell.h"
#include "fnv/decl/FUN_00850360_class.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/SaveManager.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011de000.h"
#include "bgssaveloadfile_types_BGSSaveLoadFile.h"
#include "bgssaveloadfile_types_BGSSaveLoadFileEntry.h"
#include "bgssaveloadfile_types_BGSSaveLoadManager.h"
#include "bgssaveloadfile_types_BGSSaveLoadHeader.h"
#include "bgssaveloadfile_types_NiTexture.h"
#include "MemoryManager.h"

class BSFile
{
  public:
    char opaque[0x158];
    BSFile(const char*, int, unsigned int, bool);
};

class FNVFileSeek
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void Seek(int, int);
};


void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
template <class T> unsigned int __cdecl BSStringLength(const T*);

// @fnv 0x00846b10
bool BGSSaveLoadFileEntry::IsAutoSave()
{
    return ::DAT_011de134->IsAutoSaveFileName(pFileName);
}

// @fnv 0x00846b30
bool BGSSaveLoadFileEntry::IsSaveEntryValid()
{
    if (m_bSaveEntryValid)
        return true;
    ReadTypedData();
    return m_bSaveEntryValid;
}

// Forwards a read of size bytes into buffer to the object's pFile stream and returns the result.
// @fnv 0x00846300
unsigned int SaveLoadFile::Read(void* buffer, unsigned int size)
{
    return reinterpret_cast<::FUN_00462d80_shell *>((pFile))->ReadBytes(buffer, size);
}

// @fnv 0x00846400
unsigned int SaveLoadFile::GetFilePosition()
{
    if (((bool)(reinterpret_cast<::FUN_00424940_shell *>((::DAT_011de134))->FUN_00424940())))
        return m_uiFilePosition;
    return ((unsigned int)(::FUN_004720a0((char *)(pFile))));
}

// @fnv 0x00846440
void SaveLoadFile::SetFilePosition(int position)
{
    if (((bool)(reinterpret_cast<::FUN_00424940_shell *>((::DAT_011de134))->FUN_00424940())))
        m_uiFilePosition = position;
    else
        ((FNVFileSeek*)pFile)->Seek(position, DAT_010a2480);
}

// @fnv 0x00846820
NiTexture* BGSSaveLoadFileEntry::ReadScreenshotFromFile()
{
    NiTexture* screenshot = 0;
    void* header = ((void *)(reinterpret_cast<::FUN_00850030_shell *>((::DAT_011de134))->FUN_00850030((char *)(pFileName), 0, 0, m_iScreenshotOffset)));
    if (!header)
        return 0;
    if (!m_bHeaderParsed)
    {
        ReadSaveFileHeader(header, this);
        if (!m_uiHeaderRecordValue && !m_uiFileSize)
            m_bSaveEntryValid = true;
        if (!pLocation)
            m_bSaveEntryValid = true;
        m_bHeaderParsed = true;
    }
    if (m_uiHeaderRecordValue && m_uiFileSize)
        screenshot =
            ::LoadScreenshotTexture((::SaveLoadFile *)(::SaveLoadHeader *)((SaveLoadHeader*)header), SaveFileMetadata, m_uiHeaderRecordValue, m_uiFileSize);
    ::DAT_011de134->FUN_00850100((SaveLoadHeader*)header, 0);
    return screenshot;
}

// @fnv 0x008461e0
SaveLoadFile::SaveLoadFile(const char* fileName, bool flag, unsigned int size)
{
    pFile = 0;
    m_uiBufferSize = 0;
    m_uiFilePosition = 0;
    m_cFileName[0] = 0;
    if (!((bool)(reinterpret_cast<::FUN_00424940_shell *>((::DAT_011de134))->FUN_00424940())))
        pFile = new BSFile(fileName, flag ? 1 : 0, size, false);
}

// @fnv 0x00846900
void BGSSaveLoadFileEntry::ReadTypedData()
{
    if (m_bHeaderParsed || m_bSaveEntryValid)
        return;
    void* header = ((void *)(reinterpret_cast<::FUN_00850030_shell *>((::DAT_011de134))->FUN_00850030((char *)(pFileName), 0, 1, m_iScreenshotOffset)));
    if (!header)
    {
        m_bSaveEntryValid = true;
        return;
    }
    ReadSaveFileHeader(header, this);
    if (!m_uiHeaderRecordValue && !m_uiFileSize)
        m_bSaveEntryValid = true;
    if (!pLocation)
        m_bSaveEntryValid = true;
    if (::DAT_011de134->IsSaveFileNameCustom(pFileName))
    {
        char* location = pLocation;
        ::FUN_00401030(location);
        unsigned int length = ::FUN_0044a670(pFileName) + 1;
        char* pAllocatedPath = (char*)::FUN_00401000(length);
        pLocation = pAllocatedPath;
        TaskQueueInterface::CopyStringToBuffer(pLocation, length, pFileName);
    }
    ::DAT_011de134->FUN_00850100((SaveLoadHeader*)header, 0);
    m_bHeaderParsed = true;
}

struct VDestruct008462c0
{
    virtual ~VDestruct008462c0();
};

// Deletes the VDestruct008462c0 object stored at offset 0x104 of pThis.
// @fnv 0x008462c0
void FUN_008462c0(char* pThis)
{
    delete *reinterpret_cast<VDestruct008462c0**>(pThis + 0x104);
}

class UnknownVtbl008463c0
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool vfn_20(int, int);
};

struct UnknownOwner008463c0
{
    char pad[0x104];
    UnknownVtbl008463c0* unk104;
};

// @fnv 0x008463c0
bool FUN_008463c0(UnknownOwner008463c0* _this)
{
    if (((bool)(reinterpret_cast<::FUN_00424940_shell *>((::DAT_011de134))->FUN_00424940())))
        return true;
    return _this->unk104->vfn_20(0, 0);
}


struct FUN_00846490_t
{
    char pad_000[0x104];
    FNVFileSeek* file;
    int unk_108;
    int pos_10c;
    void AdvancePosition(int offset);
};

// If DAT_011de134->FUN_00424940() is true, adds offset to pos_10c; otherwise seeks file by offset using DAT_010a2484.
// @fnv 0x00846490
void FUN_00846490_t::AdvancePosition(int offset)
{
    if (((bool)(reinterpret_cast<::FUN_00424940_shell *>((::DAT_011de134))->FUN_00424940())))
    {
        pos_10c += offset;
    }
    else
    {
        file->Seek(offset, DAT_010a2484);
    }
}

struct FUN_008464f0_arg
{
    const char* str;
};

// @fnv 0x008464f0
void FUN_008464f0(char* pThis, FUN_008464f0_arg aStringArg)
{
    TaskQueueInterface::CopyStringToBuffer(pThis, 0x104, aStringArg.str);
}

// Allocates and constructs a new object from a name string, a bool flag and an unsigned int value, returning the new instance.
// @fnv 0x00846520
SaveLoadFile* __cdecl FUN_00846520(const char* apName, bool abFlag, unsigned int auiValue)
{
    return new SaveLoadFile(apName, abFlag, auiValue);
}

// Deletes the objects stored at indices 0, 6, 5, 3 and 4 of the array pointed to by pThis.
// @fnv 0x00846690
void FUN_00846690(void** pThis)
{
    delete pThis[0];
    delete pThis[6];
    delete pThis[5];
    delete pThis[3];
    delete pThis[4];
}

struct FUN_008467b0_shell : public BGSSaveLoadFileEntry
{
    bool LoadSaveEntry();
};

struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
};

// @fnv 0x008467b0
bool FUN_008467b0_shell::LoadSaveEntry()
{
    return reinterpret_cast<::BGSSaveLoadManager *>((((BGSSaveLoadManager_ext*)::DAT_011de134)))->LoadGame(*(const char**)this, this->m_iScreenshotOffset, false, false);
}

namespace fnv_00846a20 {
struct _FILETIME_
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};

struct _WIN32_FIND_DATAA_
{
    unsigned int dwFileAttributes;
    _FILETIME_ ftCreationTime;
    _FILETIME_ ftLastAccessTime;
    _FILETIME_ ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};


struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
};

// @fnv 0x00846a20
void UpdateFileWriteTime(char* pThis)
{
    if (*(unsigned int*)(pThis + 0x30) == 0 && *(unsigned int*)(pThis + 0x2c) == 0)
    {
        char path[260];
        _WIN32_FIND_DATAA_ findData;
        reinterpret_cast<::FUN_0084ff90_shell *>((((BGSSaveLoadManager_ext*)::DAT_011de134)))->BuildWeaponPath(*(char**)pThis, path, false);
        void* hFind = FindFirstFileA(path, &findData);
        if (hFind != (void*)-1)
        {
            *(_FILETIME_*)(pThis + 0x2c) = findData.ftLastWriteTime;
        }
        FindClose(hFind);
    }
}
}  // namespace fnv_00846a20

namespace fnv_00846ad0 {
struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
};

// @fnv 0x00846ad0
bool FUN_00846ad0(const char** pThis)
{
    return reinterpret_cast<::BGSSaveLoadManager *>((((BGSSaveLoadManager_ext*)::DAT_011de134)))->IsQuickSaveFileName(*pThis);
}
}  // namespace fnv_00846ad0

namespace fnv_00846af0 {
struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
};

// @fnv 0x00846af0
bool IsLegacyAutosaveFileName(const char** apFileName)
{
    return reinterpret_cast<::BGSSaveLoadManager *>((((BGSSaveLoadManager_ext*)::DAT_011de134)))->IsSaveFileNameLegacyAutosave(*apFileName);
}
}  // namespace fnv_00846af0

struct MemoryManagerStatic
{
};
struct FUN_008465b0_stub
{
    char* name;
    char f4;
    char f5;
    int f8, fc, f10, f14, f18, f1c, f20, f24, f28;
    char blk[8];
    int f34;
    FUN_008465b0_stub(const char* src, int p);
};
// Zeroes the fields, stores p in f34, allocates a buffer for src, copies src into name, and clears blk.
// @fnv 0x008465b0
FUN_008465b0_stub::FUN_008465b0_stub(const char* pcName, int p)
{
    f4 = 0;
    f5 = 0;
    f8 = 0;
    fc = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f34 = p;
    ::FUN_00403d30(blk, 0, 8);
    unsigned int len = std::strlen(pcName);
    char* buf = (char*)::FUN_00401000(len + 1);
    name = buf;
    ::TaskQueueInterface::CopyStringToBuffer(name, len + 1, pcName);
}

struct FUN_00473180_shell
{
public:
    unsigned int FUN_00473180(void *, unsigned int);
};
struct FUN_00846330_shell
{
    unsigned int WriteToFile(const void* apBuffer, unsigned int aiBytes);
};
// @fnv 0x00846330
unsigned int FUN_00846330_shell::WriteToFile(const void* apBuffer, unsigned int aiBytes)
{
    if (((bool)(reinterpret_cast<::FUN_00424940_shell *>((::DAT_011de134))->FUN_00424940())))
    {
        unsigned int ifileSizePositionDiff =
            *(unsigned int*)((char*)this + 0x108) - *(unsigned int*)((char*)this + 0x10c);
        if (aiBytes > ifileSizePositionDiff)
            *(unsigned int*)((char*)this + 0x108) += aiBytes - ifileSizePositionDiff;
        *(unsigned int*)((char*)this + 0x10c) += aiBytes;
        return aiBytes;
    }
    return ((FUN_00473180_shell*)(*(char**)((char*)this + 0x104)))->FUN_00473180((void *)((const char*)apBuffer), aiBytes);
}

struct FUN_00846710_mgr_view
{
};

struct FUN_00846710_cls : public BGSSaveLoadFileEntry
{
    bool FUN_00846710();
};

class C8467E0Event;

class C8467E0Manager
{
  public:
};


class C8467E0Event
{
  public:
    unsigned int m_uiType;
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
    int m_iData;

    void DispatchEvent();
};
// @fnv 0x00846710
bool FUN_00846710_cls::FUN_00846710()
{
    if (reinterpret_cast<::BGSSaveLoadManager *>((reinterpret_cast<FUN_00846710_mgr_view*>(::DAT_011de134)))->IsSaveFileNameDefault(pFileName) ||
        reinterpret_cast<::BGSSaveLoadManager *>((reinterpret_cast<FUN_00846710_mgr_view*>(::DAT_011de134)))->IsSaveFileNameLegacyAutosave(pFileName))
    {
        if (reinterpret_cast<::SaveManager *>((reinterpret_cast<FUN_00846710_mgr_view*>(::DAT_011de134)))->FUN_008503b0(0, m_iScreenshotOffset, 0))
        {
            reinterpret_cast<::C8467E0Event *>(this)->DispatchEvent();
            return true;
        }
    }
    else
    {
        if (reinterpret_cast<::SaveManager *>((reinterpret_cast<FUN_00846710_mgr_view*>(::DAT_011de134)))->FUN_008503b0(pFileName, m_iScreenshotOffset, 0))
        {
            reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00846710_mgr_view*>(::DAT_011de134)))->RemoveAndDelete((::FUN_008515f0 *)(void *)(this));
            return true;
        }
    }
    return false;
}

// @fnv 0x008467e0
void C8467E0Event::DispatchEvent()
{
    reinterpret_cast<::FUN_00850360_class *>(((*reinterpret_cast<::C8467E0Manager * *>(&::DAT_011de134))))->DeleteWeaponFile((char *)(m_uiType), m_iData);
    reinterpret_cast<::Holder *>(((*reinterpret_cast<::C8467E0Manager * *>(&::DAT_011de134))))->RemoveAndDelete((::FUN_008515f0 *)(::C8467E0Event *)(this));
}

struct FUN_00850330_class
{
    char* FUN_00850330(unsigned int);
};
struct GlobalObject_0045cfe0
{
};
int __cdecl strcat_s(char*, unsigned int, const char*);
struct MgrShell
{
};
struct FUN_006815c0_Class
{
};

// Builds successive .bak paths, deletes an existing destination, and calls FUN_00ec862c with source and destination paths.
// @fnv 0x00850100
void BGSSaveLoadManager::FUN_00850100(SaveLoadHeader* header, int abRotate)
{
    FUN_00850330_class* p2;
    FUN_00850330_class* p1;
    int inner4;
    char bufD_[260];
    char _bufE[260];
    int count2;
    char bufB[260];
    char bufC4[260];
    char bufA3[260];
    char* filename9;

    filename9 = (char*)((void *)(new ((void *)(((FUN_006815c0_Class*)header))) ::Vec3()));
    ::TaskQueueInterface::CopyStringToBuffer(bufA3, 260, filename9);
    p1 = (FUN_00850330_class*)header;
    p2 = p1;
    (p2 ? p2->FUN_00850330(1) : (char*)0);
    if (*(unsigned char*)&abRotate)
    {
        reinterpret_cast<::FUN_0084ff90_shell *>((((MgrShell*)this)))->BuildWeaponPath(bufA3, bufB, *(unsigned char*)&abRotate);
        ::TaskQueueInterface::CopyStringToBuffer(bufC4, 260, bufB);
        bufC4[::FUN_0044a670(bufC4) - 4] = 0;
        for (count2 = *((int *)&(::FUN_0043d4d0((int *)&(::g_011de2c8)))) - 1; count2 >= 0; count2--)
        {
            ::TaskQueueInterface::CopyStringToBuffer(bufD_, 260, bufC4);
            for (inner4 = 0; inner4 < count2; inner4++)
                strcat_s(bufD_, 260, ".bak");
            ::TaskQueueInterface::CopyStringToBuffer(_bufE, 260, bufD_);
            strcat_s(_bufE, 260, ".bak");
            if (fnv::crt::access(bufD_, 0) != -1)
            {
                if (fnv::crt::access(_bufE, 0) != -1)
                    DeleteFileA(_bufE);
                std::rename(bufD_, _bufE);
            }
        }
        std::rename(bufB, bufC4);
        ::TaskQueueInterface::CopyStringToBuffer(bufB, 260, bufC4);
    }
}
