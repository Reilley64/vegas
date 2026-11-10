#include "AutoMemContext.h"
// fallout/interface/fadermanager_update_decls.h: declares AutoMemContext, TimeGlobal, TileShaderProperty
#ifndef FADERMANAGER_UPDATE_DECLS_H
#define FADERMANAGER_UPDATE_DECLS_H

// Private declarations for the fader update's out-of-line helpers.
#include "fnv/decl/FUN_00821600_shell.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/symbols_011f6000.h"
enum MEM_CONTEXT
{
    MEM_CONTEXT_INTERFACE = 13
};
using ::AutoMemContext;
class TimeGlobal
{
  public:
};
class NiTexture;
class NiTexture;
class TileShaderProperty : public NiMemObject
{
  public:
    unsigned char layout[176];
    TileShaderProperty(bool);
public:
    void FUN_00bb7a10(::NiTexture *);
};
#endif
