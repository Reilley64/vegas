// src/fallout_shared/tesbipedmodelform_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesbipedmodelform.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0043f010.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00480570_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008bbc40_shell.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011c3000.h"
#include "tesbipedmodelform_decls.h"
#include "TESForm.h"
#include "tesbipedmodelform_types_TESBipedModelForm.h"
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
#include "tesbipedmodelform_types_SEX.h"
#include "tesbipedmodelform_types_BGSBipedModelList.h"

class FUN_00480400
{
  public:
    virtual ~FUN_00480400();

    BipedModelForm m_kBipedModelForm;
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap worldModel[2];
    TESIcon m_kIcon[2];
    BGSMessageIcon messageIcon[2];
    TESModelRDT m_kFaceGenModel;
};

// @fnv 0x00480400
FUN_00480400::~FUN_00480400()
{
    reinterpret_cast<::FUN_00480570_cls *>(this)->FreeModels();
}
