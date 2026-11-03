// fallout_shared/bgsdebris_decls.h: declares FileEntryList, DebrisModelEntry, ModelLoader
#ifndef BGSDEBRIS_DECLS_H
#define BGSDEBRIS_DECLS_H

#include "fnv/decl/C4442C0Queue.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011c3000.h"
#include "bgsdebris_types_BGSDebris.h"
class FileEntryList
{
  public:
    unsigned int fields[2];
    FileEntryList();
    ~FileEntryList();
    void Load(TESFile*, TESForm*, const char*);
};
extern const char DAT_01024988[];
extern "C" void* _alloca(unsigned int);
class DebrisModelEntry
{
  public:
    char chance, flags;
    short pad;
    char* path;
    FileEntryList model;
    DebrisModelEntry();
    ~DebrisModelEntry();
};
void* Allocate(unsigned int);
template <class T> unsigned int BSStringLength(const T*);
class ModelLoader
{
  public:
};
#endif
