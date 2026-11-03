
//
// The covered PC function at 0x00568e50 is a two-call accessor:
//
//     return GetExtraData()->GetExtraRadioData();
//
// non-virtual TESObjectREFR::GetExtraData() getter returns its address.
// The linker folds that getter with every other identical
// "return &this->member" getter, which is why the BSFile vtable slot 6
// resolves to the same address.  ExtraDataList::GetExtraRadioData() looks the
// radio extra up by its type index and hands back its data pointer.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00418460_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/symbols_00450000.h"
#include "layout_support.h"

class ExtraRadioData;

class ExtraDataList
{
  public:
      // 0x00418460
};

class TESObjectREFR
{
  public:
            // 0x005d43c0
    ExtraRadioData* GetExtraRadioData();  // 0x00568e50
};

// @fnv 0x00568e50
ExtraRadioData* TESObjectREFR::GetExtraRadioData()
{
    return ((::ExtraRadioData *)(reinterpret_cast<::FUN_00418460_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00418460()));
}
