#ifndef TESFACTION_DECLS_H
#define TESFACTION_DECLS_H


#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0048ca90.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
class ReactionInfo
{
  public:
    char data[12];
};
class BGSLoadFormBuffer;
#include "tesfaction_types_TESFaction.h"
#include "tesfaction_types_BGSLoadFormBuffer.h"
#include "tesfaction_types_RANK_DATA.h"
#include "TESReactionForm.h"

class TESDataHandler;

class TESFormBufferAccess : public TESForm
{
  public:
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void Revert(BGSLoadFormBuffer*);
};

class TESReactionFormBufferAccess : public TESReactionForm
{
  public:
    void InitItem(TESForm*);
};

struct TESFactionReactionView
{
    TESForm form;
    TESFullName fullName;
    TESReactionFormBufferAccess reaction;
};


class TESFormInitFlag
{
  public:
};

class TESDataHandlerAccess
{
  public:
};

void* __cdecl Allocate(unsigned int);
class TESFileFormVersion
{
  public:
};
class TESReactionFormLoader
{
  public:
};
class TESFactionRecordLoader
{
  public:
};
#endif
