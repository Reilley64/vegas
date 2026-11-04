// bssystem/filefinder_filefinder_decls.h: declares NiFile, FileFinder, MemoryManager, BSFile, ArchiveManager
#ifndef FNV_FILEFINDER_FILEFINDER_DECLS_H
#define FNV_FILEFINDER_FILEFINDER_DECLS_H
#include <cstddef>

#include "runtime/crt.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00af5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f8000.h"
class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual bool Open(bool, bool);
};

class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NOTFOUND = 0,
        HARDDRIVE = 1,
        ARCHIVE = 2,
        CACHE = 3,
        PC = 4,
        DVD = 5,
        DVDTOHD = 6
    };
    static NiFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
    static FILE_LOCATION __cdecl Exist(const char*, char*, unsigned int, unsigned int);
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
};

class MemoryManager
{
  public:
};
class BSFile : public NiFile
{
  public:
    char storage[340];
    BSFile(const char*, int, unsigned int, bool);
};
class ArchiveManager
{
  public:
};

#endif
