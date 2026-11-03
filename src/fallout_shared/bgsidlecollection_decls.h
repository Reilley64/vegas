// fallout_shared/bgsidlecollection_decls.h: declares TESObjectANIO, TESIdleForm, TESFormInitFlag, Actor
#ifndef FALLOUT_SHARED_BGSIDLECOLLECTION_DECLS_H
#define FALLOUT_SHARED_BGSIDLECOLLECTION_DECLS_H

#include "fnv/decl/FUN_008b2010_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00479000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "TESForm.h"
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
    void SetAt(unsigned int, T&);
    unsigned int Add(T&);
};
#include "bgsidlecollection_types_BGSIdleCollection.h"

class TESObjectANIO : public TESForm
{
};

class TESIdleForm : public TESObjectANIO
{
  public:
    bool IsIdleFile();
    bool IsValidForReferences(TESObjectREFR*, TESObjectREFR*, bool);
};

class TESFormInitFlag
{
  public:
};

extern "C" const char kBGSIdleCollectionMissingIdle[];
extern "C" const char kBGSIdleCollectionMissingAnim[];

class Actor
{
  public:
};
template <int N> struct EndianSizeTag
{
};
void* operator new[](unsigned int);
void operator delete[](void*);
extern "C" void* memset(void*, int, unsigned int);
#endif
