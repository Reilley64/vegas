// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/fallout shared/magic/magicitemobject.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00402990  MagicItemForm::SetAltered        (26 bytes)
#ifndef FNV_MAGICITEMOBJECT_H
#define FNV_MAGICITEMOBJECT_H

#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "layout_support.h"

class TESForm
{
  public:
};

class MagicItemForm : public TESForm
{
  public:
    void SetAltered(bool bAltered);
};

// @fnv 0x00402990
void MagicItemForm::SetAltered(bool bAltered)
{
    reinterpret_cast<::fnv_00484730::FUN_00484730_shell *>(this)->FUN_00484730(bAltered);
}

#endif
