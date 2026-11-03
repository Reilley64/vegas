// src/fallout/interface/menus/messagemenu_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/interface/menus/messagemenu.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_00aa4c40_class.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00778000.h"
#include "fnv/symbols_007a9000.h"
#include "fnv/symbols_007aa000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "MessageMenu.h"
static const int kGetClassValue = 1001;

struct ArrSI
{
};
struct MessageQueueEntryView
{
    BSStringT<char> m_kMessageText;
    char* m_kTitle;
    BSStringT<char> m_kPrimaryButtonText;
    BSStringT<char> m_kTertiaryButtonText;
    char m_cButtonCount;
    BSStringT<char> m_kSecondaryButtonText;
    void(__cdecl* aCallback)();
    unsigned int m_uiMessageFlags;
};
struct MessageQueueComparisonArray
{
    MessageQueueEntryView** FUN_00877a30(int);
};
struct GlobalObject_00869f00
{
};
struct GlobalObject_007ab590;
class MessageHandler
{
  public:
    static MessageHandler* pHandler;
};
struct FUN_007aa500
{
    ~FUN_007aa500();
};

// @fnv 0x007aa5c0
void FUN_007aa5c0()
{
    if (::GetCurrentArrayElement())
    {
        unsigned int uiID = ((MessageQueueEntryView*)::GetCurrentArrayElement())->m_uiMessageFlags;
        reinterpret_cast<::FUN_00aa4c40_class *>((MessageHandler::pHandler))->FUN_00aa4c40(uiID);
        ::FUN_007aa6a0(true);
        for (unsigned int i = DAT_011da4f4; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&::g_011da53c)))->GetName())); i++)
        {
            if ((*((MessageQueueComparisonArray*)&::g_011da53c)->FUN_00877a30(i))->m_uiMessageFlags == uiID)
            {
                FUN_007aa500* pEntry = (FUN_007aa500*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&::g_011da53c)))->FUN_006a7ad0(i)));
                delete pEntry;
                reinterpret_cast<::FUN_006bf8f0_Class *>((((GlobalObject_00869f00*)&::g_011da53c)))->FUN_006bf8f0(i--, true);
            }
        }
    }
}

namespace fnv_007aae70 {
class ScriptLocals;
class TESBoundObject;
class Script
{
  public:
};
struct TESObjectREFR_acc
{
    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);
};
struct ArrSI
{
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct GlobalObject_007ab610;
struct PC7d;

struct PerkActivationEntry
{
    unsigned int uiButton;
    Script* pScript;
    TESObjectREFR* pRef;
};

// @fnv 0x007aae70
void FUN_007aae70()
{
    unsigned int ibuttonClicked;
    int icount;
    ibuttonClicked = ::ConsumeByteAtE4();
    if (ibuttonClicked != ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->GetName())) - 1)
    {
        reinterpret_cast<::FUN_005ac1e0_shell *>((((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))
            ->pScript))->FUN_005ac1e0(
                ((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))->pRef,
                (::ScriptLocals *)(::fnv_007aae70::ScriptLocals *)(0), 0, false);
    }
    else
    {
        icount = ::GetExtraDataShort(
            ((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))->pRef);
        ((TESObjectREFR_acc*)((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))
             ->pRef)
            ->Activate((TESObjectREFR*)(*reinterpret_cast<::fnv_007aae70::PC7d * *>(&::_g_thePlayer)), false, 0, icount);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->Clear(true);
}
}  // namespace fnv_007aae70
