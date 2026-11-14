// tesobjectarmo_load.h: declares TESFileFormVersion, TESFullNameLoader, TESObjectARMOOldBipedModel, TESObjectARMOOldData
#ifndef TESOBJECTARMO_LOAD_H
#define TESOBJECTARMO_LOAD_H
#include <cstring>
#include <malloc.h>
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00512810_holder.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/symbols_00487000.h"
#include "TESFile.h"
class TESFileFormVersion
{
  public:
};
class TESFileChunkData16
{
  public:
};
class TESFullNameLoader
{
  public:
};
class TESTexture1024
{
  public:
};
// Legacy formats retained for records written before the current armor layout.
struct TESObjectARMOOldBipedModel
{
    unsigned short slots;
    unsigned char flags;
};
struct TESObjectARMOOldData
{
    unsigned short rating;
};
#endif
