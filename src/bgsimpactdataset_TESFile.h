// bgsimpactdataset_TESFile.h: declares TESFile
#ifndef FNV_LOCAL_TESFILE_H
#define FNV_LOCAL_TESFILE_H
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "layout_support.h"
class TESFile
{
  public:
    ENUM_FORM_ID GetTESForm();
    bool NextChunk();
public:
    bool IsEndianConversionRequired();
};
#endif
