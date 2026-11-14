// fallout_shared/region system/tesregion_load.h: declares TESFile, TESRegionDataManager, TESRegionLoadHandler, TESRegionLoadList
#ifndef TESREGION_LOAD_H
#define TESREGION_LOAD_H

#include <malloc.h>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_011c3000.h"
class TESFile
{
  public:
    bool GetChunkData(unsigned int*);
    bool NextChunk();
};
class TESRegionDataManager
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual bool Load(TESFile*, TESRegion*);
};
class TESRegionLoadHandler
{
  public:
};
class TESRegionLoadList
{
  public:
};
#endif
