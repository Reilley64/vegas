// bssystem/filefinder.cpp: FileFinder, Loader_S (12 functions)

#include <windows.h>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00446dc0_Class.h"
#include "fnv/decl/FUN_00b01bc0_class.h"
#include "fnv/decl/FUN_00b01be0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00af5000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afe000.h"
#include "fnv/symbols_00b01000.h"
#include "fnv/symbols_011a2000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f8000.h"
#include "fnv/symbols_01202000.h"
#include "filefinder_filefinder_decls.h"

// Returns the file location from g_fileFinder's lookup for fileName, or NOTFOUND when g_fileFinder is null.
// @fnv 0x00456a20
FileFinder::FILE_LOCATION __cdecl FileFinder::Exist(const char* fileName, char* filePath, unsigned int flags,
                                                    unsigned int archiveType)
{
    FILE_LOCATION result;
    if (g_fileFinder)
        result = g_fileFinder->GetFileLocation((char*)fileName, filePath, flags, archiveType);
    else
        result = NOTFOUND;
    return result;
}

// Resolves name through g_fileFinder and returns a BSFile or archive file for the given mode, buffer size and archive type, or null.
// @fnv 0x00afdf20
NiFile* FileFinder::GetFile(const char* name, NiFile::OpenMode mode, unsigned int bufferSize, unsigned int archiveType)
{
    // These local identifiers preserve MSVC9 stack-slot ordering.
    bool bFileFound;
    FILE_LOCATION pFile;     // Location returned by GetFileLocation.
    NiFile* pInputFile = 0;  // Resulting file stream.
    char cFileName[780];
    if (g_fileFinder)
    {
        if (mode == 1)
        {
            pInputFile = new BSFile(name, mode, bufferSize, false);
        }
        else
        {
            pFile = g_fileFinder->GetFileLocation((char*)name, cFileName, 0, archiveType);
            bFileFound = false;
            if (pFile != NOTFOUND)
            {
                if (pFile == ARCHIVE)
                {
                    if (!pInputFile)
                        pInputFile = ((::NiFile *)(::fnv_00af5fa0::LoadFileFromArchives(cFileName, bufferSize, archiveType)));
                    else
                        bFileFound = true;
                }
                else
                {
                    pInputFile = new BSFile(cFileName, mode, bufferSize, false);
                    pInputFile->Open(false, false);
                }
            }
        }
    }
    return pInputFile;
}

struct FUN_00afe220_shell : public FileFinder
{
    int FUN_00afe220(char*, unsigned int, unsigned int);
};
// @fnv 0x00afe0d0
FileFinder::FILE_LOCATION FileFinder::GetFileLocation(char* fileName, char* filePath, unsigned int flags,
                                                      unsigned int archiveType)
{
    char path[260];
    char unused[4];
    FILE_LOCATION result;

    if (archiveType == 0xffffffff)
        archiveType = 0xffff;
    unused[0] = 0;
    result = NOTFOUND;

    if (fileName[1] == ':')
    {
        flags |= 5;
    }
    else if (fileName[0] == '.' && fileName[1] == '\\')
    {
        flags |= 4;
        fileName += 2;
    }

    if (fileName[0] == '\\')
        fnv::crt::strcpy_s(path, 260, fileName + 1);
    else
        fnv::crt::strcpy_s(path, 260, fileName);

    result = (FILE_LOCATION)((unsigned int)(reinterpret_cast<::FUN_00afe220_shell *>(this)->FUN_00afe220(path, flags, archiveType)));
    if (result == NOTFOUND)
    {
        if (filePath)
            filePath[0] = 0;
    }
    else if (filePath)
    {
        fnv::crt::strcpy_s(filePath, 260, path);
    }
    return result;
}

bool __cdecl FUN_00af6320(int, int);
struct PathArr_S
{
    void* pVtbl;
    const char** pData;
    unsigned int uiSize;
    __forceinline unsigned int GetSize() const
    {
        unsigned int r = uiSize;
        return r;
    }
};
__forceinline unsigned int StrLenFI(const char* s)
{
    unsigned int n = std::strlen(s);
    return n;
}
struct FinderCalls_S
{
};

// @fnv 0x00afe220
int FUN_00afe220_shell::FUN_00afe220(char* apFilePath, unsigned int aiFlags, unsigned int aiArchiveType)
{
    char acFullPath[260];
    if (!(aiFlags & 1) && FUN_00af6320((int)apFilePath, aiArchiveType))
        return 2;
    if (!DAT_011acdf8 || DAT_011acdf9)
        aiFlags = 0;
    if (reinterpret_cast<::FUN_00b01bc0_class *>((reinterpret_cast<FinderCalls_S*>(this)))->IsFlag2Clear(aiFlags, aiArchiveType) &&
        fnv::crt::access(apFilePath, 0) != -1)
        return 1;
    if (reinterpret_cast<::FUN_00b01be0_Class *>((reinterpret_cast<FinderCalls_S*>(this)))->IsFlag4Clear(aiFlags, aiArchiveType))
    {
        unsigned int uiPathCount = reinterpret_cast<PathArr_S*>(this)->GetSize();
        for (unsigned int uiIndex = 0; uiIndex < uiPathCount; uiIndex++)
        {
            const char* pcPrefix = reinterpret_cast<PathArr_S*>(this)->pData[uiIndex];
            if (pcPrefix && fnv::crt::strnicmp(apFilePath, pcPrefix, StrLenFI(pcPrefix)))
            {
                fnv::crt::strcpy_s(acFullPath, 0x104, pcPrefix);
                fnv::crt::strcat_s(acFullPath, 0x104, apFilePath);
                if (fnv::crt::access(acFullPath, 0) != -1)
                {
                    fnv::crt::strcpy_s(apFilePath, 0x104, acFullPath);
                    return 1;
                }
            }
        }
    }
    return 0;
}

struct IOManager_S
{
    int CallInnerF3();
};
struct OSGlobals_S
{
};
extern bool DAT_011c3bfc;
struct Loader_S
{
    int CallVirtual17();
    void UpdateLoadingStatus();
};

// @fnv 0x00446cb0
void Loader_S::UpdateLoadingStatus()
{
    if (!((bool)(::FUN_00446e10())))
    {
        int iPost = CallVirtual17();
        int iRefs = reinterpret_cast<::FUN_00446dc0_Class *>(this)->FUN_00446dc0();
        int iBackground = ((int)(reinterpret_cast<::NiAVObject *>(((*reinterpret_cast<::IOManager_S * *>(&::DAT_01202d98))))->GetParentNode()));
        int iTasks = (*reinterpret_cast<::IOManager_S * *>(&::DAT_01202d98))->CallInnerF3();
        if (iBackground || iRefs || iPost || iTasks)
        {
            char buffer[260];
            ::FUN_00406d00(buffer, 0x104,
                       "Loading %d references( %d background cloning ) and %d tasks( %d post processing )", iPost,
                       iRefs, iBackground, iTasks);
            DAT_011c3bfc = true;
        }
        else if (DAT_011c3bfc)
        {
            DAT_011c3bfc = false;
            SetWindowTextA(((void *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::OSGlobals_S * *>(&::g_osGlobals))))->GetName())), ::_DAT_011a2fe8);
        }
    }
}

struct FUN_00afe1f0_shell : public FileFinder
{
    unsigned int FindFile(char*, unsigned int);
};

// @fnv 0x00afe1f0
unsigned int FUN_00afe1f0_shell::FindFile(char* pcPath, unsigned int uiFlags)
{
    return ((unsigned int)(reinterpret_cast<::FUN_00afe220_shell *>((this))->FUN_00afe220(pcPath, uiFlags, 0xffff)));
}


// @fnv 0x00afe400
int __cdecl FUN_00afe400(int a2, int a1)
{
    return ((int)(::FUN_00afe420((const char *)(a2), (const char *)(a1), 0xffff, (::FileMatchList *)(0))));
}


// @fnv 0x00afe590
int __cdecl FUN_00afe590(int a1, int a2, int a3)
{
    return ((int)(::FUN_00afe420((const char *)(a1), (const char *)(a2), 0xffffu, (::FileMatchList *)(a3))));
}

struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};
struct FileFinderHack
{
};
// @fnv 0x00afe7b0
bool __cdecl FUN_00afe7b0(char const* a, _FILETIME& b)
{
    return ::fnv_00afe7d0::FUN_00afe7d0(a, (::fnv_00afe7d0::_FILETIME &)(b), 0xffff);
}

namespace fnv_00afe7d0 {
struct _FILETIME
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};
struct FileEntryTmp
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual const char* f6();
};
// @fnv 0x00afe7d0
bool __cdecl FUN_00afe7d0(const char* apFileName, _FILETIME& arFileTime, unsigned int aiMode)
{
    std::memset(&arFileTime, 0, 8);
    FileEntryTmp* pkEntry = ((::fnv_00afe7d0::FileEntryTmp *)(::fnv_00af6160::FindArchiveForFile(apFileName, aiMode)));
    if (pkEntry)
        apFileName = pkEntry->f6();
    return ::FUN_00b01b60(apFileName, (::DirFileTime *)(::fnv_00afe7d0::_FILETIME *)(&arFileTime));
}
}  // namespace fnv_00afe7d0

inline void DeadQ6()
{
    int a[6];
}
class Actor;
struct MM
{
};
bool __cdecl FUN_00b01af0(const char*);
void __cdecl strcat_s(char*, unsigned int, const char*);
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList()
    {
        m_item = 0;
        m_pkNext = 0;
    }
    ~BSSimpleList()
    {
        RemoveAll();
    }
    void AddHead(T const& item);
    void RemoveAll();
    bool IsEmpty()
    {
        return (m_pkNext == 0 && m_item == 0) ? 1 : 0;
    }
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>((((MM*)&::g_memoryManager)))->FUN_00aa4060(p);
    }
};
inline void* __cdecl operator new[](unsigned int n)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(n);
}
inline void CopyQ(char* d, const char* s, unsigned int n)
{
    std::memmove(d, s, n);
}
inline void CatQ(char* d, unsigned int n, const char* s)
{
    strcat_s(d, n, s);
}
// Validates a path and name, builds a combined string, adds it to a BSSimpleList, and returns the list or null if empty.
// @fnv 0x00afe5b0
BSSimpleList<Actor*>* __cdecl FUN_00afe5b0(const char* path, const char* name, int x, BSSimpleList<Actor*>* apList)
{
    BSSimpleList<Actor*>* list7 = apList;
    if (!list7)
        list7 = new BSSimpleList<Actor*>;
    bool ok = false;
    if (!DAT_011acdf8 || DAT_011acdf9)
        ok = FUN_00b01af0(path);
    if (!ok)
        ok = FUN_00af6320((int)path, x);
    if (ok)
    {
        unsigned int len5 = strlen(name);
        const char* s6 = strrchr(name, '\\');
        const char* sA = strrchr(path, '\\');
        if (s6 && sA)
        {
            len5 -= strlen(s6 + 1);
            unsigned int total = len5 + strlen(sA + 1) + 1;
            char* buf = new char[total];
            CopyQ(buf, name, len5);
            buf[len5] = 0;
            CatQ(buf, total, sA + 1);
            list7->AddHead((Actor* const&)buf);
        }
    }
    if (list7->IsEmpty())
    {
        delete list7;
        list7 = 0;
    }
    DeadQ6();
    return list7;
}

struct FinderMemory : MemoryManager
{
};
struct FileMatchList
{
    void* data;
    FileMatchList* next;
    FileMatchList()
    {
        data = 0;
        next = 0;
    }
    ~FileMatchList()
    {
        RemoveAll();
    }
    void RemoveAll()
    {
        while (next)
        {
            FileMatchList* following = next->next;
            next->next = 0;
            delete next;
            next = following;
        }
        data = 0;
    }
    bool IsEmpty() const
    {
        return next == 0 && data == 0;
    }
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
    static void operator delete(void* object)
    {
        reinterpret_cast<::FNV_MemoryManager *>((static_cast<FinderMemory*>(&::g_memoryManager)))->FUN_00aa4060(object);
    }
};
// Finds files matching a pattern in a directory, using wildcards or exact match, and returns a list of matches.
// @fnv 0x00afe420
FileMatchList* FUN_00afe420(const char* pattern, const char* directory, unsigned int flags, FileMatchList* existing)
{
    if (!pattern || !directory)
        return 0;
    if (!strstr(pattern, "*") && !strstr(pattern, "?"))
        return ((::FileMatchList *)(::FUN_00afe5b0(pattern, directory, flags, (::BSSimpleList< ::Actor *> *)(existing))));
    FileMatchList* matches = existing;
    if (!matches)
        matches = new FileMatchList;
    if (!DAT_011acdf8 || DAT_011acdf9)
        ::CollectDirectoryEntries(pattern, directory, (::BSSimpleList<char *> *)(matches));
    ::FUN_00af6ba0((::LNode *)(matches), pattern, directory, flags);
    if (matches->IsEmpty())
    {
        delete matches;
        matches = 0;
    }
    return matches;
}

#include "generated/data/bssystem/filefinder.inc"
