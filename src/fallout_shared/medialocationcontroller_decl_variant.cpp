
// src/fallout_shared/medialocationcontroller_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00595310: the skeleton of src/fallout_shared/medialocationcontroller.cpp
// with declarations corrected to what the original code does (medialocationcontroller_update_decls.h: class MediaLocationController : public TESForm, pu -> class MediaLocationController : public TESForm, pu). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_00595cb0_shell.h"
#include "fnv/decl/FUN_00595cf0_shell.h"
#include "fnv/decl/FUN_00595d10_shell.h"
#include "fnv/decl/FUN_005fd3b0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PlayerNearbyRefs.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/ThisT.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00568cb0__FUN_00568cb0_shell.h"
#include "fnv/decl/fnv_008b8e90__FUN_008b8e90_shell.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "medialocationcontroller_update_decls_decl_medialocationcontroller.h"
#include "medialocationcontroller.h"
#include "mediaset.h"
class TESDataHandler
{
  public:
};

// @fnv 0x00595310
MediaLocationController::MediaLocationController()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x70))));
    iFlags = 4;
    m_fLowerWeightThreshold = 0.33f;
    m_fUpperWeightThreshold = 0.66f;
    m_fUpdateInterval = 0.0f;
    m_uiShortDelay = 64;
    m_uiLongDelay = 336;
    reinterpret_cast<::FileMatchList *>(&(m_kMediaSetList1))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(m_kMediaSetList2))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(m_kMediaSetList3))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(m_kMediaSetList4))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(m_kMediaSetList5))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(m_kMediaSetList6))->RemoveAll();
    pFaction = 0;
    m_eRequiredFightReaction = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
    m_pReference = 0;
    m_fUpdateCooldown = 0;
    m_uiFirstCounter = 0;
    m_uiSecondCounter = 0;
    m_uiThirdCounter = 0;
    m_bCountWasNonzero = false;
    m_bActorStateFlag = false;
    m_bConditionWasTrue = false;
    m_bConditionActive = false;
    m_cMediaState = 0;
    m_pMediaSet = 0;
    m_uiPerceivedActorCount = 0;
    m_uiPreviousPerceivedActorCount = 0;
    m_eCurrentFightReaction = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
}
