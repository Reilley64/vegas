// fallout/misc/saveload/bgssaveloadhistory_decls.h: declares BGSSaveLoadHistoryNoteLocals, BGSSaveLoadChangesMap, BGSLoadFormBuffer, BGSLoadGameBuffer
#ifndef BGSSAVELOADHISTORY_DECLS_H
#define BGSSAVELOADHISTORY_DECLS_H


#include <cstdint>
#include "fnv/decl/FUN_00864740_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/symbols_00407000.h"
void FUN_0084c2a0(unsigned int first, unsigned int second, unsigned char flags);

class INISettingCollection;
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};

class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    unsigned int Add(NavMeshInfo*& item);
};

struct BGSSaveLoadHistoryNoteLocals
{
    char* allocation;
    char* note;
    char buffer[1024];
};

class InventoryStackRecord;
template <class T> class BSSimpleList;
template <> class BSSimpleList<InventoryStackRecord*>
{
  public:
    void RemoveAll();
};

class FormChangeRecord;
class BGSSaveLoadChangesMap
{
  public:
    FormChangeRecord* FUN_009a4250(uintptr_t);
};
class ActorCause;
template <> class BSSimpleList<ActorCause*>
{
  public:
    void RemoveAll();
};
struct BGSLoadFormBuffer
{
  public:
};
struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    void** vtable;
    char* data;
    unsigned int size;
    unsigned int position;
};
#endif
